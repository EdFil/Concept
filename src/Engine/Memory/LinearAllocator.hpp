#pragma once

class LinearAllocator {
public:
	LinearAllocator(void* memoryStart, size_t memorySize);
	~LinearAllocator();

	void init(void* memoryStart, size_t memorySize);

	void allocate(size_t chunkSize, const char* debugName);
	void free(void* memoryPointer);

private:
	const void* _memoryStart;
	const size_t _memorySize;

	size_t _numAllocations = 0;
	size_t _usedMemory = 0;
};