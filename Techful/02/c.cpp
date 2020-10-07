#include <bits/stdc++.h>
using namespace std;

int is_prime(int a){
    if(a<2) return 0;
    for(int i=2; i<a; i++){
        if(a%i==0) return 0;
    }
    return 1;
}

int main(void){
    int i, x, y;
    int *p;
    cin >> i;
    p = &i;
    for(int j=0; j<*p-1; j++){
        x = is_prime(*p-j);
        y = is_prime(*p+j);
        if(j!=0 && x*y==1){
            printf("%dに最も近い素数は%dと%dです。\n", *p, *p-j, *p+j);
            return 0;
        }else if(x==1){
            printf("%dに最も近い素数は%dです。\n", *p, *p-j);
            return 0;
        }else if(y==1){
            printf("%dに最も近い素数は%dです。\n", *p, *p+j);
            return 0;
        }
    }
    return 0;
}