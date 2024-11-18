#pragma once
#include "Tools.h"
#include "Entity.h"

class Skills : public Entity
{
public:
	Skills();
	Skills(const std::string& _name);
	~Skills();

	bool operator==(Skills* _skills);

	virtual void Update() = 0;

private:

};
