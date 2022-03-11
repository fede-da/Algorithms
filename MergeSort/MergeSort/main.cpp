//
//  main.cpp
//  MergeSort
//
//  Created by Federico D'Armini on 11/03/22.
//

#include <iostream>
#include <vector>
#include "array_generator/array_generator.cpp"



template <typename T>
void merge(std::vector<T>& array,int p,int c, int r){
    std::cout<<" Called merge\n";
    std::vector<T> tmp {};
    int i=1;
    int j=c+1;
    while( i<=c && j<=r ){
        if(array[i]<array[j]){
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
    array=tmp;
    return;
}

template <typename T>
void mergesort(std::vector<T>&array,int p, int r){
    
    if(p<r){
        std::cout<<" Called mergesort p : "<<p<<" , r : "<<r<<" \n";
        int c = (p+r)>>1;
        mergesort(array, p, c);
        mergesort(array, c, r);
        merge(array, p, c,r);
    }
}

template <typename T>
void printArray(std::vector<T> array){
    for(T t : array)
        std::cout<<t<<" ";
    std::cout<<std::endl;
}

int main(int argc, const char * argv[]) {
    ArrayGenerator generator = ArrayGenerator();
    std::vector<int> array {5,6,7,1,2,3,4};
    printArray(array);
    mergesort(array, 1, (int)array.size());
//    merge(array, 0,3,(int) array.size());
    printArray(array);
    return 0;
}
