#include <bits/stdc++.h>
using namespace std;
const long MAX_S = 10;

long calc(long a[MAX_S-1], string s){
    long len = s.size();
    long res = 0;
    long temp = s[0]-'0';
    for(long i=1; i<len; i++){
        if(a[i-1]==1){
            res += temp;
            temp = s[i]-'0';
        }else if(a[i-1]==0){
            temp *= 10;
            temp += s[i]-'0';
        }
    }
    return res+temp;
}

long dfs(long i, long last, long a[MAX_S-1], string s){
    if (i==last) return calc(a, s);
    long res0 = 0, res1 = 0;
    a[i] = 0;
    res0 = dfs(i+1, last, a, s);
    a[i] = 1;
    res1 = dfs(i+1, last, a, s);
    return res0+res1;
}

int main(void){
    string s;
    cin >> s;
    long a[MAX_S-1] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("%ld\n", dfs(0, s.size()-1, a, s));
    return 0;
}