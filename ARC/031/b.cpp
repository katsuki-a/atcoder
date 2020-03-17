#include <bits/stdc++.h>
using namespace std;
const int ROW=10;
const int COL=10;

bool check(vector<int>& index, vector<vector<char>> vv){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(vv[i][j]=='o'){
                index[0] = i;
                index[1] = j;
                return true;
            }
        }
    }
    return false;
}

int count_neighbor(int i, int j, vector<vector<char>> vv){
    int res=0;
    if(i<0 || i>ROW-1 || j<0 || j>COL-1) return 0;
    if(i!=0) if(vv[i-1][j]=='o') res += 1;
    if(i!=ROW-1) if(vv[i+1][j]=='o') res += 1;
    if(j!=0) if(vv[i][j-1]=='o') res += 1;
    if(j!=COL-1) if(vv[i][j+1]=='o') res += 1;
    return res;
}

bool search(int i, int j, vector<vector<char>>& vv){
    if(i<0 || i>ROW-1) return false;
    if(j<0 || j>COL-1) return false;
    if(vv[i][j]=='x') return false;
    vv[i][j] = 'x';
    search(i+1, j, vv);
    search(i-1, j, vv);
    search(i, j+1, vv);
    search(i, j-1, vv);
    return true;
}

void view(vector<vector<char>> vv){
  for(size_t i=0; i<vv.size(); i++){
    for(size_t j=0; j<vv[i].size(); j++){
      cout << vv[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void){

    vector<char> v(COL);
    vector<vector<char>> vv(ROW, v);
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            cin >> vv[i][j];
        }
    }
    vector<int> index(2);
    int neighbor;
    vector<vector<char>> vv_trial;

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(vv[i][j]=='x'){
                neighbor = count_neighbor(i, j, vv);
                if(neighbor>1){
                    vv_trial = vv;
                    vv_trial[i][j] = 'o';
                    search(i, j, vv_trial);
                    if(!(check(index, vv_trial))){
                        cout << "YES" << endl;
                        // view(vv_trial);
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    // view(vv);
    return 0;
    // cout << count_neighbor(8, 3, vv) << endl;
}