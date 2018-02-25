#pragma once

#include "Component.hpp"

class TransformSystem;

enum class TransformState {
	Used, Unused
};

class TransformComponent : public Component {

public:
	TransformComponent();
	void cleanup() override;

private:
	TransformSystem* _system = nullptr;
	TransformState _state = TransformState::Unused;

	float _x = 0.0f;
	float _y = 0.0f;

	friend TransformSystem;
};