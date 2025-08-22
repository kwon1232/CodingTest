#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    if(people.size() < 2)
        return people.size();
    
    int min = 0;
    int max = people.size() - 1;
    
    while (min <= max)
    {
        if(people[max] + people[min] > limit)
        {
            answer++;
            max--;
        }
        else
        {
            answer++;
            min++;
            max--;
        }
    }
    
    return answer;
}