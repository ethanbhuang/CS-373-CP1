#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstring>

#include "State.h"

class TuringMachine {

    private:
        char tape[2000000];
        char current_state;
        int transition_cap;
        std::map<char, State> states;


    public:
        // constructor
        TuringMachine();
        TuringMachine(std::string, std::string, int, int);
        
        std::string simulate();

};