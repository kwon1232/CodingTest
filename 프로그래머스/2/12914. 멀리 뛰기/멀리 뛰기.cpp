#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<long long> jumpArr;
    jumpArr.push_back(1);
    jumpArr.push_back(2);
    
    for (int i = 2; i < n; i++)
    {
        jumpArr.push_back((jumpArr[i-1] + jumpArr[i - 2]) % 1234567);
    }
    
    return jumpArr[n-1];
}