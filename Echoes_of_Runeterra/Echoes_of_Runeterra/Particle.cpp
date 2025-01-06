#include "Particle.h"
#include "Window.h"

bool Particle::Update()
{
	float dt = Tools::GetDeltaTime();

	lifeTime += dt;

	pos += velocity * dt;

	float normalizedLifeTime = lifeTime / timeToDie;

	color = Tools::Lerp(startColor, endColor, normalizedLifeTime);

	bool isInScreen = (sf::FloatRect(pos - origin, size).intersects(sf::FloatRect(Window::view.getCenter() - Window::view.getSize() * 0.5f, Window::view.getSize())));

	return (isInScreen && (lifeTime < timeToDie));
}

void Particle::Display()
{
	Window::rectangle.setPosition(pos);
	Window::rectangle.setSize(size);
	Window::rectangle.setOrigin(origin);
	Window::rectangle.setFillColor(color);
	Window::Draw();
}
