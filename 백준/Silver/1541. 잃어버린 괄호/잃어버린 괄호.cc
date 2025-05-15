#include <vector>
#include <iostream> 
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <set>
#include <regex>
#include <tuple>
#include <cmath>
#include <cstddef> 

using namespace std;





int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    string str = "", temp = "";
    int result = 0;
    cin >> str;

    bool minus = false;
    for (int i = 0; i <= str.size(); i++)
    {
        // 부호를 만났을 때
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            // 이전 값이 - 였다면 이전 값을 모두 빼준다.
            if (minus) {
                result -= stoi(temp);
            }
            // 이전 값이 -가 아니었다면 모두 더해준다
            else {
                result += stoi(temp);
            }
            // 현재 부호가 - 라면 이전 값이 -가 된다는 걸 알려준다.
            temp = "";
            if (str[i] == '-')
            {
                minus = true;
            }
        }
        // 숫자라면 모두 더해준다.
        else
        {
            temp += str[i];
        }

    }

    cout << result;

    return 0;
}

