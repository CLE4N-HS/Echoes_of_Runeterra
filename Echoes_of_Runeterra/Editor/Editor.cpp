#include "Editor.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "TextureManager.h"
#include "Window.h"

constexpr int TILE_SIZE = 32;

Editor::Editor() : m_AutoTileDatabase(), m_Map(), m_MapEdit(&m_Map.getMap())
{
	TextureManager::AddTexture("tileset", TEXTURE_PATH "Map/tileset.png");
	TextureManager::AddTexture("tile", TEXTURE_PATH "Map/tile.png");

}

Editor::~Editor()
{
}

void Editor::Update()
{
	namespace ig = ImGui;

	bool* igUselessBool = nullptr;
	if (ig::Begin("Editor", igUselessBool, ImGuiWindowFlags_HorizontalScrollbar))
	{
		if (ig::TreeNode("Map"))
		{
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
				std::map<std::string_view, sf::Texture*> texture = TextureManager::Get();

				for (std::map<std::string_view, sf::Texture*>::iterator it = texture.begin(); it != texture.end(); it++)
				{
					if (ig::Button((*it).first.data()))
					{
						m_CurrentTexture = (*it).second;
					}
				}

				ig::NewLine();

				ig::TreePop();
			}

			if (m_CurrentTexture)
			{
				static int igTileSize = 16;
				ig::PushItemWidth(400.f);
				ig::SliderInt("Size", &igTileSize, 0, 64);

				if (igTileSize > 0)
				{
					int sizeX = static_cast<int>(m_CurrentTexture->getSize().x) / TILE_SIZE;
					int sizeY = static_cast<int>(m_CurrentTexture->getSize().y) / TILE_SIZE;

					sf::Sprite spr(*m_CurrentTexture);

					ig::NewLine();
					for (int y = 0; y < sizeY; y++)
					{
						for (int x = 0; x < sizeX; x++)
						{
							ig::SameLine(0.f, 4.f);
							spr.setTextureRect(sf::IntRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE));
							if (ig::ImageButton(std::to_string(y * 100 + x).c_str(), spr, sf::Vector2f(sf::Vector2i(igTileSize, igTileSize))))
							{
								m_CurrentRect = sf::IntRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
							}
						}
						ig::NewLine();
					}
				}
			}

			ig::TreePop();
		}



		//ig::Image(m_MapTexture, sf::Vector2f(m_MapTexture.getSize()));
	}
	ig::End();
}

void Editor::Display()
{
	m_Map.Display();

	if (m_CurrentTexture && m_CurrentRect.width != 0)
	{
		Window::rectangle.setTexture(m_CurrentTexture);
		Window::rectangle.setTextureRect(m_CurrentRect);
		Window::rectangle.setPosition(Window::GetMousePos());
		Window::rectangle.setSize(sf::Vector2f(sf::Vector2i(TILE_SIZE, TILE_SIZE)));
		Window::rectangle.setOrigin(sf::Vector2f());
		Window::rectangle.setFillColor(sf::Color(255, 255, 255));
		Window::Draw();

		Window::rectangle.setTexture(nullptr);
	}

}
