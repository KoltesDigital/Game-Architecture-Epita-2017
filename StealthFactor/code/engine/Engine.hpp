#pragma once

#include <string>
#include <engine/EventListener.hpp>
#include <engine/assets/AssetsManager.hpp>
#include <engine/backend/BackendManager.hpp>
#include <engine/frontend/FrontendManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/network/NetworkManager.hpp>

namespace engine
{
	class Engine : public EventListener
	{
	public:
		Engine();

		bool loadConfiguration();

		bool setUp();
		void tearDown();

		void run();
		float getDeltaTime() const;

		// EventListener
		void onEvent(const sf::Event &event) override;
		void onChat(const std::string &text) override;

	private:
		assets::Manager assetsManager;
		backend::Manager backendManager;
		frontend::Manager frontendManager;
		graphics::Manager graphicsManager;
		input::Manager inputManager;
		network::Manager networkManager;

		bool running;
		float deltaTime;

		// Configuration
		std::string startMap;
	};
}
