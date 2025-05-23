using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[] want, int[] number, string[] discount) {
        int answer = 0;
        
        Dictionary<string, int> wMap = new Dictionary<string, int>();
        for (int i = 0; i < want.Length; i++)
        {
            wMap[want[i]] = number[i];
        }
        
        for (int i = 0; i <= discount.Length - 10; i++)
        {
            Dictionary<string, int> tMap = new Dictionary<string, int>(wMap);
            
            for (int j = 0; j < 10; j++)
            {
                string item = discount[i+j];
                if(tMap.ContainsKey(item)){
                    tMap[item]--;
                }
            }
            
            bool check = true;
            foreach (var pair in tMap)
            {
                if(pair.Value > 0)
                {
                    check = false;
                    break;
                }
            }
            
            if (check) answer++;
            
        }
        
        return answer;
    }
}