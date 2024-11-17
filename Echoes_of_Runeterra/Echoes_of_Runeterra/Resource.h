#pragma once
#include "Item.h"

class Resource : public Item
{
public:
	Resource();
	Resource(const std::string& _name);
	~Resource();

	virtual void Update() override;
	virtual void Display() override;

private:

};
