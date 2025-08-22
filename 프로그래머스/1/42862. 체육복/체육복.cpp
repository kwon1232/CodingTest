#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> difference(n + 2, 0);
    
    for (int x : lost)  difference[x]--;
    for (int x : reserve) difference[x]++;
    
    for (int i = 1; i <= n; i++)
    {
        if(difference[i] == -1) {
            if(difference[i - 1] == 1)
            {
                difference[i - 1]--;
                difference[i]++;
            }
            else if (difference[i+1] == 1)
            {
                difference[i + 1]--;
                difference[i]++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(difference[i] >= 0) ++answer;
    }
    
    return answer;
}