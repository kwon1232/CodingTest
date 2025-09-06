#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    
    int mini = arr[0];
    int miniIdx = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(mini > arr[i])
        {
            mini = arr[i];
            miniIdx = i;
        }
    }
    
    arr.erase(arr.begin()+miniIdx);
    
    return arr;
}