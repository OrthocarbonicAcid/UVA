//UVA 11222 - Only I did it!
//やった！

#include <bits/stdc++.h>

using namespace std;

void solve(){
    map<int, int>prob;
    set<int>a, b, c;
    int sa, sb, sc;

    cin >> sa;
    for(int i = 0; i < sa; i++){
        int x; cin >> x;
        if(a.count(x) == 0)
            prob[x]++;
        
        a.insert(x);
    }   

    cin >> sb;
    for(int i = 0; i < sb; i++){
        int x; cin >> x;
        if(b.count(x) == 0)
            prob[x]++;
        
        b.insert(x);
    }  

    cin >> sc;
    for(int i = 0; i < sc; i++){
        int x; cin >> x;
        if(c.count(x) == 0)
            prob[x]++;
        
        c.insert(x);
    }  

    vector<int>prob_a, prob_b, prob_c;

    for(auto x : a){
        if(prob[x] == 1)
            prob_a.push_back(x);
    }

     for(auto x : b){
        if(prob[x] == 1)
            prob_b.push_back(x);
    }   

    for(auto x : c){
        if(prob[x] == 1)
            prob_c.push_back(x);
    }

    sa = prob_a.size();
    sb = prob_b.size();
    sc = prob_c.size();

    if(sa >= sb && sa >= sc){
        cout << "1 " << sa;
        
        for(int i = 0; i < sa; i++){
            cout << " " << prob_a[i];
        }
        cout << endl;
    }

    if(sb >= sa && sb >= sc){
        cout << "2 " << sb;
        
        for(int i = 0; i < sb; i++){
            cout << " " << prob_b[i];
        }
        cout << endl;
    }
  
    if(sc >= sb && sc >= sa){
        cout << "3 " << sc;
        
        for(int i = 0; i < sc; i++){
            cout << " " << prob_c[i];
        }
        cout << endl;
    }
}

int main(){
    int tc; cin >> tc;

    for(int t = 1; t <= tc; t++){
        cout << "Case #" << t << ":" << endl;
        solve();
    }

    return 0;
}
