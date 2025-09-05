#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> q;
    for (int i = 0; i < works.size(); i++)
    {
        q.push(works[i]);
    }
    
    while(n > 0 && !q.empty())
    {
        int temp = q.top();
        q.pop();
        
        if(temp > 0)
        {
            q.push(temp -1);
        }
        n--;
    }
    
    while(!q.empty())
    {
        long long x = q.top();
        q.pop();
        answer += x*x;
    }
    
    
    return answer;
}