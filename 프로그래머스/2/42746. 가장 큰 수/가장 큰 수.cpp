#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s;
    for (int x : numbers) s.push_back(to_string(x));
    
    sort(s.begin(), s.end(), [](const string& a, const string& b){
       return a+b > b+a; 
    });
    
    if(!s.empty() && s[0] == "0") return "0";
    
    size_t total_len = 0;
    for (auto& t : s) total_len += t.size();
    answer.reserve(total_len);
    
    for (auto& t : s) answer += t;
    return answer;
    
    
    return answer;
}