// https://judge.beecrowd.com/pt/problems/view/1244

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

struct Palavra {
    string st;
    int pos;
    int tam;

    bool operator>(const Palavra &other) const {
        if(tam != other.tam) return tam > other.tam;
        else return pos < other.pos;
    }
};

vector<Palavra> conju;

__int32_t main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin>>n; cin.ignore();

    while(n--){
        int pos = 1;
        string st; getline(cin, st);

        string pa = "";
        for(auto &c:st){
            if(c == ' '){
                if(!pa.size()) continue;
                conju.push_back({pa, pos, long(pa.size())});
                pos++;
                pa = "";
            } else pa += c;
        } 
        if(long(pa.size()) != 0)conju.push_back({pa, pos, long(pa.size())});

        sort(conju.begin(), conju.end(), greater());
        for(int i = 0 ; i < conju.size() ; i++){
            cout<<conju[i].st;
            if(i+1 != conju.size()) cout<<' ';
        }
        cout<<endl;
        conju.clear();
    }

    return 0;
}
