//
//  MyTimer.cpp
//  C++Book
//
//  Created by Federico D'Armini on 24/12/21.
//

#include <iostream>
#include <vector>

using namespace std::chrono;
class Timer{
private:
    steady_clock::time_point start;
    steady_clock::time_point stop;

public:
    Timer(){}
    void startTimer(){
        std::cout<<"Starting timer\n";
        start=high_resolution_clock::now();
    }
    void stopTimer(){
        stop=high_resolution_clock::now();
        auto duration=duration_cast<seconds>(stop - start);
        std::cout << "Time elapsed : " << duration.count() <<" seconds" << std::endl<<std::endl;
    }
    
    void waitFor(std::vector<int> &array, std::function<void(std::vector<int>&)> f)
    {
         this->startTimer();
         f(array);
         this->stopTimer();
    }
};
