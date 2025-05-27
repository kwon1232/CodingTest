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

    long Min, Max;
    cin >> Min >> Max;

    vector<bool> Check(Max - Min + 1);

    for (long long i = 2; i * i <= Max; i++)
    {
        long long pow = i * i;
        long long startIDX = Min / pow;

        if (Min % pow != 0)
            startIDX++;
        
        for (long long j = startIDX; pow * j <= Max; j++)
            Check[(int)((j * pow) - Min)] = true;

    }

    int count = 0;

    for (int i = 0; i <= Max - Min; i++)
    {
        if (!Check[i]) count++;
    }

    cout << count << endl;

    return 0;
}

