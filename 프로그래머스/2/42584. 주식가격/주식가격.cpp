#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>


using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    for (int i = 0; i < prices.size()-1; i++)
    {
        int chk = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            chk++;
            if (prices[i] > prices[j])
                break;
        }
        answer[i] = chk;
    }

    return answer;
}