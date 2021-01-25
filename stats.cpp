#include "stats.h"
#include <cmath>

Stats Statistics::ComputeStatistics(const std::vector<float>&input ) {
    //Implement statistics here
    double sum=0;
    static float prev = 0;
    Stats temp={NAN, NAN, NAN};
    if(input.empty())
    {
       return temp; 
    }
    temp.min = input[0];
    temp.max = input[0];
    prev = input[0];
    for(auto n:input)
    {
        if(n>prev)
        {
            temp.max = n;
        }
        else
        {
            temp.min = n;
        }
        sum += n;
        prev = n
    }
    temp.average = sum/input.size;
    
    return temp;
}
