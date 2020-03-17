#include <bits/stdc++.h>
using namespace std;

int main(void){
    long a, b, cnt=0;
    string num;
    cin >> a >> b;
    for(long i=a; i<b+1; i++){
        num = to_string(i);
        for(long j=0; j<num.size(); j++){
            if(num[j]=='4' || num[j]=='9'){
                cnt+=pow(10, num.size()-j-1);
                i+=pow(10, num.size()-j-1);
                // cout << e << endl;
                break;
            }
        }
    }
    cout << cnt << endl;
}