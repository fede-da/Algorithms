//
//  array_generator.cpp
//  Insertion Sort
//
//  Created by Federico D'Armini on 09/03/22.
//
#include <iostream>
#include <vector>
#include <random>

#include "array_generator.hpp"


class ArrayGenerator{
    std::vector<int> array{};
public:
    ArrayGenerator(){};
    
    std::vector<int> getRandomArrayOfN(int size){
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, size<<3);
        for(int i=size;i>=0;i--){
            int res =dist(mt);
            array.push_back(res);
        }
        return array;
    }
    
};
