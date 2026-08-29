// https://judge.beecrowd.com/pt/problems/view/1030

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

__int32_t main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int nc, n, k, caso = 1; cin>>nc;
    
    while(nc--){
        cin>>n>>k;
        vector<int> conj(n);
        for(int i = 0 ; i < n ; i++) conj[i] = i;
        
        int sup = n, cont = 0; 
        while(long(conj.size()) != 1){
            sup++; cont++;
            if(sup > long(conj.size())) sup -= long(conj.size());
            
            
            if(cont == k){
                conj.erase(conj.begin()+sup-1);
                cont = 0;
                sup--;
            }
        }
        
        cout<<"Case "<<caso<<": "<<conj[0]+1<<endl;
        caso++;
    }
    
    return 0;
}
