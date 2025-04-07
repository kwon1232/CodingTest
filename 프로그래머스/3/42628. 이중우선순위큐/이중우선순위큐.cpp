#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxHip;
    priority_queue<int, vector<int>, greater<int> > minHip;

    for (int i = 0; i < operations.size(); i++)
    {
        string num = "";
        if (operations[i][0] == 'I')
        {
            num += operations[i].substr(2, operations[i].length());
            maxHip.push(stoi(num));
            minHip.push(stoi(num));
        }
        else
        {
            // 최솟값 삭제
            if (operations[i][2] == '-')
            {
                if (!minHip.empty())
                {
                    minHip.pop();
                }
                if (!maxHip.empty())
                {
                    int gap = maxHip.size() - minHip.size();
                    priority_queue<int> swapMaxHip;
                    for (int j = 0; j < maxHip.size() - gap; j++)
                    {
                        swapMaxHip.push(maxHip.top());
                        maxHip.pop();
                    }

                    maxHip.swap(swapMaxHip);

                }
            }
            // 최대 힙 삭제
            else
            {
                if (!maxHip.empty())
                {
                    maxHip.pop();
                }
                if (!minHip.empty())
                {
                    int gap = minHip.size() - maxHip.size();
                    priority_queue<int, vector<int>, greater<int> > swapMinHip;
                    for (int j = 0; j < minHip.size() - gap; j++)
                    {
                        swapMinHip.push(minHip.top());
                        minHip.pop();
                    }
                    minHip.swap(swapMinHip);
                }
            }
        }
    }

    if (!maxHip.empty())
    {
        answer.emplace_back(maxHip.top());
    }
    else
    {
        answer.emplace_back(0);
    }
    if (!minHip.empty())
    {
        answer.emplace_back(minHip.top());
    }
    else
    {
        answer.emplace_back(0);
    }

    return answer;
}
