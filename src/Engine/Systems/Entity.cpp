#include "Entity.hpp"

#include <SDL.h>
#include <cstdlib>
#include <SDL_log.h>
#include <SDL_assert.h>

#include "TransformComponent.hpp"
#include "TransformSystem.hpp"
#include "EntitySystem.hpp"
#include "../Engine.hpp"

Entity::Entity() {
	_debugR = rand() % 256;
	_debugG = rand() % 256;
	_debugB = rand() % 256;
}

bool Entity::addComponent(Component* newComponent) {
	if (newComponent == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_ASSERT, "Entity::addComponent: Component cannot be nullptr");
		SDL_assert(false);
		return false;
	}

	// <DEBUG>
	for (const Component* component : _components) {
		if (component == newComponent) {
			SDL_LogError(SDL_LOG_CATEGORY_ASSERT, "Entity::addComponent: Component already added");
			SDL_assert(false);
			return false;
		}
	}
	// </DEBUG>

	_components.push_back(newComponent);
	return true;
}

bool Entity::removeComponent(Component* component) {
	if (component == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_ASSERT, "Entity::removeComponent: Component cannot be nullptr");
		SDL_assert(false);
		return false;
	}

	auto it = std::find(_components.cbegin(), _components.cend(), component);

	if (it != _components.cend()) {
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Entity::removeComponent: Removed component");
		_components.erase(it);
		return true;
	}

	SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Entity::removeComponent: Could not find component to remove");
	return false;
}

template<> TransformComponent* Entity::getComponent() {
	return nullptr;
}

void Entity::cleanup() {
	SDL_assert(false); // NOT IMPLEMENTED
}

// <DEBUG>

void Entity::debugDraw(SDL_Renderer* _renderer) {
	if (_state == EntityState::Used)  {
		SDL_SetRenderDrawColor(_renderer, _debugR, _debugG, _debugB, 255);
		SDL_Rect rect = {10, 10, 10, 10};
		SDL_RenderDrawRect(_renderer, &rect);
	}
}
// </DEBUG>