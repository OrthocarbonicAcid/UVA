//UVA 10114 - Loansome Car Buyer
//やった！

#include <bits/stdc++.h>

using namespace std;

double d[101];

int main(){
    double duration, downpayment, amount, depreciation;
    
    while(cin >> duration >> downpayment >> amount >> depreciation){
        memset(d, 0, sizeof(d));
        if(duration < 0) break;
        double monthly = amount/duration;
        double carValue = amount + downpayment;
        double owes = amount;

        for(int i = 0; i < depreciation; i++){
            int m;
            double v; cin >> m >> v;
            d[m] = v;
        }

        double curDep = d[0];
        carValue -= (carValue*curDep);

        for(int i = 1; i <= duration; i++){
            if(d[i] != 0) curDep = d[i];
            carValue -= (carValue*curDep);
            owes -= monthly;

            if(owes < carValue){
                cout << i << " month";
                if(i > 1) cout << "s";
                cout << endl;
                break;
            }
        }
    }

    return 0;
}

/*
30 500.0 15000.0 3
0 .10
1 .03
3 .002
12 500.0 9999.99 2
0 .05
2 .1
60 2400.0 30000.0 3
0 .2
1 .05
12 .025
-99 0 17000 1
*/
