# Tictactoe
```
[===== T I C - T A C - T O E =====]

          [1] [START GAME]
             [2] [EXIT]

* THIS A CONSOLE GAME, use [NUMPAD]
and press [ENTER] to register
input...
```
A very basic and simple program of tictactoe minigame with a command-line interface.
Build with C++ and MakeFile

# Purposes:
Personal learning as well as entertaining.

# Requirements:
Operation system (OS): Windows, Unix-based system.
C++ Compiler: C++11 minimum

# Installations and Setups:
Download the package containing the source code and the Makefile.

* Make sure to install and add Make, C++ compiler (and modify it in the config variable section of the Makefile),... and add them to PATH. 

Go to the folder containing the MakeFile, open the console, and run this command:
```
make build
```
* If using mingw32-make then just replace "make" with "mingw32-make"
to create the initial program for the first time. The program will be shown in the following hierarchy:
```
Tictactoe
+--> build
     +--> program.exe <---- The program located here
+--> src
     +--> entrypoint.cpp
     +--> logic.cpp
     +--> logic.hpp
     +--> visualizer.cpp
     +--> visualizer.hpp
+--> LICENSE
+--> Makefile
+--> README.md
```
Then simply run the program.exe file.
You can later change the source code and update the program by:
```
make rebuild
```
after creating the initial program. There are also 2 other commands that kinda helpful:
```
make clean
make run
```

# Personal Ratings:
* Difficulty: 2.3
Much harder than creating a fullly functional simple full-stack webpage (?).
* Performance: 8.4
There are some optimization techniques are used to make this program better: framebuffer, modular code based, smart data type (reduce memory leak), ...
* Functionality: 6
Functioning the game as intended.
* Learning: 3.5
Learning C++ in this project is quite good, for organization with OOP and mid-level optimization.
* Entertaining: 4
See the project building up is entertaining.