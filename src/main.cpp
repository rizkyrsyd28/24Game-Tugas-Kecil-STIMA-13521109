#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(){
    std::string str = "1333222";

    for (int i = 0; i < str.size(); i++){
        std::cout << str.at(i) << std::endl;
    }
}