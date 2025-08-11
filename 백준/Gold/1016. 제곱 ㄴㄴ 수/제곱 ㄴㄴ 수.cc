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

    long min, max;
    cin >> min >> max;

    vector<bool> check(max - min + 1);

    for (long i = 2; i * i <= max; i++)
    {
        long pow = i * i;
        long start_idx = min / pow;
        if (min % pow != 0)
            start_idx++;

        for (long j = start_idx; pow * j <= max; j++)
            check[(int)((j * pow) - min)] = true;
    }

    int cnt = 0;

    for (int i = 0; i <= max - min; i++)
        if (!check[i])
            cnt++;

    cout << cnt << endl;
    
    return 0;
}

