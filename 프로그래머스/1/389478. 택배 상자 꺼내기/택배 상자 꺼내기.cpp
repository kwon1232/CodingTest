#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    
    int totalHeight  = (n - 1) / w;
    int currHeight  = (num - 1) / w;
    int pos  = (num - 1) % w;
    
      if (currHeight % 2 == 1) {
        pos = w - 1 - pos;
    }
    
    for (int h = currHeight + 1; h <= totalHeight; h++) {
        int idx;
        if (h % 2 == 0) {
            idx = h * w + pos;
        } else {
            idx = h * w + (w - 1 - pos);
        }
        
        if (idx < n) { // 상자가 존재하는 경우
            answer++;
        }
    }
    
    return answer;
    
    return answer;
}