//
//  recursive_merge_sort.cpp
//  MergeSort
//
//  Created by Federico D'Armini on 11/03/22.
//

#include "recursive_merge_sort.hpp"
#include <iostream>
#include <vector>


class RecursiveMergeSort{
private:
    std::vector<int> array{};
    
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
    
public:
    RecursiveMergeSort(std::vector<int>& input){
        this->array=input;
    }
    
    void mergesort(int p, int r){
        if(p<r){
            int c = (p+r)>>1;
            this->mergesort( p, c);
            this->mergesort(c+1, r);
            merge(this->array, p, c,r);
        }
    }

    std::vector<int>& getArray(){
        return this->array;
    }
    
};
