#include "Resource.h"

Resource::Resource() : Item()
{
}

Resource::Resource(const std::string& _name) : Item(_name)
{
}

Resource::~Resource()
{
}

void Resource::Update()
{
	Item::Update();
}

void Resource::Display()
{
}
