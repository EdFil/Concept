#include "Engine.hpp"

#include <SDL.h>
#include <SDL_log.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool Engine::initialize() {
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_Init Error: %s", SDL_GetError());
		return false;
	}

	_window = SDL_CreateWindow("Engine", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (_window == nullptr) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_CreateWindow Error: %s", SDL_GetError());
		SDL_Quit();
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == nullptr) {
		SDL_DestroyWindow(_window);
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL_CreateRenderer Error: %s", SDL_GetError());
		SDL_Quit();
		return false;
	}

	if (!_entitySystem.initialize(this)) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "Could not initialize EntitySystem");
		return false;
	}

	if (!_transformSystem.initialize(this)) {
		SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "Could not initialize TransformSystem");
		return false;
	}

	return true;
}

void Engine::cleanup() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Engine::run() {
	_isRunning = true;
	mainLoop();
}

static Entity* _entity = nullptr;

void Engine::mainLoop() {
	while (_isRunning) {
		// Fetch SDL_Events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				_isRunning = false;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (_entity == nullptr) {
					_entity = _entitySystem.createEntity();
				}
				else {
					_entitySystem.destroyEntity(_entity);
					_entity = nullptr;
				}
			}
		}

		// Render Scene
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
		SDL_RenderClear(_renderer);
		_entitySystem.debugDraw(_renderer);
		SDL_RenderPresent(_renderer);
	}
}
