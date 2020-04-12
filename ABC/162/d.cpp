#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long sum=0;
    string s;
    cin >> n;
    cin >> s;
    vector<int> r_cnt(n);
    vector<int> g_cnt(n);
    vector<int> b_cnt(n);
    int r_num=0, g_num=0, b_num=0;
    for(int i=n-1; i>=0; i--){
        if(s[i]=='R') r_num+=1;
        if(s[i]=='G') g_num+=1;
        if(s[i]=='B') b_num+=1;
        r_cnt[i]=r_num;
        g_cnt[i]=g_num;
        b_cnt[i]=b_num;
    }
    bool flag;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            if(s[i]!=s[j]){
                if(2*j-i<n) flag=true;
                else flag=false;
                if((s[i]=='R' && s[j]=='G')||(s[i]=='G' && s[j]=='R')){
                    if(flag){
                        if(s[2*j-i]=='B') sum+=b_cnt[j+1]-1;
                        else sum+=b_cnt[j+1];
                    }else{
                        sum+=b_cnt[j+1];
                    }
                }else if((s[i]=='R' && s[j]=='B')||(s[i]=='B' && s[j]=='R')){
                    if(flag){
                        if(s[2*j-i]=='G') sum+=g_cnt[j+1]-1;
                        else sum+=g_cnt[j+1];
                    }else{
                        sum+=g_cnt[j+1];
                    }
                }else if((s[i]=='B' && s[j]=='G')||(s[i]=='G' && s[j]=='B')){
                    if(flag){
                        if(s[2*j-i]=='R') sum+=r_cnt[j+1]-1;
                        else sum+=r_cnt[j+1];
                    }
                    else{
                        sum+=r_cnt[j+1];
                    }
                }
            }
        }
    }
    // for(int i=0; i<n-2; i++){
    //     for(int j=i+1; j<n-1; j++){
    //         if(s[i]!=s[j]){
    //             for(int k=j+1; k<n; k++){
    //                 if(s[j]!=s[k] && s[k]!=s[i]){
    //                     if((j-i)!=(k-j)) sum += 1;
    //                 }
    //             }
    //         }
    //     }
    // }
    cout << sum << endl;
    return 0;
}