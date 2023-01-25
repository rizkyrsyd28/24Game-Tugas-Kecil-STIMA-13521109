#include "24game.cpp"
#include <chrono>

int main(){
    std::vector<int> num_vec;
    std::string word;
    std::cout << R"(
.------..------..------..------..------.     .------..------..------..------..------.
|B.--. ||U.--. ||K.--. ||A.--. ||N.--. |.-.  |P.--. ||O.--. ||K.--. ||E.--. ||R.--. |
| :(): || (\/) || :/\: || (\/) || :(): ((2)) | :/\: || :/\: || :/\: || (\/) || :(): |
| ()() || :\/: || :\/: || :\/: || ()() |'-.-.| (__) || :\/: || :\/: || :\/: || ()() |
| '--'B|| '--'U|| '--'K|| '--'A|| '--'N| ((4)) '--'P|| '--'O|| '--'K|| '--'E|| '--'R|
`------'`------'`------'`------'`------'  '-'`------'`------'`------'`------'`------'
)" << std::endl << "\"24 SOLVER BUKAN POKER\"" << std::endl;

    while (true){
        std::cout << "\n===================================================" << std::endl;

        inputCard(&num_vec, &word);
        
        auto start = std::chrono::high_resolution_clock::now();
        preprocess(num_vec);
        
        solve(num_vec);
        auto end = std::chrono::high_resolution_clock::now();

        auto runtime = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);
        std::cout << "\nruntime : " << runtime.count() << "ms" << std::endl;
        
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