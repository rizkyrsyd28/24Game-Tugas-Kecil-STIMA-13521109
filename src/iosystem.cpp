#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

const std::map <std::string, int> cards{
    {"A" ,  1},
    {"2" ,  2},
    {"3" ,  3},
    {"4" ,  4},
    {"5" ,  5},
    {"6" ,  6},
    {"7" ,  7},
    {"8" ,  8},
    {"9" ,  9},
    {"10", 10},
    {"J" , 11},
    {"Q" , 12},
    {"K" , 13},
};

const std::map <int, std::string> invert_cards{
    {1  ,   "A"},
    {2  ,   "2"},
    {3  ,   "3"},
    {4  ,   "4"},
    {5  ,   "5"},
    {6  ,   "6"},
    {7  ,   "7"}, 
    {8  ,   "8"},
    {9  ,   "9"},
    {10 ,   "10"},
    {11 ,   "J"},
    {12 ,   "Q"},
    {13 ,   "K"},
};

void readfile(std::string *line){
    std::string name_file;

    std::cout << "Nama file : ";
    std::cin >> name_file;

    std::ifstream file; 
    file.open(name_file);

    while (file.fail()){
        std::cout << "File tidak ditemukan,\nNama file : ";
        std::cin >> name_file;

        file.open(name_file);
    }

    std::getline(file, *line);
}

void readTerminal(std::string *line){
    std::cout << "<card1> <card2> <card3> <card4>\n";
    std::cout << "Masukkan nilai 4 kartu : ";

    std::string a; 
    std::getline(std::cin, a);

    std::cout << a;
}

std::vector<int> parseInput(std::string line){
    std::vector<int> vec;
    std::string temp;

    std::stringstream iss(line);

    while (iss >> temp) vec.push_back(cards.at(temp));

    return vec;
}

void inputCard(){
    int input;
    std::string line;
    
    std::cout << "Tipe input : ";
    std::cin >> input; 

    while (input < 0 || input > 1){
        std::cout << "Tipe input : ";
        std::cin >> input; 
    }

    if (input == 0){
        readTerminal(&line);
    }
    else if (input == 1){
        readfile(&line);
    }

    std::vector<int> in = parseInput(line);

}

// int main(){
//     // inputCard();
    
//     return 0;
// }