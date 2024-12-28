#include "Editor.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "TileTextureManager.h"
#include "Window.h"

Editor::Editor() : m_AutoTileDatabase(), m_Map(), m_MapEdit(&m_Map.getMap())
{
	TileTextureManager::AddTexture("tileset", TILE_TEXTURE_PATH "tileset.png");
	TileTextureManager::AddTexture("tile", TILE_TEXTURE_PATH "tile.png");

	m_Layer.fill(true);
}

Editor::~Editor()
{
}

void Editor::Update()
{
	if (!(this->UpdateImGui()))
	{
		if (TileTextureManager::GetTexture(m_CurrentTextureName) && m_CurrentRect.width != 0)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2f mousePos = Window::GetMouseViewPos();

				m_MapEdit.EditTile(mousePos, m_CurrentTextureName, m_CurrentRect);
			}
		}
	}

	float dt = Tools::GetDeltaTime();

	float viewSpeed = 500.f * dt;
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
					// TODO smth compare affiche
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

			if (m_CurrentRect.width != 0)
			{
				if (ig::Button("CLEAN"))
				{
					m_CurrentRect.width = 0;
				}
				ig::SameLine();
				ig::Text("-> Remove the current Tile from your cursor");
			}

			// EDITOR / MAP / TEXTURE
			if (ig::TreeNode("Texture"))
			{
				if (ig::TreeNode("Name##MAP_TEXTURE_NAME"))
				{
					std::map<std::string_view, sf::Texture*> texture = TileTextureManager::Get();

					for (std::map<std::string_view, sf::Texture*>::iterator it = texture.begin(); it != texture.end(); it++)
					{
						if (ig::Button((*it).first.data()))
						{
							m_CurrentTextureName = (*it).first;
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

	for (size_t l = 0; l < map.size(); l++)
	{
		if (m_Layer[l])
		{
			for (size_t y = 0; y < map[l].size(); y++)
			{
				for (size_t x = 0; x < map[l][y].size(); x++)
				{
					Window::rectangle.setTexture(TileTextureManager::GetTexture(map[l][y][x]->GetTextureName()));
					Window::rectangle.setTextureRect(map[l][y][x]->GetRect());
					Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * 32, y * 32)));
					Window::rectangle.setSize(sf::Vector2f(32.f, 32.f));

					//test
					Window::rectangle.setFillColor(sf::Color(255, 255, 255, 100));

					Window::Draw();
				}
			}
		}
	}

	if (sf::Texture* currentTexture = TileTextureManager::GetTexture(m_CurrentTextureName); m_CurrentRect.width != 0)
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
