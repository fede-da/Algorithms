//
//  printer.cpp
//  MergeSort
//
//  Created by Federico D'Armini on 11/03/22.
//

#pragma once
#include "printer.hpp"
#include <iostream>
#include <vector>

class Printer{
    
private:
    int elements=0;
    int begin=0;
    int end=0;
    
public :
    
    int getSize(){
        return this->elements;
    }
    int getBegin(){
        return this->begin;
    }
    int getEnd(){
        return this->end;
    }
    
    Printer(){}
    
    template <typename T>
    const void printArray(std::vector<T> &array){
        std::cout<<"Printing array : ";
        for(T t : array)
            std::cout<<t<<" ";
        std::cout<<std::endl;
    }
    
    template <typename T>
    void printArray(std::vector<T>& array,int left,int right){
        std::cout<<"Printing array from index "<<left<<" to "<<right<<" :\n";
        int sum = right+left;
        for(int i=left;i<sum;i++)
            std::cout<<array[i]<<" ";
        std::cout<<std::endl;
    }
    
    template <typename T>
    void printArrayReversed(std::vector<T>& array){
        std::cout<<"Printing array : ";
        int size = (int) array.size();
        for(int i=size-1;i>=0;i--)
            std::cout<<array[i]<<" ";
        std::cout<<std::endl;
    }
    
    template <typename T>
    void printArrayReversed(std::vector<T>& array,int left,int right){
        std::cout<<"Printing reversed array from index "<<left<<" to "<<right<<" :\n";
        for(int i=right;i>=left;i--)
            std::cout<<array[i]<<" ";
        std::cout<<std::endl;
    }
    
    
    void readInput(){
        while( elements<=0 || end>elements || begin>end ){
            std::cout << "How many elements the array will sort? \n";
            std::cin >> elements;
            std::cout<<"How many elements of the array you want to get printed?\n";
            std::cin>>end;
            std::cout<<"Starting from index? (0 for default)\n";
            std::cin>>begin;
        }
        return;
    }
    
};
