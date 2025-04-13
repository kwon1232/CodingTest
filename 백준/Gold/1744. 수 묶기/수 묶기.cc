#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <set>
#include <regex>
#include <sstream>
#include <tuple>


using namespace std;



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>> pq_plus;
    priority_queue<int, vector<int>, greater<int>> pq_minus;
    int data;

    int oneCnt = 0;
    int zeroCnt = 0;

    cin >> N;

    while (N-- != 0)
    {
        cin >> data;
        if (data > 1)
        {
            pq_plus.push(data);
        }
        else if (data == 0)
        {
            zeroCnt++;
        }
        else if (data == 1)
        {
            oneCnt++;
        }
        else
        {
            pq_minus.push(data);
        }
    }

    int sum = 0;

    while (pq_plus.size() > 1)
    {
        int first = pq_plus.top();
        pq_plus.pop();
        int second = pq_plus.top();
        pq_plus.pop();
        sum += (first * second);
    }
    if (pq_plus.size() > 0)
    {
        sum += pq_plus.top();
        pq_plus.pop();
    }

    while (pq_minus.size() > 1)
    {
        int first = pq_minus.top();
        pq_minus.pop();
        int second = pq_minus.top();
        pq_minus.pop();
        sum += (first * second);
    }
    if (pq_minus.size() > 0)
    {
        if (zeroCnt == 0)
        {
            sum += pq_minus.top();
            pq_minus.pop();
        }
        else
            pq_minus.pop();
    }

    sum += oneCnt;

    cout << sum << '\n';

    return 0;
}

