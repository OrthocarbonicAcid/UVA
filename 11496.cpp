//UVA 11496 - Musical Loop
//やった！

#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    int arr[n+1];
    int ans = 0;
    bool up, down;
    up = down = false;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    if(arr[n-1] < arr[0])
        up = true;
    
    else
        down = true;
    
    arr[n] = arr[0];

    for(int i = 1; i <= n; i++){
        if(arr[i] > arr[i-1] && down){
            ans++;
            down = false;
            up = true;
        } else if(arr[i] < arr[i-1] && up){
            ans++;
            down = true;
            up = false;
        }
    }

    cout << ans << endl;
}

int main(){
    int n;

    while(cin >> n){
        if(n == 0)
            break;
        
        solve(n);
    }

    return 0;
}
