#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack <int> stk;

    for (int i = 0; i < static_cast<int>(moves.size()); i++)
    {
        int x = moves[i]-1;
        for (int y = 0; y < static_cast<int>(board.size()); y++)
        {
            if (board[y][x] != 0)
            {
                if (!stk.empty() && stk.top() == board[y][x])
                {
                    stk.pop();
                    answer += 2;
                }
                else
                {
                    stk.push(board[y][x]);
                }
                board[y][x] = 0;
                break;
            }
        }
    }

    return answer;
}