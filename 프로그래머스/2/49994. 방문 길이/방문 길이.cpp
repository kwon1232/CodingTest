#include <string>
#include <cstring>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool visited[11][11][4];
    memset(visited, false, sizeof(visited));
    
    int x = 5, y = 5;
    
    for (int i = 0; i < dirs.size(); i++)
    {
        int dir = 0;
        if(dirs[i] == 'L')
        {
            dir = 1;
        }
        else if(dirs[i] == 'U')
        {
            dir = 2;
        }
        else if(dirs[i] == 'R')
        {
            dir = 3;
        }
        else if (dirs[i] == 'D')
        {
            dir = 0;
        }
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (nx < 0 || ny < 0 || nx >= 11 || ny >= 11) continue;
        int countdir = (dir + 2) % 4;
        if(!visited[x][y][dir] && !visited[nx][ny][countdir])
        {
            visited[x][y][dir] = true;
            visited[nx][ny][countdir] = true;
            answer++;
        }
        x = nx;
        y = ny;
    }
    
    
    return answer;
}