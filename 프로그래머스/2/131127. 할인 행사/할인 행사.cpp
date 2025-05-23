#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string,int> wMap;
    
    for(int i = 0; i < want.size(); i++)
    {
        wMap[want[i]] += number[i];
    }
    
    for(int i = 0; i <= discount.size() - 10; i++)
    {   
        map<string, int> tMap = wMap; 
        for (int j = 0; j < 10; j++) {
            string item = discount[i + j];
            if (tMap.find(item) != tMap.end()) {
                tMap[item]--;
            }
        }
        
        bool check = true;
        for(auto it : tMap)
        {
            if(it.second > 0)
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            answer++;
        }
    }
    
    
    
    return answer;
}