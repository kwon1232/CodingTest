#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    const int n = static_cast<int>(gems.size());
    
    unordered_set<string> kinds(gems.begin(), gems.end());
    const int need = static_cast<int>(kinds.size());
    
    unordered_map<string, int> cnt;
    cnt.reserve(need);
    
    int l = 0;
    int formed = 0;
    int bestL = 0, bestR = n-1;
    bool found = false;
    
    for (int r = 0; r < n; r++)
    {
        int &c = cnt[gems[r]];
        if (c == 0) formed++;
        c++;
        
        while(formed == need && l <= r)
        {
            if(!found || (r - l < bestR - bestL) || (r - l == bestR - bestL && l < bestL))
            {
                bestL = l;
                bestR = r;
                found = true;
            }
            
            int &cl = cnt[gems[l]];
            cl--;
            if(cl == 0)
            {
                cnt.erase(gems[l]);
                formed--;
            }
            l++;
        }
    }
    
    return {bestL + 1, bestR + 1};
}