#include <iostream>
#include <array>
#include <string>
#include <algorithm>


int main() {

    std::string note1="1234 367 1234";
    auto removed_end =std::remove(note1.begin(), note1.end(),' ');
    note1.erase(removed_end, note1.end());
    std::cout<<note1<<std::endl;





    return 0;
}
