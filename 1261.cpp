#include <iostream>
#include <string>
using namespace std;

bool recur(string str)
{
	if(str.size() == 0) return true;

	int i = 0;
	while(i < str.size()) {
			int cnt = 0;
			for(int j = i; j < str.size(); j++) {
				if(str[j] == str[i]) cnt++;
				else break;
			}

			if(cnt != 1) {
				string t = str;
				t.erase(t.begin() + i, t.begin() + i + cnt);
				if(recur(t)) return true;
			}

			i += cnt;
	}

	return false;
}

int main()
{
	int N;
	cin >> N;
	while(N--) {
		string s;
		cin >> s;
		cout << recur(s) << endl;
	}
}