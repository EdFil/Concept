#pragma once

#include <array>

#include "TransformComponent.hpp"
#include "../Utils/Constants.hpp"

class Engine;
class Entity;

class TransformSystem {
public:
	bool initialize(Engine* engine);
	TransformComponent* createTransform(Entity* entity);
	bool destroyTransform(TransformComponent* transformComponent);

	Engine* engine() const { return _engine; }
private:
	Engine* _engine;
	std::array<TransformComponent, g_numMaxEntities> _components;
};