//Noah Wyborny
//Banker Algorithm
//11/27/21

// Program is an implementation of the bankers algorithm,
// which takes an input file, and outputs to console
// if there is a safe state, using the inputs
// and what that safe sequence is

#include <array>
#include <iostream>
#include <fstream>
#include <vector>

/* Five Processes, P0 through P4.
# Three resource types, A B and C
# A has 10 instances
# B has 5 instances
C has 7 instances
*/

// Need to be able to read from input file
// Outputs safe sequence if system is safe

// Needs to answer question:
// Is system in a safe state? If yes, then what is the safe sequence

// File input format: file name: "*.txt"
// Each line will have 3 integers, separated by a space
// Each line will represent a process' allocation
// Ex 0 1 0

// Algorithm : find need for each process
// Need is found by subtracting allocation from process's max
// for each process
//  if need is less than or equal to work
//      work now becomes work plus allocation of the process
//      Add process to safe sequence
//  Else try next sequence

class Process {
public:
    Process(std::array<int, 3> alloc);

    int getID() { return processID_; }
    int getAlloc(int i) { return allocation_[i]; }
    std::array<int, 3> getMax() { return max_; };
    int getNeed(int i) { return need_[i]; }
    bool isLOE(std::array<int, 3> work) {
        for (int i = 0; i < 3; i++) {
            if (need_[i] > work[i]) return false;
        }
        return true;
    }
protected:
    static int id_;
private:
    std::array<int, 3> allocation_;
    std::array<int, 3> max_;
    std::array<int, 3> need_;
    int processID_;
};

class Safety {
public:
    bool isSafe() {
        for (int i = 0; i < 5; i++) {
            if (processes_[i] == false) return false;
        }
        return true;
    }
    void setBool(int n) {
        processes_[n] = true;
    }
    bool isPSafe(int p) { return processes_[p]; }
private:
    std::array<bool, 5> processes_ = {0};
};

int Process::id_ = 0;

Process::Process(std::array<int, 3> alloc) {
    processID_ = id_++;
    for (int i = 0; i < 3; i++) {
        allocation_[i] = alloc[i];
    }
    switch (processID_) {
    case 0:
        max_ = { 7,5,3 };
        break;
    case 1:
        max_ = { 3,2,2 };
        break;
    case 2:
        max_ = { 9,0,2 };
        break;
    case 3:
        max_ = { 2,2,2 };
        break;
    case 4:
        max_ = { 4,3,3 };
        break;
    }
    for (int j = 0; j < 3; j++) {
        need_[j] = max_[j] - allocation_[j];
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Input file is required." << std::endl;
        std::cerr << "       The main must be the first argument followed by ";
        std::cerr << "any other .txt file" << std::endl;
        return(1);
    }
    std::ifstream in(argv[1]);
    if (!in) { std::cerr << "Couldn't open file" << argv[1] << std::endl; exit(1); }
    std::cout << "File opened" << std::endl;

    std::vector<Process> processes;
    int one, two, three;
    while (in >> one >> two >> three) {
        std::array<int, 3> arr = { one, two, three };
        Process process(arr);
        processes.push_back(process);
    }

    // Intializing available resources
    std::array<int, 3> work = { 3, 3, 2 };
    //Doesnt let it run more than n times
    int exitCounter = 0;
    std::vector<int> safeSequence;
    int sequenceNum = 0;
    //Checks the safety of the whole system
    Safety safe;
    //While the system isnt safe, goes through the processes to see if one can be added
    while (!safe.isSafe()) {
        for (Process p : processes) {
            if (p.isLOE(work) && !safe.isPSafe(p.getID())) {
                std::array<int, 3> copy;
                for (int j = 0; j < 3; j++) {
                    copy[j] = p.getAlloc(j);
                }
                for (int i = 0; i < 3; i++) {
                    work[i] += copy[i];
                }
                safeSequence.push_back(p.getID());
                safe.setBool(p.getID());
            }
        }
        exitCounter++;
        if (exitCounter > processes.size()) break;
    }
    std::cout << "The system is: " << (safe.isSafe()?"Safe":"False") << "." << std::endl;
    if (safe.isSafe()) {
        std::cout << "The safe sequence is: ";
        for (int pID : safeSequence) {
            std::cout << "P" << pID << " ";
        }
    }
    exit(0);
}
