#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int n = (int)order.size();
    stack<int> stk;
    int idx = 0;
    int delivered = 0;
    
    for (int box = 1; box <= n; box++)
    {
        stk.push(box);
        
        while(!stk.empty() && stk.top() == order[idx])
        {
            stk.pop();
            idx++;
            delivered++;
        }
    }
    
    return delivered;
}