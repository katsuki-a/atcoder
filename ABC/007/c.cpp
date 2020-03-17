#include <bits/stdc++.h>
using namespace std;

void view(vector<vector<char>> vv){
    cout << endl;
    for(size_t i=0; i<vv.size(); i++){
        for(size_t j=0; j<vv[i].size(); j++){
            cout << vv[i][j] << " ";
        }
    cout << endl;
  }
}

bool judge(int i, int j, vector<vector<char>> vv){
    // if(vv[i][j]=='#' || vv[i][j]=='o') return false;
    if(vv[i][j]!='g' && vv[i][j]!='.') return false;
    else return true;
}

int bfs(queue<vector<int>>& search_queue, vector<vector<char>>& vv){
    vector<int> pos = search_queue.front();
    search_queue.pop();
    int i = pos[0], j = pos[1], dist = pos[2];
    // cout << i << " " << j << " " << dist << " " << search_queue.size() <<endl;
    if(i<0 || i>vv.size()-1 || j<0 || j>vv[0].size()-1){
        if(!(search_queue.empty())){
            bfs(search_queue, vv);
            return 0;
        }
    }
    if(!(judge(i, j, vv))){
        if(!(search_queue.empty())){
            bfs(search_queue, vv);
            return 0;
        }
    }
    if(vv[i][j]=='g'){
        cout << dist << endl;
        return 0;
    }
    // view(vv);
    vv[i][j] = to_string(dist)[0];
    if(i!=0) if(judge(i-1, j, vv)) search_queue.push({i-1, j, dist+1});
    if(i!=vv.size()-1) if(judge(i+1, j, vv)) search_queue.push({i+1, j, dist+1});
    if(j!=0) if(judge(i, j-1, vv)) search_queue.push({i, j-1, dist+1});
    if(j!=vv[i].size()-1) if(judge(i, j+1, vv)) search_queue.push({i, j+1, dist+1});
    if(!(search_queue.empty())) bfs(search_queue, vv);
}

int main(void){
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    vector<char> v(c);
    vector<vector<char>> vv(r, v);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> vv[i][j];
            if(i==gy-1 && j==gx-1) vv[i][j]='g';
        }
    }
    queue<vector<int>> search_queue;
    // view(vv);
    search_queue.push({sy-1, sx-1, 0});
    bfs(search_queue, vv);
    // view(vv);
    return 0;
}