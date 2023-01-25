#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <random>


const std::map <std::string, int> cards{
    {"A"  ,  1},
    {"1"  ,  1},
    {"2"  ,  2},
    {"3"  ,  3},
    {"4"  ,  4},
    {"5"  ,  5},
    {"6"  ,  6},
    {"7"  ,  7},
    {"8"  ,  8},
    {"9"  ,  9},
    {"10" , 10},
    {"J"  , 11},
    {"Q"  , 12},
    {"K"  , 13},
    {"11" , 11},
    {"12" , 12},
    {"13" , 13},
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

    std::cout << "Nama file (tidak menggunakan .txt)\n>> ";
    std::getline(std::cin, name_file);

    std::ifstream file; 
    file.open("../test/" + name_file + ".txt");

    while (file.fail()){
        std::cout << "File tidak ditemukan,\nNama file\n>> ";
        std::cin >> name_file;

        file.open(name_file);
    }

    std::getline(file, *line);
}

void readTerminal(std::string *line){
    std::cout << "===================================================" << std::endl;
    std::cout << "<card1> <card2> <card3> <card4>\n";
    std::cout << "Masukkan nilai 4 kartu : \n>> ";

    // std::string input;
    std::getline (std::cin, *line);
    std::cin.clear();

    // std::cout << *line;

    // return 1;
}

bool parseInput(std::string line, std::vector<int> *vec){
    std::string temp;
    std::stringstream iss(line);

    // std::vector<std::string> val;

    // if (val.size() != 4){
    //     return false;
    // }
    try {
        // for (int i = 0; i < 4; i++){
        //     vec->push_back(cards.at(val.at(i)));
        //     std::cout << vec->at(cards.at(val.at(i))) << std::endl;
        // }
        while (iss >> temp) {
            vec->push_back(cards.at(temp));
            // std::cout << temp << std::endl;
        }
    }
    catch (std::out_of_range &err){
        vec->clear();
        return false;  
    }
    if (vec->size() != 4){
        vec->clear();
        return false;
    }
    else{
        return true;
    }
}

int randomGen(){
    return 1 + (rand() % 13);
}

std::vector<int> randomCard(){
    std::vector<int> vec;
    for(int i = 0; i < 4; i++){
        vec.push_back(randomGen());
    }
    return vec;
}

void inputCard(std::vector<int> *vec, std::string * word){
    int input;
    std::string line;
    srand((unsigned) time(NULL));
    // std::vector<int> vec;
    bool check = false;
    
    std::cout << "Tipe Input: " << std::endl;
    std::cout << " 0. Input Terminal" << std::endl;
    std::cout << " 1. Input File" << std::endl;
    std::cout << " 2. Input Random" << std::endl;

    std::cout << "Tipe input : ";
    std::cin >> input; 

    while (input < 0 || input > 2){
        std::cout << "===================================================" << std::endl;
        std::cout << "Masukan Salah, \nTipe input : ";
        std::cin >> input; 
    }
    while (!check){
        if (input == 0){
            std::cin.ignore();
            readTerminal(&line);
        }
        else if (input == 1){
            std::cin.ignore();
            readfile(&line);
        }

        if (input != 2){
            check = parseInput(line, vec);
        } 
        else{
            *vec = randomCard();
            line = invert_cards.at(vec->at(0)) + " " + invert_cards.at(vec->at(1)) + " " + invert_cards.at(vec->at(2)) + " " + invert_cards.at(vec->at(3));
            check = 1;
        }

        
        if (!check){
            // std::cout << "===================================================" << std::endl;
            std::cout << "\nMasukan Tidak Valid Silahkan Input Ulang (enter)\n";
            // vec->clear();
        }
        else {
            std::cout << "Input : " << line << std::endl;
            *word = line;
        }

        std::cin.clear();
        line.clear();
    }
}


void output(std::map<std::string, bool> sol_1, 
            std::map<std::string, bool> sol_2, 
            std::map<std::string, bool> sol_3, 
            std::map<std::string, bool> sol_4, std::string line)
    {
    int type;

    std::cout << "===================================================" << std::endl;
    std::cout << "\nApakah Ingin Menyimpan File (Yes = 1 | No = 0) : \n>> ";
    std::cin >> type;

    if (type){
        std::string name_output;
        
        std::cin.ignore();
        std::cout << "Nama File (tidak menggunakan .txt)(setelah itu double enter) \n>> ";
        std::getline(std::cin, name_output);

        std::ofstream out_file;
        
        out_file.open("../bin/" + name_output + ".txt");
        
        out_file << line + "\nJumlah Kemungkinan Solusi : " << sol_1.size() + sol_2.size() + sol_3.size() + sol_4.size() << "\n";
        std::map<std::string, bool>::iterator start;
        std::map<std::string, bool>::iterator end;
        for (int x = 0; x < 4; x++){
            switch(x){
                case 0:
                    start = sol_1.end();
                    end = sol_1.begin();
                    break;
                case 1:
                    start = sol_2.end();
                    end = sol_2.begin();
                    break;
                case 2:
                    start = sol_3.end();
                    end = sol_3.begin();
                    break;
                case 3:
                    start = sol_4.end();
                    end = sol_4.begin();
                    break;
            }
            
            while (start != end)
            {
                --start;
                out_file << start->first + "\n";
            }
        }
        // out_file.close();
    }
    else {
        std::cout << std::endl << "File Tidak Tersimpan" << std::endl;
    }

}

// int main(){
//     std::vector<int> vec;

//     inputCard(&vec);
    
//     return 0;
// }