#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n,0);
    
    for (int start = 0; start < n; start++)
    {
        if (visited[start]) continue;
        
        answer++;
        
        stack<int> stk;
        
        stk.push(start);
        visited[start] = 1;
        
        while (!stk.empty())
        {
            int u = stk.top(); stk.pop();
            for (int v = 0; v < n; v++)
            {
                if(computers[u][v] == 1 && !visited[v])
                {
                    visited[v] = 1;
                    stk.push(v);
                }
            }
        }
    }
    
    
    return answer;
}