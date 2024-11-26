#include "Button.h"
#include "ComponentName.h"
#include "Window.h"

Button::Button(const std::string& _string, Entity _entity) : Entity(_entity)
{
	this->AddComponent<ComponentName>(_string);
}

void Button::Display()
{
	this->transform->CorrectWindowRectangle();
	Window::Draw();

	Window::text.setString(this->GetComponent<ComponentName>()->GetName());
	Window::text.setPosition(this->transform->getPos());
	Tools::CenterTextOrigin(Window::text);
	Window::Draw(Window::text);
}
