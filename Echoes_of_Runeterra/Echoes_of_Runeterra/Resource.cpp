#include "Resource.h"
#include "ComponentName.h"

Resource::Resource() : Item()
{
}

Resource::Resource(const std::string& _name) : Item(_name)
{
}

Resource::Resource(const Resource& _resource) : Resource(_resource.GetComponent<ComponentName>()->GetName())
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
