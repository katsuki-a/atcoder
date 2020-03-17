#include <bits/stdc++.h>
using namespace std;

void view(vector<vector<char>> vv){
  for(size_t i=0; i<vv.size(); i++){
    for(size_t j=0; j<vv[i].size(); j++){
      cout << vv[i][j] << " ";
    }
    cout << endl;
  }
}

bool search(int i, int j, vector<vector<char>>& vv){
    if(i==-1 || i==vv.size()) return false;
    if(j==-1 || j==vv[i].size()) return false;
    if(vv[i][j]=='#' || vv[i][j]=='0') return false;
    else if(vv[i][j]=='g') return true;
    vv[i][j] = '0';
    if(search(i+1, j, vv) || search(i-1, j, vv) || search(i, j+1, vv) || search(i, j-1, vv)) return true;
    else return false;
}

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<int> start(2);
    vector<char> v(w);
    vector<vector<char>> vv(h, v);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> vv[i][j];
            if(vv[i][j]=='s'){
                start[0]=i;
                start[1]=j;
            }
        }
    }
    // view(vv);
    if(search(start[0], start[1], vv)) cout << "Yes" << endl;
    else cout << "No" << endl;
    // view(vv);
    return 0;
}