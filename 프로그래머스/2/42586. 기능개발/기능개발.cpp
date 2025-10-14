#include <string>
#include <vector>
#include <utility> 
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<pair<int, int>> programList;
    
    for (int i = 0; i < progresses.size(); i++) 
    {
        programList.push_back(make_pair(progresses[i], speeds[i]));
    }
    
    int day = 0;
    int deployIdx = 0;
    
    while(deployIdx < programList.size())
    {
        day++;
        
        for(int i = 0; i < programList.size(); i++)
        {
            if( programList[i].first < 100)
            {
                programList[i].first += programList[i].second;
            }
        }
        
        int count = 0;
        while (deployIdx < programList.size()  && programList[deployIdx].first >= 100) {
            count++;
            deployIdx++;
        }
        
         if (count > 0)
            answer.push_back(count);
    }
    
    return answer;
}