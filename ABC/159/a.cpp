#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n){
    long long res=1;
    for(long long i=1; i<n+1; i++){
        res *= i;
    }
    return res;
}

int main(void)
{
    long long m, n;
    cin >> n >> m;
    long long res;
    cout << n*(n-1)/2+m*(m-1)/2 << endl;
}