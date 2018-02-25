#include "MemoryManager.hpp"

#include <new>

#include "SDL_log.h"

#include "LinearAllocator.hpp"

MemoryManager::MemoryManager() {
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "MemoryManager: Initialize");

	_globalMemory = SDL_malloc(MEMORY_CAPACITY);
	_globalMemory = SDL_memset(_globalMemory, 0, MEMORY_CAPACITY);
	if (_globalMemory != nullptr) {
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "MemoryManager: Allocated %d bytes", MEMORY_CAPACITY);
	}
	else {
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "MemoryManager: Failed to allocate memory");
	}

	_globalMemoryAllocator = new (_globalMemory) LinearAllocator(_globalMemory, MEMORY_CAPACITY);
}

MemoryManager::~MemoryManager() {
	_globalMemoryAllocator->~LinearAllocator();
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Destroy MemoryManager");

	if (_globalMemory != nullptr) {
		SDL_free(_globalMemory);
	}
}

void MemoryManager::allocate(size_t chunkSize, const char* debugName) {
}

void MemoryManager::free(void* memoryPointer) {
}