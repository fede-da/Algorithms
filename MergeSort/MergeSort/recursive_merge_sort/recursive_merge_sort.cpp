//
//  recursive_merge_sort.cpp
//  MergeSort
//
//  Created by Federico D'Armini on 11/03/22.
//

#pragma once
#include "recursive_merge_sort.hpp"

#include <iostream>
#include <vector>
#include "../printer/printer.cpp"
#include <cmath>


class RecursiveMergeSort{
private:
    std::vector<int> array{};
    Printer printer;
    
    template <typename T>
    void merge(std::vector<T>& array,int p,int c, int r){
        std::vector<T> tmp {};
        int i=p;
        int j=c+1;
        while( i<=c && j<=r ){
            if(array[i]<=array[j]){
                tmp.push_back(array[i]);
                i++;
            }
            else{
                tmp.push_back(array[j]);
                j++;
            }
        }
        while(i<=c){
            tmp.push_back(array[i]);
            i++;
        }
        
        while(j<=r){
            tmp.push_back(array[j]);
            j++;
        }
        
        for(int k=p;k<=r;k++)
            array[k]=tmp[k-p];
        return;
    }
    
    void mergesort(int p, int r){
        if(p<r){
            int c = (p+r)>>1;
            this->mergesort( p, c);
            this->mergesort(c+1, r);
            merge(this->array, p, c,r);
        }
    }
    
public:
    std::vector<int>& getArray(){
        return this->array;
    }
    RecursiveMergeSort(std::vector<int>& input,Printer& newPrinter){
        this->array=input;
        this->printer=newPrinter;
    }
    
    void solveRecursive(){
        printer.printArray(this->getArray());
        this->mergesort(0, (int) this->array.size()-1);
        printer.printArray(this->getArray(),printer.getBegin(),printer.getEnd());
    }
    
    void solveIterative(){
        printer.printArray(this->getArray());
        this->iterativeMergeSort();
        printer.printArray(this->getArray(),printer.getBegin(),printer.getEnd());
    }
    
    void insertionSort(int start, int end){
        int i;
        int key;
        for (int j=start;j<end;j++){
            key=this->array[j];
            i=j-1;
            while(i>=0 && this->array[i]>key){
                this->array[i+1] = this->array[i];
                i--;
            }
            this->array[i+1] = key;
        }
    }
    
    void iterativeMergeSort(){
        unsigned int end = (unsigned int) this->array.size();
        int times = 0;
        while( std::pow(2, times) <= end )
            times++;
        while(times!=0){
            int i=0;
            unsigned int quot =(unsigned int) std::pow(2, times);
            unsigned int stack = ((unsigned int)((end+quot-1)/quot)) <<1;

            unsigned int j = stack;
            if(j>end)
                j=end;
            while(i<end){
                insertionSort(i, j);
                i=j;
                j=j+stack;
                if(j>end)
                    j=end;
            }
            times--;
        }
    }
};
