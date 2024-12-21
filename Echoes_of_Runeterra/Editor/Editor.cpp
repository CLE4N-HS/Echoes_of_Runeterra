#include "Editor.h"
#include "imgui.h"
#include "imgui-SFML.h"

constexpr int TILE_SIZE = 32;
constexpr int IG_PIXELS_SIZE = 16;

Editor::Editor() : m_AutoTileDatabase(), m_Map(), m_MapTexture()
{
	m_MapTexture.loadFromFile("../Resources/Textures/Map/tileset.png");
}

Editor::~Editor()
{
}

void Editor::Update()
{
	namespace ig = ImGui;


	
	if (ig::Begin("Map"))
	{
		int sizeX = 28;
		int sizeY = 24;

		sf::Sprite spr(m_MapTexture);

		for (int y = 0; y < sizeY; y++)
		{
			for (int x = 0; x < sizeX; x++)
			{
				ig::SameLine(0.f, 4.f);
				spr.setTextureRect(sf::IntRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE));
				ig::ImageButton(std::to_string(y * x).c_str(), spr, sf::Vector2f(sf::Vector2i(IG_PIXELS_SIZE, IG_PIXELS_SIZE)));
			}
			ig::NewLine();
		}

		//ig::Image(m_MapTexture, sf::Vector2f(m_MapTexture.getSize()));
	}
	ig::End();
}

void Editor::Display()
{
	m_Map.Display();
}
