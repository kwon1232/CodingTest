#include <string>
#include <vector>
#include <unordered_map>

int solution(std::vector<int> a) {
    int answer = 0;
    
    std::unordered_map<int,int> count;
    
    for (int i = 0; i < a.size(); i++)
    {
        count[a[i]]++;
    }
    
    for (auto it = count.begin(); it != count.end(); it++)
    {
        int x =  it->first;
        int freq = it->second;
        
        if(freq * 2 <= answer) continue;
        
        int length =0;
        for(int i = 0; i < a.size()-1; i++)
        {
            if((a[i] == x || a[i+1]== x) && a[i] != a[i+1])
            {
                length += 2;
                i++;
            }
        }
        
        if(length > answer) 
            answer = length;
    }
    
    return answer;
}