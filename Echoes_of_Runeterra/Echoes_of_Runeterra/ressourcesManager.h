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
#include <string.h>

#define PATH_RESOURCES "..\\Resources\\"
#define PATH_RESOURCES_SOUND PATH_RESOURCES "Sounds\\"
#define PATH_RESOURCES_MUSIC PATH_RESOURCES "Musics\\"
#define PATH_RESOURCES_TEXTURE PATH_RESOURCES "Textures\\"

typedef enum {
	RES_ALL,
	RES_SANDLAND,
	RES_FORESTLAND
}res_EState;

void res_load(res_EState _state);
