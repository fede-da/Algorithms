//
//  main.cpp
//  BubbleSort
//
//  Created by Federico D'Armini on 14/03/22.
//

#include <iostream>
#include "array_generator/array_generator.cpp"
#include "printer/printer.cpp"
#include "timer/timer.cpp"

template <typename T>
void solve(std::vector<T> &array){
    bool scambio = true;
    int size= (int) array.size();
    T tmp;
    while (scambio){
        scambio=false;
        for(int i=1;i<size;i++){
            if(array[i-1] > array[i]){
                tmp=array[i];
                array[i]=array[i-1];
                array[i-1]=tmp;
                scambio=true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ArrayGenerator generator = ArrayGenerator();
    Printer printer = Printer();
    printer.readInput();
    std::vector<int> array = generator.getRandomArrayOfN<int>(printer.getSize());
    printer.printArray(array, printer.getBegin(), printer.getEnd());
    std::cout<<std::endl;
    Timer timer = Timer();
    solve(array);
    timer.printTime();
    std::cout<<std::endl;
    printer.printArray(array, printer.getBegin(), printer.getEnd());
    std::cout<<std::endl;
    return 0;
}
