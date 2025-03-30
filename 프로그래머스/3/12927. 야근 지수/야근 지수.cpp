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
    int temp;
    while (!q.empty() && n != 0)
    {
        n--;
        temp = q.top();
        q.pop();
        if (temp != 1) q.push(temp - 1);
    }
    while (!q.empty())
    {
        answer += (q.top() * q.top()); 
        q.pop();
    }


    return answer;
}
