#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(string word) {
    int answer = 0;

    string voca = "AEIOU";
    map <char, int> m;

    for (int i = 0; i < voca.size(); i++) {
        m[voca[i]] = i;
    }

    int nextWord[5] = { 781, 156, 31, 6, 1 };

    for (int i = 0; i < word.size(); i++) {
        answer += 1 + m[word[i]] * nextWord[i];
    }


    return answer;
}