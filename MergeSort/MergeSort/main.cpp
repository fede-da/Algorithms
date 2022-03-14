//
//  main.cpp
//  MergeSort
//
//  Created by Federico D'Armini on 11/03/22.
//

#include <iostream>
#include <vector>
#include <functional>

#include "array_generator/array_generator.cpp"
#include "printer/printer.cpp"
#include "merge_sort/merge_sort.cpp"
#include "timer/timer.cpp"

void doNothing(){
    
}

int main(int argc, const char * argv[]) {
    ArrayGenerator generator = ArrayGenerator();
    Printer printer = Printer();
    printer.readInput();
    std::vector<int> array = generator.getRandomArrayOfN<int>(printer.getSize());
    MergeSort ms = MergeSort(array,printer);
    Timer t ;
    ms.solveIterative();
    t.printTime();
    ms.setNewArray(array);
    t.reset();
    ms.solveRecursive();
    t.printTime();
    
    return 0;
}
