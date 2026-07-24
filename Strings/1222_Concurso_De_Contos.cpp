// https://judge.beecrowd.com/pt/problems/view/1222

#include <bits/stdc++.h>
using namespace std;
#define int long long
__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
    string resp = "";

    int palavras, lpaginas, caracteres;
    while(cin>>palavras>>lpaginas>>caracteres){
        int linhas = 1, linha = caracteres;
        for(int i = 0 ; i < palavras ; i++){
            string at; cin>>at;
            if(i == 0) linha-=at.size();
            else{
                if(linha > at.size()+1) linha-=at.size()+1;
                else if(linha == at.size()+1){
                    linhas++;
                    linha = caracteres+1;
                } else{
                    linhas++;
                    linha = caracteres - at.size();
                }
            }
        }
        if(linha == caracteres+1) linhas--;

        int paginas = linhas / lpaginas;
        if(linhas % lpaginas != 0) paginas++;
        resp+=to_string(paginas)+'\n';
    }

    cout<<resp;

    return 0;
}
