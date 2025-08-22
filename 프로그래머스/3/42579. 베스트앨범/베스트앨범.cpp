#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genreSum;
    unordered_map<string, vector<pair<int,int>>> songs;
    
    for (int i = 0; i < genres.size(); i++)
    {
        genreSum[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string,int>> sortedGenres(genreSum.begin(), genreSum.end());
    sort(sortedGenres.begin(), sortedGenres.end(),
        [](auto &a, auto &b) {
           return a.second > b.second; 
        });
    
    vector<int> answer;
    
    for (auto &g : sortedGenres)
    {
        auto &vec = songs[g.first];
        
        sort(vec.begin(), vec.end(), [](auto &a, auto&b) {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }
            return a.first > b.first;
        });    
            for (int i = 0; i < vec.size() && i < 2; i++)
            {
                answer.push_back(vec[i].second);
            }
        
    }
    
    return answer;
}