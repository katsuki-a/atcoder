#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, cnt=0;
    cin >> n;
    for(long long i=1; i<n+1; i++){
        if(i%3!=0 && i%5!=0) cnt += i;
    }
    cout << cnt << endl;
    return 0;
}