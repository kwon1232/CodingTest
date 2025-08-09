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


bool isPalindrame(int target)
{
    string temp_str = to_string(target);
    char const* temp = temp_str.c_str();
    int s = 0;
    int e = temp_str.size() - 1;

    while (s < e)
    {
        if (temp[s] != temp[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}


int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //std::cout.tie(NULL);

    vector<int> numbers = { 2, 3, 3, 5 };

    long n;
    cin >> n;
    long A[10000001];

    for (int i = 2; i < 10000001; i++)
    {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(10000001); i++)
    {
        if (A[i] == 0)
        {
            continue;
        }
        for (int j = i + i; j < 10000001; j = j + i)
            A[j] = 0;
    }

    int i = n;

    while (true)
    {
        if (A[i] != 0)
        {
            int result = A[i];
            if (isPalindrame(result))
            {
                cout << result << endl;
                break;
            }
        }
        i++;
    }
    
    return 0;
}

