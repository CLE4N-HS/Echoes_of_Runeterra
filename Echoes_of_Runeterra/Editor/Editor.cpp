#include "Editor.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "TileTextureManager.h"
#include "Window.h"

Editor::Editor() : m_AutoTileDatabase(), m_Map(), m_MapEdit(&m_Map.getMap())
{
	TileTextureManager::AddTexture("tileset", TILE_TEXTURE_PATH "tileset.png");
	TileTextureManager::AddTexture("tile", TILE_TEXTURE_PATH "tile.png");
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
	if (ig::Begin("Editor", igUselessBool, ImGuiWindowFlags_HorizontalScrollbar))
	{
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

		if (ig::TreeNode("Map"))
		{
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

			if (m_CurrentRect.width != 0)
			{
				if (ig::Button("CLEAN"))
				{
					m_CurrentRect.width = 0;
				}
				ig::SameLine();
				ig::Text("-> Remove the current Tile from your cursor");
			}

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
