#include <string>
#include <vector>

using namespace std;

int tileCase[60001];

int solution(int n) {
    int answer = 0;
    
    tileCase[1] = 1;
    tileCase[2] = 2;
    
    for(int i = 3; i <= n; i++)
    {
        tileCase[i] = (tileCase[i-2] + tileCase[i-1]) % 1000000007;
    }
    answer=tileCase[n];
    
    return answer;
}