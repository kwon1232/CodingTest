#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> students {
        {1 ,2 ,3 ,4 ,5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    vector<int> results(3,0);
    
    int s1 = 0, s2 = 0, s3 = 0, max = -1;
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(s1 == students[0].size()) s1 = 0;
        if(s2 == students[1].size()) s2 = 0;
        if(s3 == students[2].size()) s3 = 0;
        
        if (students[0][s1] == answers[i]) results[0]++;
        if (students[1][s2] == answers[i]) results[1]++;
        if (students[2][s3] == answers[i]) results[2]++;
        
        s1++; s2++; s3++;
    }
    
    max = *max_element(results.begin(), results.end());
    
    for(int i = 0; i < results.size(); i++)
    {
        if(max == results[i])
            answer.push_back(i+1);
    }
    
    
    return answer;
}