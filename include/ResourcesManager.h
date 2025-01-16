#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <unordered_map>

class ResourcesManager 
{
public:
	~ResourcesManager();
	static ResourcesManager& getInstance();
	const sf::Texture& getTexture(std::string name);
	void loadTexture();
	void show() const;
private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager&) = delete;
	ResourcesManager& operator=(const ResourcesManager&) = delete;
	//void loadTexture();
	std::unordered_map<std::string, sf::Texture> m_textures;
};
