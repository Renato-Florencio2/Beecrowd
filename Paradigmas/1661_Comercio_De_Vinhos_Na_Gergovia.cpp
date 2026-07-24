// https://judge.beecrowd.com/pt/problems/view/1661

#include <bits/stdc++.h>
using namespace std;
#define int long long
__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
    string resp = "";

    int tam;
    while(cin>>tam && tam != 0){
        stack<pair<int, int>> compra, venda;
        int custo = 0;
        for(int i = 1 ; i <= tam ; i++){
            int x; cin>>x;
2
            if(x == 0) continue;
            else {
                if(x < 0) venda.push({i, x*-1});
                else compra.push({i, x});

                while(!venda.empty() && !compra.empty()){
                    if(venda.top().second < compra.top().second){
                        compra.top().second -= venda.top().second;
                        custo += (max(venda.top().first, compra.top().first) - min(venda.top().first, compra.top().first))*venda.top().second;
                        venda.pop();
                    } else if(venda.top().second > compra.top().second){
                        venda.top().second -= compra.top().second;
                        custo += (max(venda.top().first, compra.top().first) - min(venda.top().first, compra.top().first))*compra.top().second;
                        compra.pop();
                    } else{
                        custo += (max(venda.top().first, compra.top().first) - min(venda.top().first, compra.top().first))*compra.top().second; 
                        venda.pop(); compra.pop();
                    }
                }
            } 
        }

        resp += to_string(custo) + '\n';
    }

    cout<<resp;

    return 0;
}
