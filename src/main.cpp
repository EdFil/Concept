#include <iostream>
#include <SDL.h>

#include "Engine/Engine.hpp"
#include "Engine/Memory/MemoryManager.hpp"

int main(int, char**) {
	MemoryManager* memoryManager = new MemoryManager();

	delete memoryManager;

	//Engine* engine = new Engine();
	//if (engine->initialize()) {
	//	engine->run();
	//}

	//engine->cleanup();
	return 0;
}