#include <SFML/Graphics.hpp>

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

#include <Engine/TextureCache.h>

#include <Engine/Entity.h>
#include <Engine/Engine.h>

#include "Engine/Components/PositionComponent.h"

#include "Engine/Systems/PhysicSystem.h"
#include "Engine/Systems/GraphicSystem.h"

#include <Test/Dog.h>
#include <Test/GroundPlatform.h>
#include <Test/WoodBox.h>
#include <Test/ZoneCage.h>
#include <Test/Player.h>

class FPSDisplayer : public Entity
{
	public:
	
	FPSDisplayer(Engine* engine, Player* player)
		: Entity(0)
	{
		_engine = engine;
        _player = player;
		
		// Create our main SFGUI window
		auto window = sfg::Window::Create();
		window->SetTitle( "Game9" );

		// Create the label.
		_fpsLabel = sfg::Label::Create();
		window->Add( _fpsLabel );
        
		// Set the text of the label.
		_fpsLabel->SetText( "Alpha Pre Release 0.0.1\nRC1 A rev 2\nFPS : 0" );
        
		_engine->_guiWidget.push_back(window);
	}
	
	virtual ~FPSDisplayer()
	{
		
	}
	
	virtual void update(Engine* engine, double globalTime)
	{
		std::vector<PositionComponent*> positions;
		_player->pullComponent(positions);
		
		float velocity = sqrt(positions[0]->_velocity.x*positions[0]->_velocity.x + positions[0]->_velocity.y*positions[0]->_velocity.y);
		
		std::stringstream ss;
		ss << "Alpha Pre Release 0.0.1\nRC1 A rev 2\nFPS : " << _engine->_fps << "\n";
		ss << "velocity : " << velocity;
		_fpsLabel->SetText( ss.str() );
	}
	
	Engine* _engine;
	Player* _player;
	std::shared_ptr<sfg::Label> _fpsLabel;
};

int main()
{
    // textures
    TextureCache::loadTexture("box", "assets/woodBox01.png");
	TextureCache::loadTexture("bob", "assets/bob01.png");
	TextureCache::loadTexture("dog", "assets/dog01.png");
	
	// ECS
    Engine engine;
	GraphicSystem graphic(engine._app);
	PhysicSystem physic;
	engine._systems.push_back(&physic);
	engine._systems.push_back(&graphic);
	
	engine._entities.push_back( new ZoneCage() );
	Player* player = new Player(3,5,1);
	engine._entities.push_back( player );
	engine._handlers.push_back( player );
	
	
	engine._entities.push_back( new WoodBox(7,5, 1) );
	engine._entities.push_back( new WoodBox(2, 7, 0.5) );
	engine._entities.push_back( new WoodBox(3, 9, 0.5) );
	engine._entities.push_back( new WoodBox(1, 1, 0.2) );
	engine._entities.push_back( new WoodBox(7, 7, 2) );
	
	
	engine._entities.push_back( new GroundPlatform(3, 2, 1) );
	engine._entities.push_back( new GroundPlatform(5, 2, 2) );
	engine._entities.push_back( new GroundPlatform(8, 2, 1) );
	engine._entities.push_back( new GroundPlatform(1, 4, 2) );
	engine._entities.push_back( new GroundPlatform(4, 6, 1) );
	engine._entities.push_back( new GroundPlatform(6, 7, 3) );
	
	engine._entities.push_back( new Dog(12, 3, 1) );
	
	engine._entities.push_back(new FPSDisplayer(&engine, player));
	
	// game loop
    engine.loop();

    return 0;
}
