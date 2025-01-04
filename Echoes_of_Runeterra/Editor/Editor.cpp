#include "Editor.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "TileTextureManager.h"
#include "Window.h"
#include "RenderStatesManager.h"
#include "ObjectTextureManager.h"
#include "MouseManager.h"
#include "TorchObject.h"
#include "AnimTile.h"
#include "ParticleManager.h"

#include <Windows.h>
#include <commdlg.h>

std::string wcharToString(const wchar_t* wcharStr) {
	if (!wcharStr) return "";

	// Get the required buffer size
	int bufferSize = WideCharToMultiByte(CP_UTF8, 0, wcharStr, -1, nullptr, 0, nullptr, nullptr);
	if (bufferSize == 0) {
		return ""; // Conversion failed
	}

	// Allocate a buffer for the converted string
	std::string str(bufferSize - 1, '\0'); // Exclude the null terminator
	WideCharToMultiByte(CP_UTF8, 0, wcharStr, -1, &str[0], bufferSize, nullptr, nullptr);

	return str;
}


Editor::Editor() : m_AutoTileDatabase(), m_Map(), m_MapEdit(&m_Map.getMap(), &m_Map.getObject()), m_DayNightSystem()
{
	TileTextureManager::AddTexture("tileset", TILE_TEXTURE_PATH "tileset.png");
	TileTextureManager::AddTexture("tile", TILE_TEXTURE_PATH "tile.png");
	TileTextureManager::AddTexture("animTile", TILE_TEXTURE_PATH "animTile.png");
	TileTextureManager::AddTexture("water", TILE_TEXTURE_PATH "water.png");
	TileTextureManager::AddTexture("collision", TILE_TEXTURE_PATH "collision.png");

	ObjectTextureManager::AddTexture("chest", OBJECT_TEXTURE_PATH "chest.png");
	ObjectTextureManager::AddTexture("torch", OBJECT_TEXTURE_PATH "torch.png");

	RenderStatesManager::AddShader("torch", SHADER_PATH "torch.frag", sf::Shader::Type::Fragment);
	RenderStatesManager::AddShader("dayNight", SHADER_PATH "dayNight.frag", sf::Shader::Type::Fragment);

	m_Layer.fill(true);
	m_CurrentLayer = m_MapEdit.GetLayer();
}

Editor::~Editor()
{
}

void Editor::Update()
{
	if (!(this->UpdateImGui()))
	{
		//TEST TODO
		if (MouseManager::HasJustPressed(sf::Mouse::Right) && 0)
		{
			sf::Vector2f mousePos = Window::GetMouseViewPos();
			m_MapEdit.EditObject(mousePos, "torch", sf::Vector2f(32.f, 32.f), Texture::TORCH);
		}

		sf::Texture* currentTexture = nullptr;
		switch (m_CurrentTextureId)
		{
		case Editor::TILE:
			currentTexture = TileTextureManager::GetTexture(m_CurrentTextureName); break;
		case Editor::OBJECT:
			currentTexture = ObjectTextureManager::GetTexture(m_CurrentTextureName); break;
		default:
			break;
		}
		sf::Vector2f mousePos = Window::GetMouseViewPos();
		if (currentTexture && m_CurrentRect.width != 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (m_CurrentTextureId)
			{
			case Editor::TILE:
			{
				switch (m_CurrentTexture)
				{
				case Editor::SIMPLE_TILE:
					m_MapEdit.EditTile(mousePos, m_CurrentTextureName, m_CurrentRect, m_CurrentTileType); break;
				case Editor::ANIM_TILE:
				{
					if (m_MapEdit.EditAnimTile(mousePos, m_CurrentTextureName, m_CurrentRect, m_CurrentTileType, m_CurrentAnimTileFrameX, m_CurrentAnimTileAnimSpeed))
					{
						this->ResetAnimTime();
					}
				}
				break;
				default:
					break;
				}
			}
			break;
			case Editor::OBJECT:
			{
				if (MouseManager::HasJustPressed(sf::Mouse::Left))
				{
					m_MapEdit.EditObject(mousePos, m_CurrentTextureName, sf::Vector2f(m_CurrentRect.getSize()), m_CurrentTexture);
				}
			}
			break;
			default:
				break;
			}
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			if (m_CurrentLayer == Map::Layer::OBJECT)
			{
				m_MapEdit.EraseObject(mousePos);
			}
			else
			{
				m_MapEdit.EraseTile(mousePos);
			}
		}
	}

	float dt = Tools::GetDeltaTime();

	float viewSpeed = 200.f * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		Window::view.move(sf::Vector2f(0.f, -viewSpeed));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		Window::view.move(sf::Vector2f(-viewSpeed, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Window::view.move(sf::Vector2f(0.f, viewSpeed));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Window::view.move(sf::Vector2f(viewSpeed, 0.f));
	}

	float viewZoomSpeed = dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Window::view.zoom(1.f + viewZoomSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		Window::view.zoom(1.f - viewZoomSpeed);
	}

	m_DayNightSystem.Update();
	ParticleManager::Update();
}

bool Editor::UpdateImGui()
{
	namespace ig = ImGui;

	bool isMouseOnWindow(false);

	bool* igUselessBool = nullptr;
	// EDITOR
	if (ig::Begin("Editor", igUselessBool, ImGuiWindowFlags_HorizontalScrollbar))
	{
		// EDITOR / INFO
		if (ig::TreeNode("Info"))
		{
			// EDITOR / INFO / VIEW
			if (ig::TreeNode("View##EDITOR_INFO_VIEW"))
			{
				ig::Text("Z/Q/S/D : Move");
				ig::Text("A/E     : Zoom");

				ig::TreePop();
			}

			// EDITOR / INFO / TEXTURE
			if (ig::TreeNode("Texture##EDITOR_INFO_TEXTURE"))
			{
				ig::Text("Left Click  : Place a Texture (if one has been selected)");
				ig::Text("Right Click : Erase a Texture (on the Current Layer)");
				ig::Text("// Clicks have no effects on the map if you are on this ImGui Window");

				ig::Separator();

				ig::Text("// A Tile can't be placed in Layer 2 (OBJECT)");
				ig::Text("// An Object have to be placed in Layer 2 (OBJECT)");
				//ig::Text("// An Object will automatically be placed in Layer 2 (OBJECT)");

				ig::TreePop();
			}

			ig::TreePop();
		}

		// EDITOR / MAP
		if (ig::TreeNode("Map"))
		{
			// EDITOR / MAP / SIZE
			if (ig::TreeNode("Size"))
			{
				sf::Vector2i mapSize = m_MapEdit.GetSize<int>();
				sf::Vector2i saveMapSize(mapSize);

				ig::Text(std::string("X (" + std::to_string(mapSize.x) + ") : ").c_str());
				ig::SameLine(120.f);
				if (ig::Button(" - ##SIZEX-"))
				{
					mapSize.x -= 1;
				}
				ig::SameLine(160.f);
				if (ig::Button(" + ##SIZEX+"))
				{
					mapSize.x += 1;
				}
				ig::SameLine(240.f);
				ig::PushItemWidth(300.f);
				ig::SliderInt("##SIZEXSLIDER", &mapSize.x, MapEdit::MIN_SIZE, MapEdit::MAX_SIZE);

				ig::Text(std::string("Y (" + std::to_string(mapSize.y) + ") : ").c_str());
				ig::SameLine(120.f);
				if (ig::Button(" - ##SIZEY-"))
				{
					mapSize.y -= 1;
				}
				ig::SameLine(160.f);
				if (ig::Button(" + ##SIZEY+"))
				{
					mapSize.y += 1;
				}
				ig::SameLine(240.f);
				ig::PushItemWidth(300.f);
				ig::SliderInt("##SIZEYSLIDER", &mapSize.y, MapEdit::MIN_SIZE, MapEdit::MAX_SIZE);

				mapSize.x = std::max(MapEdit::MIN_SIZE, mapSize.x);
				mapSize.y = std::max(MapEdit::MIN_SIZE, mapSize.y);
				mapSize.x = std::min(MapEdit::MAX_SIZE, mapSize.x);
				mapSize.y = std::min(MapEdit::MAX_SIZE, mapSize.y);
				if (mapSize != saveMapSize)
				{
					m_MapEdit.Resize(sf::Vector2<size_t>(mapSize));
				}

				ig::TreePop();
			}

			// EDITOR / MAP / DISPLAY
			if (ig::TreeNode("Display##EDITOR_MAP_DISPLAY"))
			{
				// EDITOR / MAP / DISPLAY / GRID
				if (ig::TreeNode("Grid##EDITOR_MAP_DISPLAY_GRID"))
				{
					ig::Checkbox("Display##EDITOR_MAP_DISPLAY_GRID_DISPLAY", &m_Grid);

					// EDITOR / MAP / DISPLAY / GRID / SETTINGS
					if (ig::TreeNode("Settings##EDITOR_MAP_DISPLAY_GRID_SETTINGS"))
					{
						ig::SliderFloat("Size##EDITOR_MAP_DISPLAY_GRID_SETTINGS_SIZE", &m_GridSize, 0.f, static_cast<float>(Tile::SIZE / 2), "%.1f");

						ig::Separator();

						float color[4]{ static_cast<float>(m_GridColor.r) / 255.f, static_cast<float>(m_GridColor.g) / 255.f, static_cast<float>(m_GridColor.b) / 255.f , static_cast<float>(m_GridColor.a) / 255.f };
						ig::ColorEdit4("Color##EDITOR_MAP_DISPLAY_GRID_SETTINGS_COLOR", color);
						m_GridColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
						m_GridColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
						m_GridColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
						m_GridColor.a = static_cast<sf::Uint8>(color[3] * 255.f);

						ig::TreePop();
					}

					ig::TreePop();
				}

				// EDITOR / MAP / DISPLAY / BORDER
				if (ig::TreeNode("Border##EDITOR_MAP_DISPLAY_BORDER"))
				{
					ig::Checkbox("Display##EDITOR_MAP_DISPLAY_BORDER_DISPLAY", &m_Border);

					// EDITOR / MAP / DISPLAY / BORDER / SETTINGS
					if (ig::TreeNode("Settings##EDITOR_MAP_DISPLAY_BORDER_SETTINGS"))
					{
						ig::SliderFloat("Size##EDITOR_MAP_DISPLAY_BORDER_SETTINGS_SIZE", &m_BorderSize, 0.f, static_cast<float>(Tile::SIZE / 2), "%.1f");

						ig::Separator();

						float color[4]{ static_cast<float>(m_BorderColor.r) / 255.f, static_cast<float>(m_BorderColor.g) / 255.f, static_cast<float>(m_BorderColor.b) / 255.f , static_cast<float>(m_BorderColor.a) / 255.f };
						ig::ColorEdit4("Color##EDITOR_MAP_DISPLAY_BORDER_SETTINGS_COLOR", color);
						m_BorderColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
						m_BorderColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
						m_BorderColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
						m_BorderColor.a = static_cast<sf::Uint8>(color[3] * 255.f);

						ig::TreePop();
					}

					ig::TreePop();
				}

				ig::TreePop();
			}

			// EDITOR / MAP / LAYER
			if (ig::TreeNode("Layer"))
			{
				Map::Layer saveCurrentLayer = m_CurrentLayer;
				int iCurrentLayer = static_cast<int>(m_CurrentLayer);
				ig::PushItemWidth(200.f);
				std::string tmpLayerName;
				switch (m_CurrentLayer)
				{
				case Map::BACKGROUND: tmpLayerName = "BACKGROUND"; break;
				case Map::COLLISION: tmpLayerName = "COLLISION"; break;
				case Map::OBJECT: tmpLayerName = "OBJECT"; break;
				case Map::FOREGROUND: tmpLayerName = "FOREGROUND"; break;
				default:
					break;
				}
				ig::SliderInt("Current Layer :##EDITOR_MAP_LAYER_CURRENT_LAYER_NAME_TMP", &iCurrentLayer, 0, static_cast<int>(Map::Layer::COUNT - 1));

				ig::SameLine();
				ig::Text(tmpLayerName.c_str());


				m_CurrentLayer = static_cast<Map::Layer>(iCurrentLayer);

				if (m_CurrentLayer != saveCurrentLayer)
				{
					m_MapEdit.SetLayer(m_CurrentLayer);

					bool isInNONEMode(true);
					for (size_t l = 0; l < m_Layer.size(); l++)
					{
						if (m_Layer[l] && l != saveCurrentLayer)
						{
							isInNONEMode = false;
							break;
						}
					}

					if (isInNONEMode)
					{
						m_Layer.fill(false);
						m_Layer[m_CurrentLayer] = true;
					}
				}

				// EDITOR / MAP / LAYER / DISPLAY
				if (ig::TreeNode("Display##EDITOR_MAP_LAYER_DISPLAY"))
				{
					if (ig::Button("ALL##EDITOR_MAP_LAYER_ALL"))
					{
						m_Layer.fill(true);
					}
					if (ig::Button(std::string("NONE (only [" + std::to_string(m_CurrentLayer) + "])##EDITOR_MAP_LAYER_NONE").c_str()))
					{
						m_Layer.fill(false);
						m_Layer[m_CurrentLayer] = true;
					}

					ig::Separator();

					ig::Checkbox("Layer : 0 (BACKGROUND)##EDITOR_MAP_LAYER_0", &m_Layer[0]);
					ig::Checkbox("Layer : 1 (COLLISION -> not displayed in game) ##EDITOR_MAP_LAYER_1", &m_Layer[1]);
					ig::Checkbox("Layer : 2 (OBJECT)##EDITOR_MAP_LAYER_2", &m_Layer[2]);
					ig::Checkbox("Layer : 3 (FOREGROUND)##EDITOR_MAP_LAYER_3", &m_Layer[3]);

					//size_t nbLayer = m_Layer.size();
					//for (size_t l = 0; l < nbLayer; l++)
					//{
					//	ig::Checkbox(std::string("Layer : " + std::to_string(l) + "##EDITOR_MAP_LAYER_NBLAYER").c_str(), &m_Layer[l]);
					//}
					ig::TreePop();
				}

				ig::TreePop();
			}

			// EDITOR / MAP / TEXTURE
			if (ig::TreeNode("Texture##EDITOR_MAP_TEXTURE"))
			{
				if (m_CurrentRect.width != 0)
				{
					if (ig::Button("CLEAN"))
					{
						m_CurrentRect.width = 0;
					}
					ig::SameLine();
					ig::Text("-> Remove the current Texture from your cursor");
				}

				// EDITOR / MAP / TEXTURE / TILE
				if (ig::TreeNode("Tile##EDITOR_MAP_TILE"))
				{
					// EDITOR / MAP / TEXTURE / TILE / TILESET
					if (ig::TreeNode("Tileset##EDITOR_MAP_TILE_TILESET"))
					{
						std::map<std::string_view, sf::Texture*> texture = TileTextureManager::Get();

						for (std::map<std::string_view, sf::Texture*>::iterator it = texture.begin(); it != texture.end(); it++)
						{
							if ((*it).first.data() == "water")
								continue;

							if (ig::Button((*it).first.data()))
							{
								m_CurrentTextureName = (*it).first;
								m_CurrentTextureId = TextureId::TILE;

								if (m_CurrentTextureName == "animTile")
									m_CurrentTexture = Texture::ANIM_TILE;
								else
									m_CurrentTexture = Texture::SIMPLE_TILE;

								m_CurrentRect.width = 0;
							}
						}

						ig::NewLine();

						ig::TreePop();
					}

					if (sf::Texture* currentTexture = TileTextureManager::GetTexture(m_CurrentTextureName))
					{
						if (m_CurrentLayer == Map::Layer::OBJECT)
						{
							ig::Separator();
							ig::Text("// A Tile can't be placed in this Current Layer");
							ig::Separator();
							ig::NewLine();
						}

						static int igTileSize = 16;
						ig::PushItemWidth(400.f);
						ig::SliderInt("Size##SIZECURRENTTEXTURE", &igTileSize, 0, 64);

						if (igTileSize > 0)
						{
							if (m_CurrentTexture == Texture::ANIM_TILE)
							{
								ig::Separator();

								ig::SliderInt("FrameX##EDITOR_MAP_TEXTURE_TILE_FRAMEX", &m_CurrentAnimTileFrameX, 1, 10);
								ig::SliderFloat("AnimSpeed##EDITOR_MAP_TEXTURE_TILE_ANIMSPEED", &m_CurrentAnimTileAnimSpeed, 0.0f, 1.f, "%.2f");
							}

							ig::Separator();

							int sizeX = static_cast<int>(currentTexture->getSize().x) / Tile::SIZE;
							int sizeY = static_cast<int>(currentTexture->getSize().y) / Tile::SIZE;

							sf::Sprite spr(*currentTexture);

							ig::NewLine();
							for (int y = 0; y < sizeY; y++)
							{
								for (int x = 0; x < sizeX; x++)
								{
									ig::SameLine(0.f, 4.f);
									spr.setTextureRect(sf::IntRect(x * Tile::SIZE, y * Tile::SIZE, Tile::SIZE, Tile::SIZE));
									if (ig::ImageButton(std::to_string(y * 100 + x).c_str(), spr, sf::Vector2f(sf::Vector2i(igTileSize, igTileSize))))
									{
										m_CurrentRect = sf::IntRect(x * Tile::SIZE, y * Tile::SIZE, Tile::SIZE, Tile::SIZE);

										if (m_CurrentTexture == Texture::ANIM_TILE)
										{
											m_CurrentTileType = Tile::Type::WATER;
										}
										else
										{
											m_CurrentTileType = Tile::Type::NO_TYPE;
										}
									}
								}
								ig::NewLine();
							}
						}
					}

					ig::TreePop();
				}

				// EDITOR / MAP / TEXTURE / OBJECT
				if (ig::TreeNode("Object##EDITOR_MAP_OBJECT"))
				{
					// EDITOR / MAP / TEXTURE / OBJECT / TILESET
					if (ig::TreeNode("Tileset##EDITOR_MAP_OBJECT_TILESET"))
					{
						std::map<std::string_view, sf::Texture*> texture = ObjectTextureManager::Get();

						for (std::map<std::string_view, sf::Texture*>::iterator it = texture.begin(); it != texture.end(); it++)
						{
							if (ig::Button((*it).first.data()))
							{
								m_CurrentTextureName = (*it).first;
								m_CurrentTextureId = TextureId::OBJECT;

								if (m_CurrentTextureName == "chest")
									m_CurrentTexture = Texture::CHEST;
								else if (m_CurrentTextureName == "torch")
									m_CurrentTexture = Texture::TORCH;
								else
									m_CurrentTexture = Texture::NO;

								m_CurrentRect.width = 0;
							}
						}

						ig::NewLine();

						ig::TreePop();
					}

					if (sf::Texture* currentTexture = ObjectTextureManager::GetTexture(m_CurrentTextureName))
					{
						if (m_CurrentLayer != Map::Layer::OBJECT)
						{
							ig::Separator();
							ig::Text("// An Object can't be placed in this Current Layer");
							ig::Separator();
							ig::NewLine();
						}

						static int igTileSize = 16;
						ig::PushItemWidth(400.f);
						ig::SliderInt("Size##SIZECURRENTTEXTURE_OBJECT", &igTileSize, 0, 64);

						if (igTileSize > 0)
						{
							ig::Separator();

							int sizeX = static_cast<int>(currentTexture->getSize().x) / Tile::SIZE;
							int sizeY = static_cast<int>(currentTexture->getSize().y) / Tile::SIZE;

							sf::Sprite spr(*currentTexture);

							ig::NewLine();
							for (int y = 0; y < sizeY; y++)
							{
								for (int x = 0; x < sizeX; x++)
								{
									ig::SameLine(0.f, 4.f);
									spr.setTextureRect(sf::IntRect(x * Tile::SIZE, y * Tile::SIZE, Tile::SIZE, Tile::SIZE));
									if (ig::ImageButton(std::string(std::to_string(y * 100 + x) + "##EDITOR_MAP_OBJECT").c_str(), spr, sf::Vector2f(sf::Vector2i(igTileSize, igTileSize))))
									{
										m_CurrentRect = sf::IntRect(x * Tile::SIZE, y * Tile::SIZE, Tile::SIZE, Tile::SIZE);
									}
								}
								ig::NewLine();
							}
						}
					}
					ig::TreePop();
				}

				ig::TreePop();
			}

			// Hugo Miceli (c) for the library usage
			if (1)
			{
				// EDITOR / MAP / SAVES
				if (ig::TreeNode("Saves##EDITOR_MAP_SAVES"))
				{
					if (ImGui::Button("Save##EDITOR_MAP_SAVES_SAVE"))
					{
						OPENFILENAME ofn;                        // Structure pour configurer la boîte de dialogue
						wchar_t fileName[MAX_PATH] = L"";        // Stocke le chemin du fichier sélectionné
						wchar_t initialDir[MAX_PATH] = L"..\\Resources\\Saves\\Map"; // Répertoire initial
						ZeroMemory(&ofn, sizeof(ofn));

						ofn.lStructSize = sizeof(ofn);
						//ofn.hwndOwner = Window::getNativeHandle();                 // Met la window en fenêtre prioritaire
						ofn.lpstrFilter = L"Fichiers JSON (*.json)\0*.json\0Tous les fichiers (*.*)\0*.*\0";
						ofn.lpstrFile = fileName;
						ofn.nMaxFile = MAX_PATH;
						ofn.lpstrInitialDir = initialDir;        // Répertoire de départ
						ofn.Flags = OFN_OVERWRITEPROMPT;         // Demander confirmation avant d'écraser
						ofn.lpstrDefExt = L"json";                // Extension par défaut

						if (GetSaveFileName(&ofn))               // Afficher la boîte de dialogue
						{
							std::ofstream mapStream(fileName);
							m_Map.Save(mapStream);           // Sauvegarder la map dans le chemin sélectionné
							m_GameMapPath = wcharToString(fileName);
						}
					}

					if (ImGui::Button("Load##EDITOR_MAP_SAVES_LOAD"))
					{
						OPENFILENAME ofn;                        // Structure pour configurer la boîte de dialogue
						wchar_t fileName[MAX_PATH] = L"";        // Stocke le chemin du fichier sélectionné
						wchar_t initialDir[MAX_PATH] = L"..\\Resources\\Saves\\Map"; // Répertoire initial
						ZeroMemory(&ofn, sizeof(ofn));

						ofn.lStructSize = sizeof(ofn);
						//ofn.hwndOwner = Window::getNativeHandle();                 // Met la window en fenêtre prioritaire
						ofn.lpstrFilter = L"Fichiers JSON (*.json)\0*.json\0Tous les fichiers (*.*)\0*.*\0";
						ofn.lpstrFile = fileName;
						ofn.nMaxFile = MAX_PATH;
						ofn.lpstrInitialDir = initialDir;        // Répertoire de départ
						ofn.Flags = OFN_FILEMUSTEXIST;           // Assurez-vous que le fichier existe avant d'ouvrir

						if (GetOpenFileName(&ofn))               // Afficher la boîte de dialogue pour OUVRIR un fichier
						{
							std::ifstream mapStream(fileName);   // Ouvrir le fichier sélectionné en lecture
							if (mapStream.is_open())
							{
								m_Map.Load(mapStream);            // Charger la map à partir du fichier
								mapStream.close();
								m_GameMapPath = wcharToString(fileName);
							}
							else
							{
								MessageBox(nullptr, L"Impossible d'ouvrir le fichier sélectionné.", L"Erreur", MB_OK | MB_ICONERROR);
							}
						}
					}

					if (ImGui::Button("New##EDITOR_MAP_SAVES_NEW"))
					{
						m_Map.DeinitMap();
						m_Map.DefaultMap();
					}

					ig::TreePop();
				}
			}

			ig::TreePop();
		}

		// EDITOR / DAY NIGHT SYSTEM
		if (ig::TreeNode("Day-Night System##EDITOR_DAY_NIGHT_SYSTEM"))
		{
			ig::PushItemWidth(300.f);
			ig::SliderInt("Hour##EDITOR_DAY_NIGHT_SYSTEM_HOUR", &m_DayNightSystem.GetHour(), 0, 23);

			ig::SliderInt("Minute##EDITOR_DAY_NIGHT_SYSTEM_MINUTE", &m_DayNightSystem.GetMinute(), 0, 59);

			ig::DragInt("Coefficient##EDITOR_DAY_NIGHT_SYSTEM_COEFFICIENT", &m_DayNightSystem.GetCoefficient(), 60.f);

			ig::TreePop();
		}

		// EDITOR / GAME
		if (ig::TreeNode("GAME##EDITOR_GAME"))
		{
			ig::Text("// Save or Load the Map you want to test");

			ig::Separator();

			if (m_GameMapPath != "")
			{
				std::string pathName = m_GameMapPath;

				size_t iPathName = 0;

				size_t nbErase = 0;
				while (iPathName <= pathName.size())
				{
					if (pathName[iPathName] == '\\')
						nbErase = iPathName + 1;

					iPathName++;
				}

				for (size_t i = 0; i < nbErase; i++)
				{
					pathName.erase(pathName.begin());
				}

				if (pathName.size() > 4)
				{
					pathName.erase(pathName.size() - 1);
					pathName.erase(pathName.size() - 1);
					pathName.erase(pathName.size() - 1);
					pathName.erase(pathName.size() - 1);
					pathName.erase(pathName.size() - 1);
				}

				ig::Text(std::string("Map : " + pathName).c_str());

				if (ig::Button("Start##EDITOR_GAME_START"))
				{
					Window::Exit();
					std::system("../Debug/Echoes_of_Runetera.exe");
				}
			}


			ig::TreePop();
		}

		//ig::Image(m_MapTexture, sf::Vector2f(m_MapTexture.getSize()));

		float windowOffset = 20.f;
		if (sf::FloatRect(ig::GetWindowPos().x - windowOffset, ig::GetWindowPos().y - windowOffset, ig::GetWindowSize().x + windowOffset * 2.f, ig::GetWindowSize().y + windowOffset * 2.f).contains(Window::GetMousePos()))
		{
			isMouseOnWindow = true;
		}
	}
	ig::End();

	return isMouseOnWindow;
}

void Editor::Display()
{
	Window::SetView();

	m_Map.Display();

	std::vector<std::vector<std::vector<Tile*>>> map = m_Map.getMap();
	std::vector<Object*> object= m_Map.getObject();

	/*
	Window::rectangle.setOrigin(sf::Vector2f());
	Window::rectangle.setSize(sf::Vector2f(sf::Vector2<int>(Tile::SIZE, Tile::SIZE)));
	//test
	Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
	float tmpDt = Tools::GetDeltaTime();
	for (size_t l = 0; l < map.size(); l++)
	{
		if (m_Layer[l])
		{
			for (size_t y = 0; y < map[l].size(); y++)
			{
				for (size_t x = 0; x < map[l][y].size(); x++)
				{
					if (sf::Texture* tex = TileTextureManager::GetTexture(map[l][y][x]->GetTextureName()))
					{
						if (AnimTile* animTile = dynamic_cast<AnimTile*>(map[l][y][x]))
						{
							animTile->Anim(tmpDt);
						}

						Window::rectangle.setTexture(tex);
						Window::rectangle.setTextureRect(map[l][y][x]->GetRect());
						Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * Tile::SIZE, y * Tile::SIZE)));
					
						Window::Draw();
					}
				}
			}
		}
	}
	*/

	if (m_Layer[Map::Layer::BACKGROUND])
	{
		this->DisplayLayer(Map::Layer::BACKGROUND);
	}
	if (m_Layer[Map::Layer::COLLISION])
	{
		this->DisplayLayer(Map::Layer::COLLISION);
	}
	if (m_Layer[Map::Layer::OBJECT])
	{
		Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
		Window::rectangle.setOrigin(sf::Vector2f());
		for (size_t i = 0; i < object.size(); i++)
		{
			object[i]->Display();
		}

		Window::rectangle.setTexture(nullptr);
		Window::rectangle.setFillColor(sf::Color(0, 0, 0, 0));
		for (Object* o : object)
		{
			if (TorchObject* t = dynamic_cast<TorchObject*>(o))
			{
				t->DisplayShader(m_DayNightSystem);
				t->DisplayParticles(m_DayNightSystem);
			}
		}
		ParticleManager::Display();
	}
	if (m_Layer[Map::Layer::FOREGROUND])
	{
		this->DisplayLayer(Map::Layer::FOREGROUND - 1);
	}

	Window::rectangle.setTexture(nullptr);

	if (m_Grid)
	{
		Window::rectangle.setFillColor(m_GridColor);

		Window::rectangle.setSize(sf::Vector2f(static_cast<float>(map[0][0].size() * Tile::SIZE), m_GridSize));
		Window::rectangle.setOrigin(sf::Vector2f(0.f, Window::rectangle.getSize().y * 0.5f));
		for (size_t y = 1; y < map[0].size(); y++)
		{
			Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(0, y * Tile::SIZE)));

			Window::Draw();
		}
		Window::rectangle.setSize(sf::Vector2f(m_GridSize, static_cast<float>(map[0].size() * Tile::SIZE)));
		Window::rectangle.setOrigin(sf::Vector2f(Window::rectangle.getSize().x * 0.5f, 0.f));
		for (size_t x = 1; x < map[0][0].size(); x++)
		{
			Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * Tile::SIZE, 0)));

			Window::Draw();
		}
	}
	if (m_Border)
	{
		Window::rectangle.setTexture(nullptr);
		Window::rectangle.setFillColor(sf::Color(0, 0, 0, 0));
		Window::rectangle.setSize(sf::Vector2f(static_cast<float>(map[0][0].size() * Tile::SIZE), static_cast<float>(map[0].size() * Tile::SIZE)));
		Window::rectangle.setPosition(sf::Vector2f());
		Window::rectangle.setOrigin(sf::Vector2f());
		Window::rectangle.setOutlineThickness(m_BorderSize);
		Window::rectangle.setOutlineColor(m_BorderColor);
		Window::Draw();

		Window::rectangle.setOutlineThickness(0.f);
		Window::rectangle.setOutlineColor(sf::Color(0, 0, 0, 0));
	}

	m_DayNightSystem.Display();

	sf::Texture* currentTexture = nullptr;
	switch (m_CurrentTextureId)
	{
	case Editor::TILE:
		currentTexture = TileTextureManager::GetTexture(m_CurrentTextureName);
		break;
	case Editor::OBJECT:
		currentTexture = ObjectTextureManager::GetTexture(m_CurrentTextureName);
		break;
	default:
		break;
	}
	
	if (currentTexture && m_CurrentRect.width != 0)
	{
		Window::rectangle.setTexture(currentTexture);
		Window::rectangle.setTextureRect(m_CurrentRect);
		Window::rectangle.setPosition(Window::GetMouseViewPos());
		Window::rectangle.setSize(sf::Vector2f(sf::Vector2i(Tile::SIZE, Tile::SIZE)));
		Window::rectangle.setOrigin(sf::Vector2f());
		Window::rectangle.setFillColor(sf::Color(255, 255, 255));
		Window::Draw();

		//Window::rectangle.setTexture(nullptr);
	}

}

void Editor::ResetAnimTime()
{
	std::vector<std::vector<std::vector<Tile*>>> map = m_Map.getMap();

	for (size_t l = 0; l < map.size(); l++)
	{
		//if (m_Layer[l])
		{
			for (size_t y = 0; y < map[l].size(); y++)
			{
				for (size_t x = 0; x < map[l][y].size(); x++)
				{
					if (sf::Texture* tex = TileTextureManager::GetTexture(map[l][y][x]->GetTextureName()))
					{
						if (AnimTile* animTile = dynamic_cast<AnimTile*>(map[l][y][x]))
						{
							animTile->GetAnimTime() = 0.f;
							animTile->GetFrameX() = 0;
						}
					}
				}
			}
		}
	}
}

void Editor::DisplayLayer(size_t _layer)
{
	std::vector<std::vector<std::vector<Tile*>>> map = m_Map.getMap();

	Window::rectangle.setOrigin(sf::Vector2f());
	Window::rectangle.setSize(sf::Vector2f(sf::Vector2<int>(Tile::SIZE, Tile::SIZE)));
	//test
	Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
	float tmpDt = Tools::GetDeltaTime();

	size_t l = _layer;
	for (size_t y = 0; y < map[l].size(); y++)
	{
		for (size_t x = 0; x < map[l][y].size(); x++)
		{
			if (sf::Texture* tex = TileTextureManager::GetTexture(map[l][y][x]->GetTextureName()))
			{
				if (AnimTile* animTile = dynamic_cast<AnimTile*>(map[l][y][x]))
				{
					animTile->Anim(tmpDt);
				}

				Window::rectangle.setTexture(tex);
				Window::rectangle.setTextureRect(map[l][y][x]->GetRect());
				Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * Tile::SIZE, y * Tile::SIZE)));

				Window::Draw();
			}
		}
	}
}
