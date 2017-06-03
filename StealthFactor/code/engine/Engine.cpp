#include "engine/Engine.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <SFML/System.hpp>

namespace engine
{
	Engine::Engine()
		: graphicsManager{ assetsManager, *this }
		, backendManager{ frontendManager, assetsManager, inputManager }
		, frontendManager{ assetsManager, graphicsManager }
	{
	}

	bool Engine::loadConfiguration()
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("configuration.xml");

		if (result)
		{
			assert(!doc.empty());
			auto configuration = doc.first_child();
			startMap = configuration.child_value("start_map");

			return true;
		}
		else
		{
			std::cerr << "Configuration parsed with errors." << std::endl;
			std::cerr << "Error description: " << result.description() << std::endl;
			std::cerr << "Error offset: " << result.offset << std::endl;

			return false;
		}
	}

	bool Engine::setUp()
	{
		if (!graphicsManager.setUp())
		{
			return false;
		}

		frontendManager.setUp();

		return true;
	}

	void Engine::tearDown()
	{
		frontendManager.tearDown();
		graphicsManager.tearDown();
	}

	void Engine::run()
	{
		running = true;

		backendManager.loadMap(startMap);

		sf::Clock clock;
		while (running)
		{
			deltaTime = clock.restart().asSeconds();

			inputManager.clear();

			graphicsManager.pollEvents();
			backendManager.update();

			graphicsManager.draw();
		}
	}

	float Engine::getDeltaTime() const
	{
		return deltaTime;
	}

	void Engine::onEvent(const sf::Event &event)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			running = false;
			break;

		case sf::Event::LostFocus:
			inputManager.setActive(false);
			break;

		case sf::Event::GainedFocus:
			inputManager.setActive(true);
			break;

		case sf::Event::KeyPressed:
			inputManager.onKeyPressed(event.key);
			break;

		case sf::Event::KeyReleased:
			inputManager.onKeyReleased(event.key);
			break;
		}
	}
}
