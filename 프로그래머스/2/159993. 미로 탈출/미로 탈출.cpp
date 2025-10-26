#include <string>
#include <vector>
#include <queue>

using namespace std;


int bfs(vector<string>& maps, pair<int,int> start, char target)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m,0));
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    
    int time = 0;
    while(!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(maps[x][y] == target)
                return time;
            
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                  !visited[nx][ny] && maps[nx][ny] != 'X')
                {
                    visited[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        time++;
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    pair<int,int> start, lever, exit;
    int n = maps.size();
    int m = maps[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') start = {i, j};
            else if (maps[i][j] == 'L') lever = {i, j};
            else if (maps[i][j] == 'E') exit = {i, j};
        }
    }

    int toLever = bfs(maps, start, 'L');
    if (toLever == -1) return -1;

   int toExit = bfs(maps, lever, 'E');
    if (toExit == -1) return -1;    
    
    return toLever + toExit;
}