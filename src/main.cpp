#include "24game.cpp"

int main(){
    std::vector<int> num_vec;
    std::string word;

    while (true){
        std::cout << "\n===================================================" << std::endl;

        inputCard(&num_vec, &word);

        preprocess(num_vec);
        
        solve(num_vec);
        
        output(sol_1, sol_2, sol_3, sol_4, word);

        std::cin.ignore();
        
        num_vec.clear();
        expr_1.clear();
        expr_2.clear();
        expr_3.clear();

        sol_1.clear();
        sol_2.clear();
        sol_3.clear();
        sol_4.clear();
        word.clear();
    }

}