#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int sum = 0;
    set<int> s;
    for (int i = 0; i < elements.size(); i++)
    {
        sum += elements[i];
    }

    for (int i = 0; i < elements.size(); i++)
    {
        for (int j = 0; j < elements.size(); j++)
        {
            sum = 0;
            for (int k = 0; k < i + 1; k++)
            {
                sum += elements[(j + k) % elements.size()];
            }
            s.insert(sum);
        }

    }


    return s.size();
}

