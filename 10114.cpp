//UVA 10114 - Loansome Car Buyer
//やった！
#include <bits/stdc++.h>

using namespace std;

int main() {
	int duration, depreciation;
	double downPayment, loan, d[101];

	while(true){
		cin >> duration >> downPayment >> loan >> depreciation;
		if (duration < 0)
			break;

		int m;
		double p;
		for(int i = 0; i < depreciation; i++){
			cin >> m >> p;
			for (int i = m; i < 101; i++)
				d[i] = p;
		}

		int now = 0;
		double monthly = loan / duration;
		double curVal = (loan + downPayment) * (1 - d[0]);
		double curLoan = loan;
		while (curVal < curLoan) {
			now++;
			curLoan -= monthly;
			curVal = curVal * (1-d[now]);
		}

		cout << now << " month";
		if (now > 1) cout << "s";
		cout << endl;
	}

	return 0;
}
