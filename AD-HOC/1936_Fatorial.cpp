// https://judge.beecrowd.com/pt/problems/view/1936

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int fat(int n){
    int x = 1;
    for(n ; n > 0 ; n--) x *= n;
    return x;
}

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int obj; cin>>obj;

    vector<int> dp(obj+1, INT_MAX); dp[0] = 0;

    int at = 0;
    while(true){
        at++;
        int num = fat(at);
        if(num > obj) break;

        for(int i = 0 ; i <= obj ; i++){
            if(i + num <= obj && dp[i] != INT_MAX){
                dp[i + num] = min(dp[i + num], dp[i]+1);
            }
        }
    }

    cout<<dp[obj]<<endl;

    return 0;
}
