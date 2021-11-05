# number-guessing-game
Number guessing game written on C++ by Barış Şahin for CS-TECH interview exam.

Guide to compile on ubuntu

1- Install Build-essential Package 

Open up a terminal on Ubuntu Linux and install the build-essential package by typing the following command in the terminal

sudo apt-get install build-essential

These are the important library files for compiling C/C++ programs on linux.

2- Create a seperate folder to hold the programs

sudo mkdir -p CPP/example/

3- Change your PATH to the working directory.

cd CPP/example/

4- Save your code files in the created directory.

5- Compile your program using terminal.

g++ -c temp_name1.cpp temp_name2.cpp (change the name of files according to your files)
g++ -o insert_your_executable_file_name_Here temp_name1.o temp_name2.o

6- Run

./insert_your_executable_file_name_Here

--------------------------------------------------------------

Or you can use your C/C++ IDE directly.
