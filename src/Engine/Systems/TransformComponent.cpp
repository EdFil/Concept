#include "TransformComponent.hpp"

#include <cstdlib>

TransformComponent::TransformComponent() {
	_x = rand() % 801;
	_y = rand() % 601;
}

void TransformComponent::cleanup() {
	_x = _y = 0.0f;
	_state = TransformState::Unused;
}