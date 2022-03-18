//
//  main.cpp
//  RecursiveSquareMatrixMultiply
//
//  Created by Federico D'Armini on 18/03/22.
//

#include <iostream>
#include <vector>
#include <random>
#include <cmath>

#include "timer/timer.cpp"

template <typename T>
std::vector<std::vector<T>> generateRandomMatrix(int size){
     std::random_device dev;
     std::mt19937 rng(dev());
     std::uniform_int_distribution<std::mt19937::result_type> dist6(1,9);
     
     std::vector<std::vector<T>> matrix{};
     std::vector<T> tmp{};
     for(int i=0;i!=size;i++){
         for(int j=0;j!=size;j++){
             tmp.push_back(std::move(static_cast<int>(dist6(rng))));
         }
         matrix.push_back(std::move(tmp));
     }
     return matrix;
}

template <typename T>
void printMatrix(std::vector<std::vector<T>>& matrix){
    std::cout<<"Printing matrix :\n";
    for(std::vector<T> v : matrix){
        for(T t : v)
            std::cout<<t<<" ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

template <typename T>
std::vector<std::vector<T>> square_matrix_multiply(std::vector<std::vector<T>> &A,std::vector<std::vector<T>> &B){
    int size = (int) A[0].size();
    std::vector<std::vector<T>> C (size,std::vector<T>(size,0));
    for(int i=0;i!=size;i++){
        for(int j=0;j!=size;j++){
            for(int k=0;k<size;k++)
                C[i][j]+= A[i][k]*B[k][j];
        }
    }
    return std::move(C);
}
template <typename T>
void multiply(std::vector<std::vector<T>> &A,std::vector<std::vector<T>> &B,std::vector<std::vector<T>> &C,int rc){
    static int i=0,j=0,k=0;
    if(i>=rc)return;
    if(i<rc){
        if(j<rc){
            if(k<rc){
                C[i][j]+=A[i][k]*B[k][j];
                k++;
                multiply(A, B, C, rc);
            }
        k=0;
        j++;
        multiply(A, B, C, rc);
        }
    j=0;
    i++;
    multiply(A, B, C, rc);
    }
}

template <typename T>
std::vector<std::vector<T>> recursive_square_matrix_multiply(std::vector<std::vector<T>> &A,std::vector<std::vector<T>> &B){
    std::vector<std::vector<T>> C (A[0].size(),std::vector<T>(A[0].size(),0));
    multiply(A, B, C,(int) A[0].size());
    return C;
}

int main(int argc, const char * argv[]) {
    int size = 20;
    std::vector<std::vector<int>> A = generateRandomMatrix<int>(size);
    std::vector<std::vector<int>> B = generateRandomMatrix<int>(size);
    Timer t;
    std::vector<std::vector<int>> C {recursive_square_matrix_multiply(A, B)};
    t.printTime();
    return 0;
}
