// https://judge.beecrowd.com/pt/problems/view/1301

#include <bits/stdc++.h>
using namespace std;

int tamanho, casos;
vector<int> vt;
vector<map<int, int>> bit;
 
int lowbit(int i){
    return i&-i;
}

int conver(int x){
    int r;
    if(x == 0) r = 0;
    else if(x > 0) r = 1;
    else r = -1;
    return r;
}

void update_ini(int i, int x){
    int r = conver(x);

    while(i <= tamanho){
        bit[i][r]++;
        i+=lowbit(i);
    }
}

void update(int i, int x){
    int r = conver(x);

    if(vt[i] == 0){
        vt[i] = r;
        while(i <= tamanho){
            bit[i][0]--;
            bit[i][r]++;
            i+=lowbit(i);
        }
        return ;
    } else if(vt[i] == -1){
        vt[i] = r;
        while(i <= tamanho){
            bit[i][-1]--;
            bit[i][r]++;
            i+=lowbit(i);
        }
        return ;
    } else{
        vt[i] = r;
        while(i <= tamanho){
            bit[i][1]--;
            bit[i][r]++;
            i+=lowbit(i);
        }
        return ;
    }
}

map<int, int> query(int i){
    map<int, int> mp = {{-1, 0}, {0, 0}, {1, 0}};

    while(i){
        for(int in = -1 ; in <= 1 ; in++){
            mp[in] += bit[i][in];
        }
        i-=lowbit(i);
    }

    return mp;
}

int product(int l, int r){
    map<int, int> mp_l = query(l-1), mp_r = query(r), mp_final = {{-1, 0}, {0, 0}, {1, 0}};

    for(int i = -1 ; i <= 1 ; i++){
        mp_final[i] += mp_r[i] - mp_l[i];
    }

    if(mp_final[0] > 0) return 0;
    if(mp_final[-1] % 2 == 0) return 1;
    else return -1;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    string resp = "";

    while(cin>>tamanho>>casos){
        bit.clear(); vt.clear();

        bit.resize(tamanho+1); vt.resize(tamanho+1);
        for(int i = 1 ; i <= tamanho ; i++){
            int n; cin>>n;
            int con = conver(n);
            vt[i]=con;
            update_ini(i, n);
        }

        for(int caso = 0 ; caso < casos ; caso++){
            char car; cin>>car;
            if(car == 'C'){
                int i, x; cin>>i>>x;
                update(i, x);
            } else {
                int l, r; cin>>l>>r;
                int re = product(l, r);
                if(re == 0) resp+='0';
                else if(re == -1) resp+='-';
                else resp+='+';
            }
        }

        resp+="\n";
    }

    cout<<resp;

    return 0;
}
