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
#include <cmath>


using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    
    cin >> n;

    vector<pair<int, int>> conferenceRoom(n);


    for (int i = 0; i < n; i++)
    {
        cin >> conferenceRoom[i].second;
        cin >> conferenceRoom[i].first;
    }

    sort(conferenceRoom.begin(), conferenceRoom.end());

    int count = 0;
    int end = -1;

    for (int i = 0; i < n; i++)
    {
        if (conferenceRoom[i].second >= end)
        {
            end = conferenceRoom[i].first;
            count++;
        }
    }

    cout << count;

    
    return 0;
}