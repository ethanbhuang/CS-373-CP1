// #include "Transition.h"

// Transition::Transition()=default;

// Transition::Transition(std::istringstream& ss) {
//     ss >> this->transition_state;
//     ss >> this->write_value;
//     ss >> this->move_direction;
// }

// std::ostream& operator<<(std::ostream& ss, const Transition& t) {
//     return ss << t.transition_state << " "
//             << t.write_value << " "
//             << t.move_direction;
// }

// Transition::operator std::string() const {
//     return std::string()
//                     + this->transition_state
//                     + this->write_value
//                     + this->move_direction;
// }