#include "TorchObject.h"
#include "Window.h"
#include "ObjectTextureManager.h"

TorchObject::TorchObject() : Object()
{
}

TorchObject::TorchObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName) : Object(_pos, _size, _textureName)
{
}

TorchObject::~TorchObject()
{
}

void TorchObject::Display()
{
	this->SetupDraw();

	Window::Draw();
}
