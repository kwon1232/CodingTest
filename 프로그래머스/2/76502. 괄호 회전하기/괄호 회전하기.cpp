#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>


using namespace std;

int isIntact(queue <char> q)
{
    stack<char> stk;

    while (!q.empty())
    {
        if (q.front() == '(' || q.front() == '[' || q.front() == '{')
            stk.push(q.front());
        else if (!stk.empty())
        {
            switch (q.front())
            {
            case ')':
                if (stk.top() == '(')
                    stk.pop();
                break;
            case ']':
                if (stk.top() == '[')
                    stk.pop();
                break;
            case '}':
                if (stk.top() == '{')
                    stk.pop();
                break;
            default:
                break;
            }
        }
        else if (stk.empty())
        {
            return 0;
        }
        q.pop();
    }

    if (!stk.empty())
        return 0;

    return 1;
}


int solution(string s) {
    int answer = 0;
    queue<char> q;

    for (int i = 0; i < s.size(); i++)
    {
        q.push(s[i]);
    }


    for (int i = 0; i < s.size(); i++)
    {
        char temp = q.front();
        q.pop();
        q.push(temp);
        answer += isIntact(q);
    }

    return answer;
}