#pragma once

static constexpr size_t MEMORY_CAPACITY = 1 * 1024 * 1024; // 1 MB

class LinearAllocator;

class MemoryManager {
public:
	MemoryManager();
	~MemoryManager();

	void allocate(size_t chunkSize, const char* debugName);
	void free(void* memoryPointer);

private:
	void* _globalMemory = nullptr;
	LinearAllocator* _globalMemoryAllocator = nullptr;
};