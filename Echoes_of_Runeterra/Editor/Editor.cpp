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
	this->UpdateImGui();

	if (TileTextureManager::GetTexture(m_CurrentTextureName) && m_CurrentRect.width != 0)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mousePos = Window::GetMousePos();

			m_MapEdit.EditTile(mousePos, m_CurrentTextureName, m_CurrentRect);
		}
	}
}

void Editor::UpdateImGui()
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
				ig::SliderInt("Size", &igTileSize, 0, 64);

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



		//ig::Image(m_MapTexture, sf::Vector2f(m_MapTexture.getSize()));
	}
	ig::End();
}

void Editor::Display()
{
	m_Map.Display();

	if (sf::Texture* currentTexture = TileTextureManager::GetTexture(m_CurrentTextureName); m_CurrentRect.width != 0)
	{
		Window::rectangle.setTexture(currentTexture);
		Window::rectangle.setTextureRect(m_CurrentRect);
		Window::rectangle.setPosition(Window::GetMousePos());
		Window::rectangle.setSize(sf::Vector2f(sf::Vector2i(Tile::SIZE, Tile::SIZE)));
		Window::rectangle.setOrigin(sf::Vector2f());
		Window::rectangle.setFillColor(sf::Color(255, 255, 255));
		Window::Draw();

		//Window::rectangle.setTexture(nullptr);
	}

}
