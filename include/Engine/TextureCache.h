#ifndef ENGINE_TEXTURE_CACHE_H
#define ENGINE_TEXTURE_CACHE_H

#include <map>
#include <SFML/Graphics.hpp>

class TextureCache
{
	public:
	
	static void loadTexture(const std::string& key, const std::string& filename);
	
	static sf::Texture* getTexture(const std::string& key);
	
	static std::map<std::string, sf::Texture*> _cache;
};

#endif