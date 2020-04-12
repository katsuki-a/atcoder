#include <bits/stdc++.h>
using namespace std;

long gcd(long a, long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int main(){
    long n, sum=0;
    cin >> n;
    for(long i=1; i<n+1; i++){
        for(long j=1; j<n+1; j++){
            for(long k=1; k<n+1; k++){
                sum += gcd(gcd(i, j), k);
            }
        }
    }
    cout << sum << endl;
    return 0;
}