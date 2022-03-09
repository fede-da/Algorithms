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
    int elements=0;
    std::cout << "How many elements the array will sort? \n";
    std::cin >> elements;
    std::cout<<"Well then.\nGenerating array of length : " << elements << std::endl;
    std::vector<int> array = ag.getRandomArrayOfN(elements);
    Timer t = Timer();
    
    t.startTimer();
    solve(array);
    t.stopTimer();
    
    return 0;
}
