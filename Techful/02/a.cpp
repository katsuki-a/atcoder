#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i;
    int *p;
    cin >> i;
    p = &i;
    printf("i=%d\n", i);
    printf("*p=%d\n", *p);
    return 0;
}