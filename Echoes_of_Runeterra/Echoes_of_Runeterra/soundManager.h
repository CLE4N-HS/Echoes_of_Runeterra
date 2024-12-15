/*
 * Copyright (c) 2024, Hugo et No�
 *
 * Ce code a �t� cr�� en langage C pendant l'�t� 2024 par Hugo Miceli et No� Cleenewerck.
 * Il a �t� traduit et adapt� en C++ par les m�mes auteurs.
 * Tous droits r�serv�s.
 *
 * Toute utilisation, distribution, ou modification de ce code est soumise �
 * l'accord des auteurs.
 */

#pragma once
#include "tools.h"
#include "SFML/Audio.hpp"

typedef struct sound_SData sound_SData;
struct sound_SData {
	sound_SData* pNext;
	int state;
	char* name;
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
};

void sound_load(int _state);
void sound_add(sound_SData* _sound);
sound_SData* sound_remove(sound_SData* _sound);
void sound_play(char* _name);
void sound_deinit(bool _deinitStateAll);
