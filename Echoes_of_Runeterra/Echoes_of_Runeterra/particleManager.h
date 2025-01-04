#pragma once
#include "Particle.h"
#include <list>

class ParticleManager
{
public:
	ParticleManager() = default;
	~ParticleManager() = default;

	static bool Add(Particle* _particle, bool _pushBack = true);

	static void Update();
	static void Display();

	static std::list<Particle*> particle;

};

