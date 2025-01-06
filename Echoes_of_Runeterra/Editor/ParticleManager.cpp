#include "ParticleManager.h"
#include "Window.h"

std::list<Particle*> ParticleManager::particle = {};

bool ParticleManager::Add(Particle* _particle, bool _pushBack)
{
    if (!_particle)
        return false;

    if (_pushBack)
    {
        particle.push_back(_particle);
    }
    else
    {
        particle.push_front(_particle);
    }

    return true;
}

void ParticleManager::Update()
{
    for (std::list<Particle*>::iterator it = particle.begin(); it != particle.end();)
    {
        if (!((*it)->Update()))
        {
            delete (*it);
            it = particle.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void ParticleManager::Display()
{
    Window::rectangle.setTexture(nullptr);

    for (Particle* p : particle)
    {
        p->Display();
    }
}
