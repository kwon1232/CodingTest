#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int sum = 0;
    for (int i = 0; i < elements.size(); i++)
    {
        sum += elements[i];
    }

    vector<int> temp(sum + 1, 0);
    for (int i = 0; i < elements.size(); i++)
    {
        for (int j = 0; j < elements.size(); j++)
        {
            sum = 0;
            for (int k = 0; k < i + 1; k++)
            {
                sum += elements[(j + k) % elements.size()];
                if (temp[sum] != 1) temp[sum] = 1;
            }
        }

    }

    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] == 1) answer++;
    }

    return answer;
}
