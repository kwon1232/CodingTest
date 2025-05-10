using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        Dictionary<int, int> countMap = new Dictionary<int, int>();
        foreach(int i in tangerine)
        {
            if(countMap.ContainsKey(i))
            {
                countMap[i] = countMap[i] + 1;
            }
            else
            {
                countMap[i] = 1;
            }
        }
        
        List<int> counts = countMap
            .Values
            .OrderByDescending((int x) => x)
            .ToList();
        
        foreach(int cnt in counts)
        {
            answer = answer + 1;
            k = k - cnt;
            if (k <= 0)
            {
                break;
            }
        }
        
        return answer;
    }
}