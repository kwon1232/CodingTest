#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string num = "";

    int min = 0, max = 0;

    bool isMinus = false;
    bool first = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
            isMinus = true;

        else if (s[i] >= '0' && s[i] <= '9')
            num += s[i];

        else if(s[i] == ' ')
        {
            if (first)
            {
                min = stoi(num);
                max = stoi(num);
                if (isMinus)
                {
                    min *= -1;
                    max *= -1;
                }
                first = false;
            }

            else
            {
                int t = stoi(num);
                if (isMinus)
                    t *= -1;
                if (min > t)
                {
                    min = t;
                }
                else if (max < t)
                    max = t;
            }

            isMinus = false;
            num = "";
        }

    }

    int t = stoi(num);
    if (isMinus)
        t *= -1;
    if (min > t)
    {
        min = t;
    }
    else if (max < t)
        max = t;

    answer += to_string(min);
    answer += " ";
    answer += to_string(max);

    return answer;
}