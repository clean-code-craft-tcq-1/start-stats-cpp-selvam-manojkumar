#include <vector>
struct Stats{
    float average;
    float max;
    float min;
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& );
}
class IAlerter {
public:
	virtual ~IAlerter() {};
	virtual void setstatus(bool flag) = 0;
};

class EmailAlert : public IAlerter
{
public:
	bool emailSent;
	EmailAlert(); 
	virtual void setstatus(bool flag);
};

class LEDAlert : public IAlerter
{
public:
	bool ledGlows;
	LEDAlert();
	virtual void setstatus(bool flag);
};

class StatsAlerter {
	
public:
	float maxThreshold;
	const std::vector<IAlerter*> objList;
	StatsAlerter(float maxThreshold, const std::vector<IAlerter*>&list);
	void checkAndAlert(const std::vector<float>&);
};
