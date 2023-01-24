#include "iosystem.cpp"

std::vector<bool> defconfig = {false, false, false, false};
std::vector<char> operation = {'+', '*', '-', '/'};

typedef struct {
    float               val;
    int                 kombinasi;
    std::vector<bool>   config;
    std::string         text;
} info; 

std::vector<info> expr_1;
std::vector<info> expr_2;
std::vector<info> expr_3;

std::map<std::string, float> expr_4;

void doubleConfig(std::vector<bool> vec1, std::vector<bool> vec2, std::vector<bool> *res){
    *res = vec1;
    for(int i = 0; i < 4; i++){
        if (!vec2.at(i)) continue;
        res->at(i) = true;
    }
}

bool falseConfig(std::vector<bool> vec1, std::vector<bool> vec2){
    for (int i = 0; i < 4; i++){
        if (vec1.at(i) && vec2.at(i)){
            return true;
        }
    }
    return false;
}

void preprocess(std::vector<int> vec){
    int _kombinasi;
    
    // Kombinasi 1
    _kombinasi = 1;
    for (int i = 0; i < vec.size(); i++){
        std::vector<bool> _config = defconfig;
        _config.at(i) = true; 

        std::string _text = invert_cards.at(vec.at(i));
        info _info = {(float)vec.at(i),_kombinasi, _config, _text};

        expr_1.push_back(_info);

    }

    // for (int i = 0; i < expr_1.size(); i++){
    //     std::cout << expr_1.at(i).text << " = " << expr_1.at(i).val << std::endl; 
    // }


    // Kombinasi 2
    _kombinasi = 2;

    // Add & Times
    for (int op = 0; op < 2 ; op++){
        for (int i = 0; i < expr_1.size(); i++){
            for (int j = 0; j < expr_1.size(); j++){
                if(i==j) continue;
                std::vector<bool> _config = defconfig;
                _config.at(i) = true;
                _config.at(j) = true;

                float _val; 
                if (operation.at(op) == '+'){
                    _val = expr_1.at(i).val + expr_1.at(j).val;
                }
                else if (operation.at(op) == '*'){
                    _val = expr_1.at(i).val * expr_1.at(j).val;

                }
                std::string _text = "(" + expr_1.at(i).text + " " + operation.at(op)  + " " + expr_1.at(j).text + ")";
                
                
                info _info = {_val, _kombinasi, _config, _text};

                
                expr_2.push_back(_info);

            }
        }
    }


    for (int op = 2; op < 4 ; op++){
        for (int i = 0; i < expr_1.size(); i++){
            for (int j = 0; j < expr_1.size(); j++){
                if(i==j) continue;
                std::vector<bool> _config = defconfig;
                _config.at(i) = true;
                _config.at(j) = true;

                float _val; 
                if (operation.at(op) == '-'){
                    _val = expr_1.at(i).val - expr_1.at(j).val;
                }
                else if (operation.at(op) == '/'){
                    _val = expr_1.at(i).val / expr_1.at(j).val;

                }
                std::string _text = "(" + expr_1.at(i).text + " " + operation.at(op) + " " + expr_1.at(j).text + ")";
                
                
                info _info = {_val, _kombinasi, _config, _text};

                
                expr_2.push_back(_info);

            }
        }
    }
    // for (int i = 0; i < expr_2.size(); i++){
    //     std::cout << expr_2.at(i).text << " = " << expr_2.at(i).val << std::endl; 
    // }

    // kombinasi 3 
    for (int op = 0; op < 2 ; op++){
        for (int i = 0; i < expr_1.size(); i++){
            for (int j = 0; j < expr_2.size(); j++){
                if(falseConfig(expr_1.at(i).config, expr_2.at(j).config))continue;

                std::vector<bool> _config = expr_2.at(j).config;
                _config.at(i) = true;

                float _val; 
                if (operation.at(op) == '+'){
                    _val = expr_1.at(i).val + expr_2.at(j).val;
                }
                else if (operation.at(op) == '*'){
                    _val = expr_1.at(i).val * expr_2.at(j).val;

                }
                std::string _text_1 = "(" + expr_1.at(i).text + " " + operation.at(op) + " " + expr_2.at(j).text + ")";
                std::string _text_2 = "(" + expr_2.at(j).text + " " + operation.at(op) + " " + expr_1.at(i).text + ")";
                
                info _info_1 = {_val, _kombinasi, _config, _text_1};
                info _info_2 = {_val, _kombinasi, _config, _text_2};
                
                expr_3.push_back(_info_1);
                expr_3.push_back(_info_2);

            }
        }
    }


    // kombinasi 3 
    for (int op = 2; op < 4 ; op++){
        for (int i = 0; i < expr_1.size(); i++){
            for (int j = 0; j < expr_2.size(); j++){
                if(falseConfig(expr_1.at(i).config, expr_2.at(j).config))continue;

                std::vector<bool> _config = expr_2.at(j).config;
                _config.at(i) = true;

                float _val_1, _val_2; 
                if (operation.at(op) == '-'){
                    _val_1 = expr_1.at(i).val - expr_2.at(j).val;
                    _val_2 = expr_2.at(j).val - expr_1.at(i).val;
                }
                else if (operation.at(op) == '/'){
                    _val_1 = expr_1.at(i).val / expr_2.at(j).val;
                    _val_2 = expr_2.at(j).val / expr_1.at(i).val;

                }
                std::string _text_1 = "(" + expr_1.at(i).text + " " + operation.at(op) + " " + expr_2.at(j).text + ")";
                std::string _text_2 = "(" + expr_2.at(j).text + " " + operation.at(op) + " " + expr_1.at(i).text + ")";
                
                info _info_1 = {_val_1, _kombinasi, _config, _text_1};
                info _info_2 = {_val_2, _kombinasi, _config, _text_2};
                
                expr_3.push_back(_info_1);
                expr_3.push_back(_info_2);

            }
        }
    }
    // for (int i = 0; i < expr_3.size(); i++){
    //     std::cout << expr_3.at(i).text << " = " << expr_3.at(i).val << std::endl; 
    // }
}

void solve(){
    // kombinasi 4
    // 2 dengan 2 
    // int _kombinasi = 4;

    for (int op = 0; op < 2; op++){
        for (int i = 0; i < expr_2.size(); i++){
            for(int j = i+1; j < expr_2.size(); j++){
                if(falseConfig(expr_2.at(i).config, expr_2.at(j).config))continue;
                
                // std::vector<bool> _config;
                // doubleConfig(expr_2.at(i).config, expr_2.at(j).config, &_config);

                float _val; 
                if (operation.at(op) == '+'){
                    _val = expr_2.at(i).val + expr_2.at(j).val;
                }
                else if (operation.at(op) == '*'){
                    _val = expr_2.at(i).val * expr_2.at(j).val;
                }
                std::string _text_1 = expr_2.at(i).text + " " + operation.at(op) + " " + expr_2.at(j).text;
                std::string _text_2 = expr_2.at(j).text + " " + operation.at(op) + " " + expr_2.at(i).text;
                
                
                // info _info_1 = {_val, _kombinasi, _config, _text_1};
                // info _info_2 = {_val, _kombinasi, _config, _text_2};
                
                if (_val == 24){
                    expr_4[_text_1] = _val;
                    expr_4[_text_2] = _val;
                    // expr_4.push_back(_info_1);
                    // expr_4.push_back(_info_2);
                }
            }
        }
    }

    // MARK
    for (int op = 2; op < 4; op++){
        for (int i = 0; i < expr_2.size(); i++){
            for(int j = 0; j < expr_2.size(); j++){
                if(falseConfig(expr_2.at(i).config, expr_2.at(j).config))continue;
                
                // std::vector<bool> _config;
                // doubleConfig(expr_2.at(i).config, expr_2.at(j).config, &_config);

                float _val_1, _val_2; 
                if (operation.at(op) == '-'){
                    _val_1 = expr_2.at(i).val - expr_2.at(j).val;
                    _val_2 = expr_2.at(j).val - expr_2.at(i).val;
                }
                else if (operation.at(op) == '/'){
                    _val_1 = expr_2.at(i).val / expr_2.at(j).val;
                    _val_2 = expr_2.at(j).val / expr_2.at(i).val;
                }
                std::string _text_1 = expr_2.at(i).text + " " + operation.at(op) + " " + expr_2.at(j).text;
                std::string _text_2 = expr_2.at(j).text + " " + operation.at(op) + " " + expr_2.at(i).text;
                
                // info _info_1 = {_val_1, _kombinasi, _config, _text_1};
                // info _info_2 = {_val_2, _kombinasi, _config, _text_2};
                
                // if (_val_1 == 24) expr_4.push_back(_info_1);
                // if (_val_2 == 24) expr_4.push_back(_info_2);
                if (_val_1 == 24) expr_4[_text_1] = _val_1;
                if (_val_2 == 24) expr_4[_text_2] = _val_2;
            }
        }
    }

    
    // 1 dengan 3 / 3 dengan 1

    for (int op = 0; op < 2; op++){
        for (int i = 0; i < expr_1.size(); i++){
            for(int j = 0; j < expr_3.size(); j++){
                if(falseConfig(expr_1.at(i).config, expr_3.at(j).config))continue;
                
                // std::vector<bool> _config;
                // doubleConfig(expr_1.at(i).config, expr_3.at(j).config, &_config);

                float _val; 
                if (operation.at(op) == '+'){
                    _val = expr_1.at(i).val + expr_3.at(j).val;
                }
                else if (operation.at(op) == '*'){
                    _val = expr_1.at(i).val * expr_3.at(j).val;
                }
                std::string _text_1 = expr_1.at(i).text + " " + operation.at(op) + " " + expr_3.at(j).text;
                std::string _text_2 = expr_3.at(j).text + " " + operation.at(op) + " " + expr_1.at(i).text;
                
                // info _info_1 = {_val, _kombinasi, _config, _text_1};
                // info _info_2 = {_val, _kombinasi, _config, _text_2};
                
                if (_val == 24) {
                    // expr_4.push_back(_info_1);
                    // expr_4.push_back(_info_2);
                    expr_4[_text_1] = _val;
                    expr_4[_text_2] = _val;
                }
            }
        }
    }

    for (int op = 2; op < 4; op++){
        for (int i = 0; i < expr_1.size(); i++){
            for(int j = 0; j < expr_3.size(); j++){
                if(falseConfig(expr_1.at(i).config, expr_3.at(j).config))continue;
                
                // std::vector<bool> _config;
                // doubleConfig(expr_1.at(i).config, expr_3.at(j).config, &_config);

                float _val_1, _val_2; 
                if (operation.at(op) == '-'){
                    _val_1 = expr_1.at(i).val - expr_3.at(j).val;
                    _val_2 = expr_3.at(j).val - expr_1.at(i).val;
                }
                else if (operation.at(op) == '/'){
                    _val_1 = expr_1.at(i).val / expr_3.at(j).val;
                    _val_2 = expr_3.at(j).val / expr_3.at(i).val;
                }
                std::string _text_1 = expr_1.at(i).text + " " + operation.at(op) + " " + expr_3.at(j).text;
                std::string _text_2 = expr_3.at(j).text + " " + operation.at(op) + " " + expr_1.at(i).text;
                
                // info _info_1 = {_val_1, _kombinasi, _config, _text_1};
                // info _info_2 = {_val_2, _kombinasi, _config, _text_2};
                
                // if (_val_1 == 24) expr_4.push_back(_info_1);
                // if (_val_2 == 24) expr_4.push_back(_info_2);
                if (_val_1 == 24) expr_4[_text_1] = _val_1;
                if (_val_2 == 24) expr_4[_text_2] = _val_2;
            }
        }
    }


    std::cout << "number of solution : " << expr_4.size() << std::endl;
    
    std::map<std::string, float>::iterator it = expr_4.end();

    while (it != expr_4.begin())
    {
        --it;
        std::cout << it->first << " = " << it->second << std::endl;
    }
}


int main(){
    std::vector<int> vec = {1, 8, 9, 12};

    preprocess(vec);
    solve();
}