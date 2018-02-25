#pragma once

#include "Systems/EntitySystem.hpp"
#include "Systems/TransformSystem.hpp"
//#include "Memory/MemoryManager.hpp"

struct SDL_Window;
struct SDL_Renderer;

class Engine {
public:
	bool initialize();
	void cleanup();

	void run();

	// System getters
	EntitySystem* entitySystem() const { return const_cast<EntitySystem*>(&_entitySystem); }
	TransformSystem* transformSystem() const { return const_cast<TransformSystem*>(&_transformSystem); }
	//MemoryManager* memoryManager() const { return const_cast<MemoryManager*>(&_memoryManager); }

private:
	void mainLoop();

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	bool _isRunning = false;

	//MemoryManager _memoryManager;
	EntitySystem _entitySystem;
	TransformSystem _transformSystem;
};