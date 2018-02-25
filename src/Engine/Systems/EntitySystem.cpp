#include "EntitySystem.hpp"

#include <SDL_log.h>
#include <SDL_assert.h>

#include "../Engine.hpp"
#include "Entity.hpp"
#include "TransformSystem.hpp"

bool EntitySystem::initialize(Engine* engine) {
	if (engine == nullptr) {
		SDL_assert(false);
		SDL_LogError(SDL_LOG_CATEGORY_ASSERT, "EntitySystem::Initialize::Engine is nullptr");
		return false;
	}

	_engine = engine;
	for (Entity& entity : _entities) {
		entity._system = this;
	}

	return true;
}

Entity* EntitySystem::createEntity() {
	for (Entity& entity : _entities) {
		if (entity._state == EntityState::Unused) {
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "EntitySystem::createEntity: Created Entity");
			entity._state = EntityState::Used;
			_engine->transformSystem()->createTransform(&entity);
			return &entity;
		}
	}

	return nullptr;
}

void EntitySystem::destroyEntity(Entity* entity) {
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "EntitySystem::destroyEntity: Destroyed Entity");
	entity->_state = EntityState::Unused;
}

void EntitySystem::debugDraw(SDL_Renderer* renderer) {
	for (Entity& entity : _entities) {
		entity.debugDraw(renderer);
	}
}