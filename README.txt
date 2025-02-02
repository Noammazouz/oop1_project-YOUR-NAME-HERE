#Bomberman Game - Noam Mazouz & Ofek Cohen

Bomberman Game is a simple maze game where the player controls a bomberman trying to navigate through a maze while avoiding guard and trying to reach the door.
The game is implemented using C++ and SFML (Simple and Fast Multimedia Library) for graphics rendering.

## Overview

In Bomberman Game, the player controls a bomberman character navigating through various mazes filled with obstacles, challenges, and rewards.
The objective is to reach the door while avoiding the guard that roam the area.
The game features multiple levels with increasing difficulty, each with unique maze layouts and obstacles.
Players must use strategy and quick reflexes to navigate through the maze, setting bombs, and reach the door without being caught by the guards.

## Features

- **Player Control**: Navigate the bomberman character using keyboard arrows.
- **Collision Detection**: Handle interactions between bomberman, obstacles, and other objects.
- **Game Objects**: Walls, rocks, door, medkits, freeze power-ups, kill guard power-ups, time add,
- **Scoring System**: Track score based on guards in the level and other objects.
- **Sound Effects and Music**: Integrated sounds and background music for immersive gameplay.
- **User Interface**: Buttons for starting and quitting the game, as well as help.

## Game Objects

- **Bomberman**: Player-controlled character navigating the maze.
- **Guards**: Enemies that follow the bomberman and decrease the player's health if caught.
- **Door**: to move from one level to the other.
- **Medkits**: Provide extra lives to the player.
- **Freeze Power-ups**: Temporarily stop guards from moving for 3 seconds.
- **Water Gun**: Removing a guard from the level.
- **clock**: Adds 10 seconds to the level timer.

## Files

### Headers
- **addingtime.h**: Declares the `AddingTime` class representing clock objects that provide extra 10 seconds to the timer of the level.
- **board.h**: Load the levels from the files.
- **bombs.h**: Declares the `Bombs` class representing bomb objects that provide the player to kill guards and destroy obstacles.
- **const.h**: Contains the consts of the game;
- **door.h**: Contains the `Door` class declaration representing door object that let the player move to the next level.
- **explosion.h**: 
- **freezingGuards.h**: Defines the `Freeze` class representing freeze power-ups in the game.
- **gameController.h**: 
- **gameObjects.h**: Contains the `GameObjects` class declaration, which is a base class for all game objects.
- **guard.h**:
- **IncreasingLife.h**: Declares the `Medkit` class representing medkit objects that provide extra lives to the player.
- **menu.h**: Defines the `Menu` class representing the main menu of the game.
- **player.h**: 
- **removingGuard.h**:
- **resourcesManager.h**:
- **rock.h**: Declares the `Rock` class representing rock objects that block the player's path.
- **scoreBoard.h**:
- **staticObjects.h**: Defines the `StaticObjects` class representing static game objects in the game.
- **updateableObjects.h**: Contains the `updateableObjects` class declaration, which is a base class for moving game objects.
- **wall.h**: Declares the `Wall` class representing wall objects that block the player's path.

### Source Files (CPP)

- **addingtime.cpp**:
- **board.cpp**: 
- **bombs.cpp**: 
- **door.cpp**: Defines the behavior of the `Door` class representing door objects.
- **explosion.cpp**:
- **freezingGuard.cpp**: Implements the methods of the `Freeze` class representing freeze power-ups.
- **gameController.cpp**:
- **gameObjects.cpp**: Implements methods of the `GameObjects` base class for game objects.
- **guard.cpp**:
- **IncreasingLife.cpp**: Defines the behavior of the `Medkit` class representing medkit objects.
- **menu.cpp**: Implements the methods of the `Menu` class for the game's main menu.
- **player.cpp**: 
- **removingGuard.cpp**:
- **resourcesManager.cpp**:
- **staticObjects.cpp**: Implements methods of the `StaticObjects` class for static game objects.
- **updateableObjects.cpp**: 
- **wall.cpp**: Implements the methods of the `Wall` class representing wall objects.

### Adding a new level
to add a new level add a file named Level[the level number].txt

dictionary for making a new level:

/ - bomberman.
! - guard.
- - water gun(kills a guard).
@ - rock.
$ - medkit (increase lives by 1).
# - wall.
+ - increase the level timer by 10 seconds.
D - door.
* - freeze (stops the gaurds in place for 3 seconds).

## Credits

- Game developed by Noam Mazouz & Ofek Cohen.
- Sound effects and music obtained from Youtube, Pixabay.
- Special thanks to our lecturers Michal Merkin & Yehezkel Bernat for their assistance and feedback.
- Inspired by Bomberman games.

## License

This project is licensed under the Hadassah Academic College students:
Noam Mazouz & Ofek Cohen.
