#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    vector<int> box(10000001);

    for (int i : tangerine) {
        box[i]++;
    }

    sort(box.rbegin(), box.rend());

    for (int i = 0; i < box.size(); i++) {
        if (box[i] < k) {
            answer++;
            k -= box[i];
        }
        else {
            answer++;
            break;
        }
    }
    

    return answer;
}
