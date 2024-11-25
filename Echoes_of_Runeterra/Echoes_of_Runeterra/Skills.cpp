#include "Skills.h"
#include "ComponentName.h"

Skills::Skills() : Skills("")
{
}

Skills::Skills(const std::string& _name)
{
	this->AddComponent<ComponentName>(_name);
}

Skills::~Skills()
{
}

bool Skills::operator==(Skills* _skills)
{
	return (this->GetComponent<ComponentName>()->GetName() == _skills->GetComponent<ComponentName>()->GetName());
}
