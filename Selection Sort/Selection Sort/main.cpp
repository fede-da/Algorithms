//
//  main.cpp
//  Selection Sort
//
//  Created by Federico D'Armini on 10/03/22.
//



#include <iostream>
#include <vector>
#include "array_generator/array_generator.cpp"
#include "timer/timer.cpp"


template <typename T>
void solve(std::vector<T>& array){
    auto swapWithMin = [](std::vector<T> &array,int start)
        {
            T min = array[start];
            long size = array.size();
            int end = start;
            for(int i=start;i<size;i++){
                if (array[i]<min){
                    min=array[i];
                    end=i;
                }
            }
            T tmp = array[start];
            array[start] = array[end];
            array[end]=tmp;
        };
    long size = array.size();
    for(int i=0;i<size;i++)
        swapWithMin(array,i);
}

void readInput(int& elements,int& limit){
    while(elements<=0 || limit>elements){
        std::cout << "How many elements the array will sort? \n";
        std::cin >> elements;
        std::cout<<"How many elements of the array you want to get printed? (write the same number of above to print all, not more or the process will be restarted!)\n";
        std::cin>>limit;
        
    }
    return;
}

template <typename T>

void printNelements(int limit, std::vector<T> array){
    for(int i=0; i<limit;i++)
            std::cout<< array[i] << " ";
    std::cout<< std::endl<<std::endl;
}

int main(int argc, const char * argv[]) {
    int elements,limit;
    Timer t = Timer();
    readInput(elements, limit);
    ArrayGenerator generator = ArrayGenerator();
    std::vector<int> array = generator.getRandomArrayOfN(elements);
    std::cout<< "Printing unsorted array : ";
    printNelements<int>(limit, array);
    t.waitFor<int>(array, solve<int>);
    printNelements<int>(limit, array);
    return 0;
}
