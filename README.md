# banker
 ### Implementation of the Banker's Algorithm in C++
 
 ### Installation
 In order to compile, g++ must be installed on the chosen environment. The code is intended to be run on a linux based system. Before trying to install, it is recommended that it is ensure that g++ isn't already installed on the system. This can be done primarily by running the command 
 > g++ -v
 
 Installation can be done by running the following command for Debian or Ubuntu:
>sudo apt install g++

For any other Linux based systems, look it up yourself.

### How to clone
In order to clone the repo for use, use this command:
>gh repo clone WolfWindOW/bankerAlgo

### Compilation
Compilation can be completed by running the following command with the "Banker.cpp" file in the working directory.
>g++ Banker.cpp -o Banker

If successful, one additional file will be created, called "Banker".

### Running the program
Before running the program, an input file must be created. The format is an 3 integers per line, with a space separating them, for a total of 5 lines. A sample has been provided.
In order to run the program, the following command must be used, provided that the given text file is being used. Otherwise substitute for whatever the name of your text file is.
>./Banker input.txt
 
 ### Output
 The program will run through the given file, taking the integers given, and use them to create processes with a previously established maximum resource amount. Then it will compare how many additional resources a program will need in order to reach the max. If that number can be provided, it will, and the resources will then be released back to the system, until either no more programs are waiting for resources, or the system cannot fufill its requests. If it is successful in completing the processes, then a safe state will be achieved and a safe sequence will be output. Otherwise, the program will output that the system is not safe.
 
 ![Banker Algorithm Output](https://github.com/WolfWindOW/bankerAlgo/blob/main/output.png)
 
 ### Acknowledgement
 It is possible to do this program using primarily vectors, which would allow for a greater variability in the number of processes to be computed. Additionally, it should be possible to implement the 0-1 Knapsack problem into the algorithm, such that each possible beginning process can be separately evaluated, outputting a range of possible safe sequences.
