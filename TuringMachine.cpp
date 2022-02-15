 #include "TuringMachine.h"

 #include <iterator>

TuringMachine::TuringMachine()=default;

TuringMachine::TuringMachine(std::string file_name, 
                std::string input_string, 
                int input_string_length, 
                int transition_cap) {
    
    this->transition_cap = transition_cap;
    
    std::fill_n(this->tape, 2000000, '_');

    for (int i = 0;i < input_string_length;i++) {
        (this->tape)[i] = input_string.at(i);
    }

    std::ifstream file(file_name);

    if (file.is_open()) {
        std::string line;
        std::string token;

        while (std::getline(file, line)) {
            std::istringstream ss (line);
            ss >> token;

            if (token == "state") {
                State new_state = State(ss);

                if (new_state.isStart()) this->current_state = new_state.getState();

                states.insert(std::pair<int, State>(new_state.getState(), new_state));
            } else if (token == "transition") {
                ss >> token;

                states[std::stoi(token)].addTransition(ss);
            }
        }

        file.close();
    } else {
        std::cerr << "Unable to open file.\n";
    }
}
    
std::string TuringMachine::simulate() {
    std::string sim_status;
    std::string output = "";

    int transition_count = 0;
    int tape_position = 0;
    Transition transition_instr;

    while (!(this->states[current_state].isAccept()) || !(this->states[current_state].isReject())) {

        if (transition_count == this->transition_cap) {
            sim_status = "quit";
            break;
        }

        // read
        transition_instr = this->states[this->current_state].transition(
            this->tape[tape_position]
        );

        // write
        this->tape[tape_position] = transition_instr.write_value;

        char move_direction = transition_instr.move_direction;
        // move head
        if (move_direction == 'L') {
            tape_position--;
        } else if (move_direction == 'R') {
            tape_position++;
        }

        // transition
        this->current_state = this->states[transition_instr.transition_state].getState();

        if (this->states[this->current_state].isAccept()) {
            sim_status = "accept";
            break;
        } else if (this->states[this->current_state].isReject()) {
            sim_status = "reject";
            break;
        }

        transition_count++;
    }

    while (this->tape[tape_position] != '_') {
        output += this->tape[tape_position];
        tape_position++;
    }

    return output + " " + sim_status;
}