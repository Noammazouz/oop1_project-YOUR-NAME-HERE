#include "ResourcesManager.h"
#include <iostream>

ResourcesManager::ResourcesManager()
{ 
	//loadTexture(); 
}
ResourcesManager::~ResourcesManager() 
{ 
	//cout << "d-tor" << endl; 
}
ResourcesManager& ResourcesManager::instance() 
{
	static ResourcesManager inst;
	return inst;
}
void ResourcesManager::show() const {
	//cout << m_data << endl;
}
void ResourcesManager::loadTexture()
{
    std::vector<std::pair<std::string, std::string>> textures = 
    {
        {"door", "Door.png"},
        {"guard", "Guard.png"},
        {"player", "Robot.png"},
        {"rock", "Rock.png"},
        {"wall", "wall.png"},
        {"empty", "empty.png"},
        {"menu", "menu.png"},
        {"backround", {"helpBackground.png"}}
    };

    for (const auto& [name, filePath] : textures) 
    {
        sf::Texture texture;
        if (!texture.loadFromFile(filePath)) 
        {
            std::cout << "why" << std::endl;
            // Handle error, return false if the texture fails to load
            //return false;
        }
        
        // Insert the texture into the unordered_map
        m_textures[name] = texture;

    }
}
const sf::Texture* ResourcesManager::getTexture(std::string name)
{
    auto it = m_textures.find(name);
    if (it != m_textures.end()) 
    {
        return &(it->second); // Return a pointer to the texture
    }
    return nullptr; // Return nullptr if the texture is not found
}
