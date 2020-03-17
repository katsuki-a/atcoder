#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    string str;
    cin >> n;
    for(int i=1; i<n+1; i++){
        str = "";
        if(i%2==0) str+="a";
        if(i%3==0) str+="b";
        if(i%4==0) str+="c";
        if(i%5==0) str+="d";
        if(i%6==0) str+="e";
        if(str.empty()) str+=to_string(i);
        cout << str << endl;
    }
    return 0;
}