#include "ResourcesManager.h"
#include <iostream>

ResourcesManager::ResourcesManager()
{ 
	loadTexture(); 
}
ResourcesManager::~ResourcesManager() 
{ 
	//cout << "d-tor" << endl; 
}
ResourcesManager& ResourcesManager::getInstance() 
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
        {"backround", "helpBackground.png"},
        {"start game", "start game.png"},
        {"exit", "exit.png"},
        {"help", "help.png"},
		{"return", "return.png"},
        {"explation", "help screen.png"},
        {"bomb", "bomb.png"},
		{"freeze", "freeze.png"},
		//{"remove", "remove.png"},
		{"add time", "add time.png"}
		//{"scoreboard", "scoreboard.png"},
		//{"score", "score.png"},
		//{"time", "time.png"},
		//{"game over", "game over.png"},
        //{"win", "win.png"}
    };

    for (const auto& [name, filePath] : textures) 
    {
        sf::Texture texture;
        if (!texture.loadFromFile(filePath)) 
        {
            std::cout << "Failed to load texture " << filePath <<std::endl;
        }
        
        // Insert the texture into the unordered_map
        m_textures[name] = texture;

    }
}
const sf::Texture& ResourcesManager::getTexture(std::string name)
{
    auto it = m_textures.find(name);
    if (it == m_textures.end())
    {
            std::cout << "Could not find texture: " << name << std::endl;
    }
    return it->second;
}