#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> ans;
    int zero = count(lottos.begin(), lottos.end(), 0);
    int same = 0;
    
    for (int i = 0; i < lottos.size(); i++)
    {
        if(lottos[i] != 0 && find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
        {
            same++;
        }
    }
    
    int minRank = 7 - same;
    int maxRank = 7 - (same + zero);
    
    if(maxRank > 6)
        maxRank = 6;
    if (minRank > 6)
        minRank = 6;

    ans.push_back(maxRank);
    ans.push_back(minRank);
    
    return ans;
}