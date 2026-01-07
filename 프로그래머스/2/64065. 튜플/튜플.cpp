#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp (pair<int,int>& a, pair<int,int>& b)
{
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> m;
    string temp = "";
    for(int i =0; i < s.size(); i++)
    {
        if(s[i] != '{' && s[i] != '}' && s[i] != ',')
        {
            temp += s[i];
        }
        
        if(s[i] == '}' || s[i] == ',')
        {
            if(temp == "") continue;
            m[stoi(temp)]++;
            temp = "";
        }
        
    }
    
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < v.size(); i++)
    {
        answer.emplace_back(v[i].first);
    }
    
    return answer;
}