#pragma once

#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iostream>

#include "Transition.h"

class State {

    private:
        std::map<char, Transition> transitions;
        char state;
        bool is_start;
        bool is_accept;
        bool is_reject;

    public:
        //constructor 
        State();
        State(std::istringstream&);

        // transition functions
        void addTransition(std::istringstream&);
        std::string transition(char);

        // getter
        char getState() const;
        bool isStart() const;
        bool isAccept() const;
        bool isReject() const;
};
