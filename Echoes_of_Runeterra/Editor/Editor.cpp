#include "Editor.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "TileTextureManager.h"
#include "Window.h"
#include "RenderStatesManager.h"
#include "ObjectTextureManager.h"
#include "MouseManager.h"
#include "TorchObject.h"

#include <Windows.h>
#include <commdlg.h>

Editor::Editor() : m_AutoTileDatabase(), m_Map(), m_MapEdit(&m_Map.getMap(), &m_Map.getObject()), m_DayNightSystem()
{
	TileTextureManager::AddTexture("tileset", TILE_TEXTURE_PATH "tileset.png");
	TileTextureManager::AddTexture("tile", TILE_TEXTURE_PATH "tile.png");

	ObjectTextureManager::AddTexture("chest", OBJECT_TEXTURE_PATH "chest.png");
	ObjectTextureManager::AddTexture("torch", OBJECT_TEXTURE_PATH "torch.png");

	RenderStatesManager::AddShader("torch", SHADER_PATH "torch.frag", sf::Shader::Type::Fragment);

	m_Layer.fill(true);
	m_CurrentLayer = m_MapEdit.GetLayer();

	//RenderStatesManager::LoadShader(SHADER_PATH "test.frag", sf::Shader::Type::Fragment);
}

Editor::~Editor()
{
}

void Editor::Update()
{
	if (!(this->UpdateImGui()))
	{
		//TEST TODO
		if (MouseManager::HasJustPressed(sf::Mouse::Right))
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
		if (currentTexture && m_CurrentRect.width != 0)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2f mousePos = Window::GetMouseViewPos();

				switch (m_CurrentTextureId)
				{
				case Editor::TILE:
					m_MapEdit.EditTile(mousePos, m_CurrentTextureName, m_CurrentRect); break;
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
}

bool Editor::UpdateImGui()
{
	namespace ig = ImGui;

	bool isMouseOnWindow(false);

	bool* igUselessBool = nullptr;
	// EDITOR
	if (ig::Begin("Editor", igUselessBool, ImGuiWindowFlags_HorizontalScrollbar))
	{
		// EDITOR / KEYS
		if (ig::TreeNode("Keys"))
		{
			if (ig::TreeNode("View"))
			{
				ig::Text("Z/Q/S/D : Move");
				ig::Text("A/E     : Zoom");

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
				ig::SliderInt("Current Layer", &iCurrentLayer, 0, static_cast<int>(Map::Layer::COUNT - 1));

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

					size_t nbLayer = m_MapEdit.GetNbLayer();
					for (size_t l = 0; l < nbLayer; l++)
					{
						ig::Checkbox(std::string("Layer : " + std::to_string(l) + "##EDITOR_MAP_LAYER_NBLAYER").c_str(), &m_Layer[l]);
					}
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
					// EDITOR / MAP / TEXTURE / TILE / NAME
					if (ig::TreeNode("Name##EDITOR_MAP_TILE_NAME"))
					{
						std::map<std::string_view, sf::Texture*> texture = TileTextureManager::Get();

						for (std::map<std::string_view, sf::Texture*>::iterator it = texture.begin(); it != texture.end(); it++)
						{
							if (ig::Button((*it).first.data()))
							{
								m_CurrentTextureName = (*it).first;
								m_CurrentTextureId = TextureId::TILE;
								m_CurrentTexture = Texture::SIMPLE_TILE;

								m_CurrentRect.width = 0;
							}
						}

						ig::NewLine();

						ig::TreePop();
					}

					if (sf::Texture* currentTexture = TileTextureManager::GetTexture(m_CurrentTextureName))
					{
						static int igTileSize = 16;
						ig::PushItemWidth(400.f);
						ig::SliderInt("Size##SIZECURRENTTEXTURE", &igTileSize, 0, 64);

						if (igTileSize > 0)
						{
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
					// EDITOR / MAP / TEXTURE / OBJECT / NAME
					if (ig::TreeNode("Name##EDITOR_MAP_OBJECT_NAME"))
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
						static int igTileSize = 16;
						ig::PushItemWidth(400.f);
						ig::SliderInt("Size##SIZECURRENTTEXTURE_OBJECT", &igTileSize, 0, 64);

						if (igTileSize > 0)
						{
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
							}
							else
							{
								MessageBox(nullptr, L"Impossible d'ouvrir le fichier sélectionné.", L"Erreur", MB_OK | MB_ICONERROR);
							}
						}
					}

					if (ImGui::Button("New##EDITOR_MAP_SAVES_NEW"))
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
							m_Map.DeinitMap();
							m_Map.DefaultMap();
							m_Map.Save(mapStream);           // Sauvegarder la map dans le chemin sélectionné
						}
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

	Window::rectangle.setOrigin(sf::Vector2f());
	Window::rectangle.setSize(sf::Vector2f(sf::Vector2<int>(Tile::SIZE, Tile::SIZE)));
	//test
	Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
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
						Window::rectangle.setTexture(tex);
						Window::rectangle.setTextureRect(map[l][y][x]->GetRect());
						Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * Tile::SIZE, y * Tile::SIZE)));
					
						Window::Draw();
					}
				}
			}
		}
	}

	if (m_Layer[Map::Layer::COLLISION])
	{
		Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
		Window::rectangle.setOrigin(sf::Vector2f());
		for (size_t i = 0; i < object.size(); i++)
		{
			object[i]->Display();
		}
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
	Window::SetView();

	if (m_Layer[Map::Layer::COLLISION])
	{
		Window::rectangle.setTexture(nullptr);
		Window::rectangle.setFillColor(sf::Color(0, 0, 0, 0));
		for (Object* o : object)
		{
			if (TorchObject* t = dynamic_cast<TorchObject*>(o))
				t->DisplayShader(m_DayNightSystem);
		}
	}
	Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));


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
