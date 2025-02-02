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
- **explosion.h**: Contains the `Explosion` class declaration representing explosion objects that occur when a bomb explodes.
- **freezingGuards.h**: Defines the `Freeze` class representing freeze power-ups in the game.
- **gameController.h**: Constains the game controller class that controls the game.
- **gameObjects.h**: Contains the `GameObjects` class declaration, which is a base class for all game objects.
- **guard.h**: Contains the `Guard` class declaration representing guard objects that chase the player.
- **IncreasingLife.h**: Declares the `Medkit` class representing medkit objects that provide extra lives to the player.
- **menu.h**: Defines the `Menu` class representing the main menu of the game.
- **player.h**: Contains the `Player` class declaration	representing the player-controlled character.
- **removingGuard.h**: Declares the `RemovingGuard` class representing kill guard power-ups.
- **resourcesManager.h**: Contains the `ResourcesManager` class declaration for loading game resources.
- **rock.h**: Declares the `Rock` class representing rock objects that block the player's path.
- **scoreBoard.h**: Contains the `ScoreBoard` class declaration for tracking player score, level number, time that is left in the level, player lives.
- **staticObjects.h**: Defines the `StaticObjects` class representing static game objects in the game.
- **updateableObjects.h**: Contains the `updateableObjects` class declaration, which is a base class for moving game objects.
- **wall.h**: Declares the `Wall` class representing wall objects that block the player's path.

### Source Files (CPP)

- **addingtime.cpp**: Implements the methods of the `AddingTime` class representing clock objects that provide extra 10 seconds to the timer of the level.
- **board.cpp**: Implements the methods of the `Board` class for loading levels from files.
- **bombs.cpp**: Implements the methods of the `Bombs` class representing bomb objects that provide the player to kill guards and destroy obstacles.
- **door.cpp**: Defines the behavior of the `Door` class representing door objects.
- **explosion.cpp**: Implements the methods of the `Explosion` class representing explosion objects that occur when a bomb explodes.
- **freezingGuard.cpp**: Implements the methods of the `Freeze` class representing freeze power-ups.
- **gameController.cpp**: Implements the methods of the `GameController` class that controls the game.
- **gameObjects.cpp**: Implements methods of the `GameObjects` base class for game objects.
- **guard.cpp**: Defines the behavior of the `Guard` class representing guard objects that chase the player.
- **IncreasingLife.cpp**: Defines the behavior of the `Medkit` class representing medkit objects.
- **menu.cpp**: Implements the methods of the `Menu` class for the game's main menu.
- **player.cpp**: Implements the methods of the `Player` class representing the player-controlled character.
- **removingGuard.cpp**: Implements the methods of the `RemovingGuard` class representing kill guard power-ups.
- **resourcesManager.cpp**: Implements the methods of the `ResourcesManager` class for loading
- **staticObjects.cpp**: Implements methods of the `StaticObjects` class for static game objects.
- **updateableObjects.cpp**: Implements the methods of the `updateableObjects` class for moving game objects.
- **wall.cpp**: Implements the methods of the `Wall` class representing wall objects.

### Algorithms

- **Guard movement algorithm**: The guards follow the player using a pathfinding algorithm to find the shortest path to the player's location.
the algorithm calculates the distance on the x-axis and y-axis and checks which one is closer to the player and moves the guard in that direction
- **Collision detection algorithm**: Detects collisions between game objects and handles interactions between them (using doubledispath).

### Deisgn

- **gameObject**: A base class for all the game objects in the game. 
the classes the inharets from this class are: Bombs, Door, Explosion, Freeze, Guard, IncreasingLife, Medkit, Player, RemovingGuard, Rock, Wall.
- **updateableObjects**: A base class for all the moving objects in the game.
the classes the inharets from this class are: Bombs, Guard, Player, Explosion.
- **staticObjects**: A base class for all the static objects in the game.
the classes the inharets from this class are: Door, Freeze, IncreasingLife, Medkit, RemovingGuard, Rock, Wall.



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
