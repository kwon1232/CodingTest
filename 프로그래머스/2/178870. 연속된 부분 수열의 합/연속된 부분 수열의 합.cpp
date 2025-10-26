#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0; 
    int sum = 0;
    int minLen = INT_MAX;
    vector<int> answer = {-1,-1};
    
    for (int right = 0;  right < n; right++)
    {
        sum += sequence[right];
        
        while (sum > k && left <= right)
            sum -= sequence[left++];
        
        if (sum == k )
        {
            int len = right - left + 1;
            if (len <minLen)
            {
                minLen = len;
                answer = {left, right};
            }
        }
    }
    return answer;
}