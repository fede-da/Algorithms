//
//  main.cpp
//  MaxCrossingSubarray
//
//  Created by Federico D'Armini on 15/03/22.
//
#include "printer/printer.cpp"
#include <iostream>
#include <vector>

template <typename T>
std::tuple<int,int,T> solve(std::vector<T>& array,int low,int mid,int high){
    T max_left,max_right;
    T sum = 0;
    T left_sum = -1;
    for(int i=mid;i>=low;i--){
        sum = sum + array[i];
        if(sum>left_sum){
            left_sum=sum;
            max_left=i;
        }
    }
    sum=0;
    T right_sum=-1;
    for(int i=mid;i<=high;i++){
        sum = sum + array[i];
        if(sum>right_sum){
            right_sum=sum;
            max_right=i;
        }
    }
    return std::make_tuple(max_left,max_right,left_sum+right_sum);
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> array {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    std::tuple <int,int,int> tuple = solve(array, 0, 8, 16);
    Printer printer = Printer();
    std::cout<< "Max sub array is :  ";
    std::apply([](auto&&... args) {((std::cout << args << " "), ...);}, tuple);
    return 0;
}
