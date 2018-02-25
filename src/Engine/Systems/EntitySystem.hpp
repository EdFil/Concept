#pragma once

#include "Entity.hpp"

#include <array>
#include "../Utils/Constants.hpp"

class Engine;

class EntitySystem {
public:
	bool initialize(Engine* engine);

	Entity* createEntity();
	void destroyEntity(Entity* entity);

	Engine* engine() const { return _engine; }

	void debugDraw(SDL_Renderer* renderer);

private:
	Engine* _engine = nullptr;
	std::array<Entity, g_numMaxEntities> _entities;
};