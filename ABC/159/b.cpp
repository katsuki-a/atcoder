#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    // cout << s.size() << endl;
    int n=s.size();
    int half=(n+1)/2;
    char c;
    int i=1;
    while(true){
        c = s[i-1];
        cout << s[i-1] << " " << s[half-i-1] << " " << s[half+i-1] << " " << s[n-i] << endl;
        if(s[half-i-1]==c && s[half+i-1]==c && s[n-i]==c){
            if(i==half-i){
                cout << "Yes" << endl;
                return 0;
            }else{
                i += 1;
            }
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
}