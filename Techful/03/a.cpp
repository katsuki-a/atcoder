#include <bits/stdc++.h>
using namespace std;

int main(void){
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    scanf("%d %d", x, y);
    int z = *x+*y;
    cout << z << endl;
    free(x);
    free(y);
    return 0;
}