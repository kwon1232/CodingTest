#include <string>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    
    vector<int> dp(y + 1, -1);
    dp[x] = 0;

   
    for (int i = x; i <= y; ++i) {
        if (dp[i] == -1) 
            continue;              
        int nextCnt = dp[i] + 1;

        if (i + n <= y) {
            if (dp[i + n] == -1 || dp[i + n] > nextCnt)
                dp[i + n] = nextCnt;
        }

        if ((long long)i * 2 <= y) {
            if (dp[i * 2] == -1 || dp[i * 2] > nextCnt)
                dp[i * 2] = nextCnt;
        }

        if ((long long)i * 3 <= y) {
            if (dp[i * 3] == -1 || dp[i * 3] > nextCnt)
                dp[i * 3] = nextCnt;
        }
    }

    return dp[y];
}