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
#include "recursive_merge_sort/recursive_merge_sort.cpp"
#include "timer/timer.cpp"

void doNothing(){
    
}

int main(int argc, const char * argv[]) {
    ArrayGenerator generator = ArrayGenerator();
    Printer printer = Printer();
    Timer t = Timer();
    printer.readInput();
    std::vector<int> array = generator.getRandomArrayOfN<int>(printer.getSize());
    RecursiveMergeSort rms = RecursiveMergeSort(array,printer);
    t.waitFor2([&](){ rms.solveIterative(); });
    
    return 0;
}
