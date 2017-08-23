#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class System;
class Entity;

class EventHandler
{
	public:
	
	virtual bool onEvent(sf::Event& event);
};

class Engine
{
	public:
	
	std::vector<System*> _systems;
	std::vector<Entity*> _entities;
	std::vector<EventHandler*> _handlers;
	
	
	sf::RenderWindow* _app;
	sfg::SFGUI* _gui;
	std::vector< std::shared_ptr<sfg::Widget> > _guiWidget;
	// time management
	sf::Clock _globalClock;
	sf::Clock _timer;
    sf::Clock _fpsTimer;
    unsigned int _frameCount;
	double _fps;
	
	Engine();
	
	virtual ~Engine();
	
	void loop();
};

#endif