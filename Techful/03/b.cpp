#include <bits/stdc++.h>
using namespace std;

int main(void){
    double* x = (double*)malloc(sizeof(double));
    double* y = (double*)malloc(sizeof(double));
    scanf("%lf %lf", x, y);
    double z = (*x)*(*y);
    cout << fixed << setprecision(2) << std::round(z*100)/100 << endl;
    free(x);
    free(y);
    return 0;
}