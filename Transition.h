#pragma once

#include <sstream>
#include <string>

class Transition {

    private:
        char transition_state;
        char write_value;
        char move_direction;

    public:
        // constructor
        Transition();
        Transition(std::istringstream&);
        
        friend std::ostream& operator<<(std::ostream&, const Transition&);
        operator std::string() const;

    friend class State;

};