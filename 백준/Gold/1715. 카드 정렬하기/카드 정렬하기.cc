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
    
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int data;

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        pq.push(data);
    }

    int sum = 0, card1 = 0, card2 = 0;

    while (pq.size() != 1)
    {
        card1 = pq.top();
        pq.pop();
        card2 = pq.top();
        pq.pop();
        pq.push(card1 + card2);
        sum += card1 + card2;
    }

    cout << sum;

    return 0;
}

