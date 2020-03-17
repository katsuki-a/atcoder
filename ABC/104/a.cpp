#include <bits/stdc++.h>
using namespace std;

int calc(std::vector<int> ans, std::vector<int> c, std::vector<int> p){
    int res=0;
    for(int i=0; i<ans.size(); i++){
        res += 100*(i+1)*ans[i];
        if(ans[i]==c[i]) res += p[i];
    }
    return res;
}

int dfs(int i, int last, int min, std::vector<int> ans, std::vector<int> c, std::vector<int> p, int g){
    int res, calc_res;
    // for(int j=0; j<last; j++){
    //     cout << ans[j] << " ";
    // }
    // cout << endl;
    res = std::accumulate(ans.begin(), ans.end(), 0);
    if(res>=min) return min;
    if(i==last){
        calc_res = calc(ans, c, p);
        if(calc_res>=g) return res;
        else return min;
    }
    for(int j=0; j<c[i]+1; j++){
        ans[i] = j;
        res = dfs(i+1, last, min, ans, c, p, g);
        if(res<min) min=res;
    }
    return min;
}

bool solve(int i, int prob, int point, std::vector<int> c, std::vector<int> p, int d, int g){
    if((i==d)||(prob==0)) return false;
    int new_point;
    for(int j=0; j<prob+1; j++){
        new_point = point;
        new_point += (i+1)*100*j;
        if(j==c[i]) new_point += p[i];        
        if(new_point>=g) return true;
        if(i<d) if(solve(i+1, prob-j, new_point, c, p, d, g)) return true;
    }
    return false;
}

int main(void){
    int d, g, a, b;
    int all = 0;
    std::vector<int> c;
    std::vector<int> p;
    std::vector<int> ans;
    cin >> d >> g;
    for(int i=0; i<d; i++){
        cin >> a >> b;
        c.push_back(a);
        p.push_back(b);
        ans.push_back(0);
    }
    // int min = std::accumulate(c.begin(), c.end(), 0);
    // std::vector<int> test_c = {3, 5};
    // std::vector<int> test_p = {500, 800};
    // cout << dfs(0, d, min, ans, c, p, g) << endl;
    // cout << d << " " << g << endl;
    for(int prob=1; prob<std::accumulate(c.begin(), c.end(), 0)+1; prob++){
        if(solve(0, prob, 0, c, p, d, g)){
            cout << prob << endl;
            return 0;
        }
    }
    return 0;

}