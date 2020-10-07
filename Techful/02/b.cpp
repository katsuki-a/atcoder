#include <bits/stdc++.h>
using namespace std;

int main(void){
    double x, y;
    double *p, *q;
    cin >> x >> y;
    p = &x;
    q = &y;
    cout << *p+*q << endl;
    cout << fixed << setprecision(1) << "x+y=" << std::round((*p+*q)*10)/10 << endl;
    return 0;
}