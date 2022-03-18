//
//  main.cpp
//  StringComparison
//
//  Created by Federico D'Armini on 16/03/22.
//

#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <regex>
#include <string>
#include "timer/timer.cpp"

bool isValid(std::vector<char> e){
    int size = (int) e.size();
    bool uppercase = false;
    bool charS = false;
    bool isNumber = false;
    int letter;
    for (int i = 0; i < size; i++) {
        letter = e[i];
        if (!uppercase & ((letter >= 65) & (letter <= 90))) {
            uppercase = true;
        } else if (!isNumber & ((letter >= 48) & (letter <= 57))) {
            isNumber = true;
        } else if (!charS &
            (((letter >= 33) & (letter <= 47)) |
                ((letter >= 58) & (letter <= 64)) |
                ((letter >= 91) & (letter <= 96)) |
                ((letter >= 123) & (letter <= 126)))) {
            charS = true;
        }
        if (uppercase & charS & isNumber) return true;
    }
    return false;
}

bool isValidRegExpr(std::string& string){
    if(!std::regex_search(string, std::regex("[A-Z]"))) return false;
    if(!std::regex_search(string,std::regex("[0-9]"))) return false;
    if(!std::regex_search(string,std::regex("[!@#$%^&*(),.?':{}|<>]"))) return false;
    return true;
}

template <typename T>
std::vector<T> createString(int size){
    // 33,126  distribution in range
    std::vector<T> res (size, 32);
    res.push_back('A');
    res.push_back('4');
    res.push_back('$');
    return res;
}
template <typename T>
void printArray(std::vector<T>& array){
    std::cout<< "Printing vector : ";
    for(T t : array)
        std::cout<<t<< " ";
    std::cout<< '\n';
}


int main(int argc, const char * argv[]) {
    std::vector<char> string = createString<char>(20);
    std::string regString {};
    for(char c : string)
        regString.push_back(c);
    Timer t = Timer();
    isValid(string);
    t.printTime();
    t.reset();
    isValidRegExpr(regString);
    t.printTime();
    return 0;
}
