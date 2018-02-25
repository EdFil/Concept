#include "TransformSystem.hpp"

#include <SDL_log.h>
#include <SDL_assert.h>

#include "Entity.hpp"

bool TransformSystem::initialize(Engine* engine) {
	if (engine == nullptr) {
		SDL_assert(false);
		SDL_LogError(SDL_LOG_CATEGORY_ASSERT, "TransformSystem::Initialize::Engine is nullptr");
		return false;
	}

	_engine = engine;
	for (TransformComponent& component : _components) {
		component._system = this;
	}

	return true;
}

TransformComponent* TransformSystem::createTransform(Entity* entity) {
	for (TransformComponent& component: _components) {
		if (component._state == TransformState::Unused) {
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "TransformSystem::createTransform: Created Transform");
			if (entity->addComponent(&component)) {
				component._state = TransformState::Used;
			}

			return &component;
		}
	}

	return nullptr;
}

bool TransformSystem::destroyTransform(TransformComponent* transformComponent) {
	if (transformComponent == nullptr) {
		SDL_assert(false);
		SDL_LogError(SDL_LOG_CATEGORY_ASSERT, "TransformSystem::destroyTransform: Component is nullptr");
		return false;
	}

	//auto it = std::find(_components.begin(), _components.end(), transformComponent);

	//if (it == _components.end()) {
	//	SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "TransformSystem::destroyTransform: Could not remove transform");
	//	return false;
	//}

	if (transformComponent->_state == TransformState::Unused) {
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "TransformSystem::destroyTransform: Transform already unused");
		return true;
	}

	transformComponent->cleanup();
	return true;
}