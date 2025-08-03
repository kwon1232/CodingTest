#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[18][18][18] = {false,};
vector<int> node[18]; // 연결 상태
vector<int> kind; // 해당 노드의 상태
int ans = 0; // 최대 양의 수
void dfs(int x, int sheep, int wolf){
    ans = max(ans,sheep); // 최대 양의 수를 답으로 선택
    
    // 연결되어 있는 부모,자식 노드 모두 확인
    for(int i = 0; i < node[x].size(); i++){
        int nx = node[x][i];
        // 다음 노드가 '양' && 방문하지 않은 경우
        if(kind[nx] == 0 && !visited[nx][sheep+1][wolf]){
            visited[nx][sheep+1][wolf] = true;
            kind[nx] = -1; // 빈 노드로 바꿔줌
            dfs(nx,sheep+1,wolf); // 재귀 호출
            
            // 사용 후 다른 DFS가 호출할 수 있도록 원상복구
            kind[nx] = 0;
            visited[nx][sheep+1][wolf] = false;
        }
        // 다음 노드가 '늑대'
        else if(kind[nx] == 1){
            // 양 > 늑대+1 && 방문하지 않은 경우에만 다음 노드로 이동
            if(sheep > wolf+1 && !visited[nx][sheep][wolf+1]){
                visited[nx][sheep][wolf+1] = true;
                kind[nx] = -1;
                dfs(nx,sheep,wolf+1);
                kind[nx] = 1;
                visited[nx][sheep][wolf+1] = false;
            }
        }
        // 다음 노드가 빈 노드인 경우
        else{
            if(!visited[nx][sheep][wolf]){
                visited[nx][sheep][wolf] = true;
                dfs(nx,sheep,wolf);
                visited[nx][sheep][wolf] = false;
            }
        }
    }
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i = 0; i < edges.size(); i++){
        node[edges[i][0]].push_back(edges[i][1]);
        node[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i = 0; i < info.size(); i++) kind.push_back(info[i]);
    
    kind[0] = -1; // 루트 노드 빈 노드로
    visited[0][1][0] = true; // 루트 노드 방문 처리
    dfs(0,1,0); // 루트 노드에서 양 얻은 채로 시작
    return ans;
}