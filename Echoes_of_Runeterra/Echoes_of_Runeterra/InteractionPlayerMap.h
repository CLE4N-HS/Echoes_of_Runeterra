#pragma once
#include "Interaction.h"
#include "CharacterManager.h"
#include "MapManager.h"

class InteractionPlayerMap : public Interaction
{
public:
	InteractionPlayerMap();
	~InteractionPlayerMap();

	void update(Window& _window, CharacterManager* _characterManager, MapManager* _mapManager);

private:

};
