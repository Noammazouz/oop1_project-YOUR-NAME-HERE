#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <unordered_map>

class ResourcesManager 
{
public:
	~ResourcesManager();
	static ResourcesManager& instance();
    const sf::Texture* getTexture(std::string name);
	void loadTexture();
	void show() const;
private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager&) = default;
	ResourcesManager& operator=(const ResourcesManager&) = default;
	//void loadTexture();
	std::unordered_map<std::string, sf::Texture> m_textures;
};
