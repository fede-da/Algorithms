//
//  main.cpp
//  MergeSort
//
//  Created by Federico D'Armini on 11/03/22.
//

#include <iostream>
#include <vector>
#include "array_generator/array_generator.cpp"
#include "printer/printer.cpp"
#include "recursive_merge_sort/recursive_merge_sort.cpp"

int main(int argc, const char * argv[]) {
    ArrayGenerator generator = ArrayGenerator();
    Printer printer = Printer();
    printer.readInput();
    std::vector<int> array = generator.getRandomArrayOfN<int>(printer.getSize());
    RecursiveMergeSort rms = RecursiveMergeSort(array);
    printer.printArray(array,printer.getBegin(),printer.getEnd());
    rms.mergesort(0, (int)array.size()-1);
    std::vector<int>tmp{rms.getArray()};
    printer.printArray(
                       rms.getArray(),printer.getBegin(),printer.getEnd());
    return 0;
}
