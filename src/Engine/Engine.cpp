#include <Engine/Engine.h>
#include <Engine/Entity.h>
#include <Engine/System.h>

bool EventHandler::onEvent(sf::Event& event){}


Engine::Engine()
{
	_app = new sf::RenderWindow(sf::VideoMode(800, 600), "Game9 Bench");
	_app->setKeyRepeatEnabled(false);
	_gui = new sfg::SFGUI();
	_frameCount = 0;
	_fps = 0.0;
}

Engine::~Engine()
{
	delete _gui;
	delete _app;
}

void Engine::loop()
{
	
	 while (_app->isOpen())
	{
		if(_timer.getElapsedTime().asSeconds() < 1.0/60.0)
			continue;
		
		_timer.restart();
		double globalTime = _globalClock.getElapsedTime().asSeconds();
	
		sf::Event event;
		while (_app->pollEvent(event))
		{
			// fermeture de la fenetre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed)
				_app->close();
			
			
			// fermeture de la fenetre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				_app->close();
			
			
			if (event.type == sf::Event::Resized)
			{
				sf::View view = _app->getView();
				float aspectRatio = (float)event.size.height/(float)event.size.width;
				_app->setView(sf::View(sf::FloatRect(view.getCenter().x, view.getCenter().y, view.getSize().x, view.getSize().x * aspectRatio)));
			}
			
			for(unsigned int i=0; i<_handlers.size(); ++i)
			{
				_handlers[i]->onEvent(event);
			}
			
			// Handle events
			for(unsigned int i=0; i<_guiWidget.size(); ++i)
			{
				_guiWidget[i]->HandleEvent(event);
			}
		}
		
		if(_fpsTimer.getElapsedTime().asSeconds() >= 1.0)
		{
			_fps = (double)_frameCount/_fpsTimer.getElapsedTime().asSeconds();
			_frameCount = 0;
			_fpsTimer.restart();
			
			std::cout << "FPS : " << _fps << std::endl;
		}

		// effacement de la fenetre en noir
		_app->clear(sf::Color(150,150,255));
		
		for(unsigned int i=0; i<_entities.size(); ++i)
		{
			_entities[i]->update(this, globalTime);
		}
		
		for(unsigned int i=0; i<_systems.size(); ++i)
		{
			_systems[i]->process(_entities, globalTime);
		}
		
		// Update the GUI, note that you shouldn't normally
		// pass 0 seconds to the update method.
		for(unsigned int i=0; i<_guiWidget.size(); ++i)
		{
			_guiWidget[i]->Update(0.f);
		}
		
		// Draw the GUI
		_gui->Display( *_app );

		// fin de la frame courante, affichage de tout ce qu'on a dessine
		_app->display();
		
		++_frameCount;
	}
	
	
}