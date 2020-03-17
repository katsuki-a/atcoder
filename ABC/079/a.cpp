#include <bits/stdc++.h>
using namespace std;
const int NUM = 4, OP = 3;

int calc(int a[NUM], int b[OP]){
    int res = a[0];
    for(int i=0; i<OP; i++){
        res += a[i+1]*b[i];
    }
    return res;
}

bool dfs(int i, int a[NUM], int b[OP]){
    // std::cout << i  << ": " << b[0] << b[1] << b[2] << endl;
    if(i==OP){
        // std::cout << calc(a, b) << endl;
        if(calc(a, b)==7){
            string equ="";
            for(int i=0; i<OP; i++){
                if (b[i]==1) equ+="+";
                else equ+="-";
            }
            std::cout << a[0] << equ[0] << a[1] << equ[1] << a[2] << equ[2] << a[3] << "=7" << endl;
            return true;
        }else{
            return false;
        }
    }
    int c[OP], d[OP];
    memcpy(c, b, sizeof(int)*OP);
    memcpy(d, b, sizeof(int)*OP);
    c[i] = 1;
    if (dfs(i+1, a, c)) return true;
    d[i] = -1;
    if (dfs(i+1, a, d)) return true;
    return false;
}

int main(void){
    string s;
    int a[NUM];
    std::cin >> s;
    for(int i=0; i<NUM; i++){
        a[i] = s[i]-'0';
    }
    int b[OP] = {1, 1, 1};
    dfs(0, a, b);
    return 0;
}