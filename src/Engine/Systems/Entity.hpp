#pragma once

#include "Component.hpp"

#include <array>
#include <vector>

class TransformComponent;
struct SDL_Renderer;
class EntitySystem;

enum class EntityState {
	Used,
	Unused
};

class Entity {
public:
	//template<typename T> typename T* createComponent() { return nullptr; }
	//template<> TransformComponent* createComponent<TransformComponent>() { return nullptr;};
	Entity();

	bool addComponent(Component* component);
	bool removeComponent(Component* component);

	template<typename T> T* getComponent();

	void cleanup();

	// <DEBUG>
	void debugDraw(SDL_Renderer* _renderer);
	// </DEBUG>

private:
	EntitySystem* _system = nullptr;
	EntityState _state = EntityState::Unused;
	std::vector<Component*> _components;

	// <DEBUG>
	float _debugR;
	float _debugG;
	float _debugB;
	// </DEBUG>

	friend EntitySystem;
};