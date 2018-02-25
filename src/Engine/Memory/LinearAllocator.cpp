#include "LinearAllocator.hpp"

#include <SDL_log.h>

LinearAllocator::LinearAllocator(void* memoryStart, size_t memorySize) : _memoryStart(memoryStart), _memorySize(memorySize) {
	SDL_Log("LinearAllocator: Constructor");
}

LinearAllocator::~LinearAllocator() {
	SDL_Log("LinearAllocator: Destructor");
}

void LinearAllocator::init(void * memoryStart, size_t memorySize) {
}

void LinearAllocator::allocate(size_t chunkSize, const char* debugName) {

}

void LinearAllocator::free(void* memoryPointer) {

}