// ./main insertDollarSignAndAppendPoundSign.txt 0110 9

#include <iostream>
#include <fstream>
#include <string>

#include "TuringMachine.h"

int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cerr << "Invalid number of arguments.\n";
        return 0;
    }
    
    std::string file_name = argv[1];
    std::string input_string = argv[2];
    int input_string_length = input_string.length();
    int max_args = std::stoi(argv[3]);

    TuringMachine tm = TuringMachine(file_name, 
                    input_string, input_string_length, 
                    max_args);
    std::cout << tm.simulate() << std::endl;

    return 0;
}