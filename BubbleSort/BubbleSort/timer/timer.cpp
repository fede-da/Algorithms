//
//  MyTimer.cpp
//  C++Book
//
//  Created by Federico D'Armini on 24/12/21.
//

#include <iostream>
#include <vector>

class Timer
{
public:
  using clock = std::chrono::system_clock;
  clock::time_point start;

  Timer()
    : start( clock::now() )
  {}
    auto time_elapsed() const
  {
      return clock::now() - start;
  }
    void reset()
  {
      start = clock::now();
  }
    void printTime(){
        std::cout<<"Time elapsed (milliseconds) : "<< this->time_elapsed().count() << std::endl;
    }
};
