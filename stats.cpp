#include "stats.h"
#include <cmath>

Stats Statistics::ComputeStatistics(const std::vector<float>&input ) {
    //Implement statistics here
    float sum=0;
    static float prev = 0;
	Stats temp = {NAN, NAN, NAN};
    if(input.empty())
    {
       return temp; 
    }
    temp.min = input[0];
    temp.max = input[0];
    for(auto n:input)
    {
        if(n>temp.max)
        {
            temp.max = n;
        }
        if( n<temp.min)
        {
            temp.min = n;
        }
        sum += n;

    }
    temp.average = sum/input.size();
    
    return temp;
}


LEDAlert::LEDAlert():ledGlows(false) {};
EmailAlert::EmailAlert() :emailSent(false) {};

void EmailAlert::setstatus(bool flag)
{
	this->emailSent = flag;
}
void LEDAlert::setstatus(bool flag)
{
	this->ledGlows = flag;
}

StatsAlerter::StatsAlerter(float threshold, const std::vector<IAlerter*>&list) : maxThreshold(threshold), objList(list) {};

void StatsAlerter::checkAndAlert(const std::vector<float>&list) 
{
	auto objstatistics = Statistics::ComputeStatistics(list);
	bool flag = false;
	if (objstatistics.max > maxThreshold)
	{
		flag = true;
	}
	for (auto ptr = objList.begin(); ptr < objList.end(); ptr++)
	{
		(*ptr)->setstatus(flag);
	}
}
