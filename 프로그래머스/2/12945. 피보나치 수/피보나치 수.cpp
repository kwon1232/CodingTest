#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int>arr(n+1,0);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i = 3; i <= n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]) % 1234567;
    }
    
    return arr[n-1];
}