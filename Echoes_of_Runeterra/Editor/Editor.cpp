#include "Editor.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "TextureManager.h"

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

	bool* igUseless = nullptr;
	if (ig::Begin("Editor", igUseless, ImGuiWindowFlags_HorizontalScrollbar))
	{
		if (ig::TreeNode("Map"))
		{
			static sf::Texture* currentTexture = nullptr;

			if (ig::TreeNode("Map Texture"))
			{
				std::map<std::string_view, sf::Texture*> texture = TextureManager::Get();

				for (std::map<std::string_view, sf::Texture*>::iterator it = texture.begin(); it != texture.end(); it++)
				{
					if (ig::Button((*it).first.data()))
					{
						currentTexture = (*it).second;
					}
				}

				ig::NewLine();

				ig::TreePop();
			}

			if (currentTexture)
			{
				static int igTileSize = 16;
				ig::PushItemWidth(400.f);
				ig::SliderInt("Size", &igTileSize, 0, 64);



				int sizeX = static_cast<int>(currentTexture->getSize().x) / TILE_SIZE;
				int sizeY = static_cast<int>(currentTexture->getSize().y) / TILE_SIZE;

				sf::Sprite spr(*currentTexture);

				ig::NewLine();
				for (int y = 0; y < sizeY; y++)
				{
					for (int x = 0; x < sizeX; x++)
					{
						ig::SameLine(0.f, 4.f);
						spr.setTextureRect(sf::IntRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE));
						if (ig::ImageButton(std::to_string(y * 100 + x).c_str(), spr, sf::Vector2f(sf::Vector2i(igTileSize, igTileSize))))
						{
						}
					}
					ig::NewLine();
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
}
