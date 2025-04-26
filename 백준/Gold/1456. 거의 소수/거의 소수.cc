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


long long arr[10000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    long long rangeMax, rangeMin;

    cin >> rangeMin >> rangeMax;

    int arrSize = sizeof(arr) / sizeof(arr[0]);


    for (int i = 2; i < arrSize; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i <= sqrt(arrSize); i++)
    {
        if (arr[i] == 0) continue;

        for (int j = i + i; j < arrSize; j = j + i)
        {
            arr[j] = 0;
        }
    }

    int count = 0;

    for (int i = 2; i < arrSize; i++)
    {
        if (arr[i] != 0)
        {
            long long temp = arr[i];

            while ((double)arr[i] <= (double)rangeMax / (double)temp)
            {
                if ((double)arr[i] >= (double)rangeMin / (double)temp)
                {
                    count++;
                }
                temp = temp * arr[i];
            }
        }
    }
    cout << count;
    
    return 0;
}

