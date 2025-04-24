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


using namespace std;



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    cin >> m >> n;
    vector<int> v(n + 1);

    for (int i = 2; i <= n; i++)
    {
        v[i] = i;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (v[i] == 0)
        {
            continue;
        }
        for (int j = i + i; j <= n; j = j + i)
        {
            v[j] = 0;
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (v[i] != 0)
        {
            cout << v[i] << '\n';
        }
    } 

    
    return 0;
}

