#include <iostream>
#include <array>
#include <string>
#include "gnStack.h"

int main() {

    std::string note1="1234 367 1234";
    std::string note2="88907867";
    Parrots::remove_char_from_string(note1, ' ');
    Parrots::remove_char_from_string(note2, ' ');
    std::cout<<note1<<std::endl;
    //Parrots::add_largenumbers()
    Parrots::add_largenumbers(note1, note2);


"12343671234";
   "88907867";


    return 0;
}
