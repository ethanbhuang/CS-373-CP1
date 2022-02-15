#include "State.h"

State::State()=default;

State::State(std::istringstream& ss) {
    this->is_start = false;
    this->is_accept = false;
    this->is_reject = false;

    std::string token;
    ss >> token;

    this->state = token.at(0);
    ss >> token;

    if (token == std::string(1, this->state)) {
        return;
    }

    if (token == "start") {
        this->is_start = true;
    } else if (token == "accept") {
        this->is_accept = true;
    } else if (token == "reject") {
        this->is_reject = true;
    }
}

void State::addTransition(std::istringstream& ss) {
    char symbol_read;
    char transition_state;
    char write_value;
    char move_direction;

    ss >> symbol_read;
    ss >> transition_state;
    ss >> write_value;
    ss >> move_direction;

    std::cout << symbol_read
                    << transition_state
                    << write_value
                    << move_direction
                    << std::endl;

    Transition t = {transition_state, write_value, move_direction};

    this->transitions.insert(std::pair<char, Transition>(symbol_read, t));
}

Transition State::transition(char input) {
    return (this->transitions)[input];
}

char State::getState() const {
    return this->state;
}

bool State::isStart() const {
    return this->is_start;
}

bool State::isAccept() const {
    return this->is_accept;
}

bool State::isReject() const {
    return this->is_reject;
}