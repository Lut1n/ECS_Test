#include <Engine/TextureCache.h>

std::map<std::string, sf::Texture*> TextureCache::_cache;


void TextureCache::loadTexture(const std::string& key, const std::string& filename)
{
	if(_cache.find(key) == _cache.end())
	{
		_cache[key] = new sf::Texture();
		_cache[key]->loadFromFile(filename);
		_cache[key]->setSmooth(true);
	}
}

sf::Texture* TextureCache::getTexture(const std::string& key)
{
	if(_cache.find(key) != _cache.end())
	{
		return _cache[key];
	}
}