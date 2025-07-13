#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    int nowFinalRoute = -30001;
    for (int i = 0; i < routes.size(); i++)
    {
        if (nowFinalRoute<routes[i][0])
        {
            answer++;
            nowFinalRoute = routes[i][1];
        }
    }
    
    return answer;
}