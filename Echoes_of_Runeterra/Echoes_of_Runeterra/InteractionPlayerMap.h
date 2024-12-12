#pragma once
#include "Interaction.h"
#include "CharacterManager.h"
//#include "MapManager.h"

class InteractionPlayerMap : public Interaction
{
public:
	InteractionPlayerMap();
	~InteractionPlayerMap();

	void Update(PawnManager* _characterManager/*, MapManager* _mapManager*/);

private:

};
