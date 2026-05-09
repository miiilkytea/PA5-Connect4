# PA5-Connect4
Authors: Samantha English & Isabelle Schinzing
Date: 05/08/2026

## How to Compile
1. To compile, make sure all files are copied over to your IDE
2. Open a new terminal and make sure you are in the folder with all the copied files
3. Type "make" into terminal and then enter
4. All respective object and final executable files should be created

## How to Run Program
1. Make sure all code is compiled and object and executable files are created.
2. In the terminal type "./

## Overview
The game you are about to play is called Connect 4!
You and an opponent will compete to get 4 in a row faster.
The 4 in a row can be vertical, horizontal, or diagonal, whichever comes first.

To set up the game, type "make"  into the terminal to compile the code for the game.
To start the game type "./game" into the terminal to begin the game.

## Class Structure & Program Design Breakdown
We have 5 classes in this game that work together to allow for a seamless user experience.

### Player
The Player class is the parent class of the derived Human & Computer classes. This class stores all the player attributes and is an Abstract Base Class.

### Human
The human class is the child of the parent class, Player. This is the type of class that controls human player behavior.

### Computer
The computer class is the child of the parent class, Player. This is the type of class that controls non-human player behavior.

### Board
The Board class is the class the stores, tracks, and updates all edits to the board. This has an aggregative relationship with the Game and Player classes.

### Game
The Game class is the class that controls the overall game behavior and flow. This has an aggregative relationship with Player and Board classes.

### File Manager
The File Manager files helps save and load up a selected player's information that is stored in the "playerData.csv" file.


