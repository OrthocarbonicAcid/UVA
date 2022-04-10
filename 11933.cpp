//UVA 11933 - Splitting Numbers
//やった！

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<int>v;

        for(int i = 0; i < 32; i++){
            if(n & (1<<i))
                v.push_back(i);
        }

        int a = 0, b = 0;

        for(int i = 0; i < v.size(); i += 2){
            a += (1<<v[i]);
        }

        for(int i = 1; i < v.size(); i += 2){
            b += (1<<v[i]);
        }

        cout << a << " " << b << "\n";
    }

    return 0;
}
