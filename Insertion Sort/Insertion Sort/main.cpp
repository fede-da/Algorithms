//
//  main.cpp
//  Insertion Sort
//
//  Created by Federico D'Armini on 08/03/22.
//

#include <iostream>
#include <vector>
#include "array_generator/array_generator.cpp"
#include "timer/Timer.cpp"

void readInput(int& elements,int& limit){
    while(elements<=0 || limit>elements){
        std::cout << "How many elements the array will sort? \n";
        std::cin >> elements;
        std::cout<<"How many elements of the array you want to get printed? (write the same number of above to print all, not more or the process will be restarted!)\n";
        std::cin>>limit;
        
    }
    return;
}

void solve(std::vector<int>& array){
    std::cout << "Solve with insertion sort \n";
    long size = array.size();
    int i;
    int key;
    for (int j=1;j<size;j++){
        key=array[j];
        i=j-1;
        while(i>=0 && array[i]>key){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}

int main(int argc, const char * argv[]) {
    ArrayGenerator ag = ArrayGenerator();
    int elements = 0;
    int limit = 1;
    
    readInput(elements,limit);
    
    std::cout<<"Well then.\nGenerating array of length : " << elements << std::endl<<std::endl;
    std::vector<int> array = ag.getRandomArrayOfN(elements);
    std::cout<<"Print asked :\n";
    for(int i=0; i<limit;i++)
        std::cout<< array[i] << " ";
    std::cout<< std::endl<<std::endl;

    Timer t = Timer();
    
    t.waitFor(array, solve );
    
    std::cout<<"Array sorted :\n";
    for(int i=0; i<limit;i++)
        std::cout<< array[i] << " ";
    std::cout<< std::endl<<std::endl;
    
    return 0;
}
