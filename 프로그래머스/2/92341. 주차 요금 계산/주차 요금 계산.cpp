#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int ConvertTimeToMin(const string& time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int CalculationParkingFee(int totalTime, const vector<int>& fees)
{
    int baseTime = fees[0];
    int baseFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    if (totalTime <= baseTime)
        return baseFee;
    int extra = ceil((totalTime - baseTime) / (double)unitTime);
    return baseFee + extra * unitFee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> totalTimes;    
    map<string, int> lastInTime;    
    map<string, bool> parked;       

    for (const string& record : records) {
        stringstream ss(record);
        string time, carNum, inOut;
        ss >> time >> carNum >> inOut;
        int minute = ConvertTimeToMin(time);

        if (inOut == "IN") {
            lastInTime[carNum] = minute;
            parked[carNum] = true;
        }
        else {
            totalTimes[carNum] += minute - lastInTime[carNum];
            parked[carNum] = false;
        }
    }

    int endOfDay = ConvertTimeToMin("23:59");
    for (auto& [carNum, isParked] : parked) {
        if (isParked) {
            totalTimes[carNum] += endOfDay - lastInTime[carNum];
        }
    }
    
    vector<pair<string, int>> result;
    for (auto& [carNum, time] : totalTimes) {
        result.push_back({carNum, CalculationParkingFee(time, fees)});
    }
    sort(result.begin(), result.end());

    vector<int> answer;
    for (auto& [carNum, fee] : result) {
        answer.push_back(fee);

    }
    return answer;
}