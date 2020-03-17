#include <bits/stdc++.h>
using namespace std;

void view(vector<vector<int>> vv){
  for(size_t i=0; i<vv.size(); i++){
    for(size_t j=0; j<vv[i].size(); j++){
      cout << vv[i][j] << " ";
    }
    cout << endl;
  }
}

int dfs(int i, int flag, vector<vector<int>>& vv){
    if(vv[i][0]==-1) return false; 
    int res = 1;
    vector<int> visit(vv[i].size());
    visit = vv[i];
    for(int j=0; j<vv[i].size(); j++){
        vv[i][j] = -1;
    }
    for(int j=0; j<vv[i].size(); j++){
        if(visit[j]==1) res *= dfs(i, flag, vv);
    }

}

int main(void){
    int n, m, u, v;
    cin >> n >> m;
    vector<int> vec(n+1, 0);
    vector<vector<int>> vv(n+1, vec);
    for(int i=0; i<m; i++){
        cin >> u >> v;
        vv[u][v] = 1;
        vv[v][u] = 1;
    }
    view(vv);
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(vv[i][j]==1);
        }
    }
    return 0;
}