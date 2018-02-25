#pragma once

enum class ComponentType {
	INVALID = -1,
	Transform = 0,
	NUM_COMPONENTS
};

class Component {
	virtual void cleanup() = 0;
};