# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.
# New Features

This version of the snake game adds three different types of food:
  - Basic food (yellow): This is a basic food item. Eating one of these increments speed by 0.02, increase the size of the snake by one and adds one to the score
  - Super food (green):  Eating one of these increments speed by 0.04 (twice as fast as eating basic food!), increase the size of the snake by two and adds two to the score
  - Poison food (red): Eating one of these causes the snake to pause for two seconds, then docks one point from the score.

In addition to the arrow keys, the snake head can be moved with 'w,s,a,d' keys. And hitting the escape button ends the program.
The user is asked to type their name into the game via cli (doing this in SDL is tricky)
The random number generation for the placement of the food is placed in its own class. The food classes all inherit from the AbstractFood class (which isn't truly abstract). All inheritef class override 'CheckForFood'
I also used 'SDL_ShowSimpleMessageBox' to print out the score when the game ends (but it may be buggy depending on SDL version used). The application also writes the player name, score and size to a log file

# Rubric Points

## Loops, Functions, I/O
 
 - A variety of control structures are added to the project.The project code is clearly organized into functions.
 - The project uses vectors and uses constant variables.
 - The project reads data from an external file or writes data to a file as part of the necessary operation of the program.

 ## Object Oriented Programming 
 - Classes are organized with attributes to hold data and methods to perform tasks. All class data members are explicitly specified as public, protected, or private. Member data that is subject to an invariant is hidden from the user and accessed via member methods.

 - All class members that are set to argument values are initialized through member initialization lists.
 - One function is overloaded with different signatures for the same function name. e.g. AbstractFood Constructor

 - Inheritance hierarchies are logical. One member function in an inherited class overrides a virtual base class member function. (e.g. AbstractFood -> BasicFood)

 ## Memory Management 

 - At least two variables are defined as references, or two functions use pass-by-reference in the project code. (e.g. AbstractFood::CheckForFood & AbstractFood::PlaceFoodItem)

- At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor. e.g. food color variables _r, _g, _b & _o in AbstractFood

- The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. e.g. shared_ptr
The project code is clearly organized into functions and classes. e,g 'std::vector<std::shared_ptr<AbstractFood>> foods' in Game class.

## Concurrency 

- A promise and future is used to pass data from a worker thread to a parent thread in the project code
- A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code.



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
