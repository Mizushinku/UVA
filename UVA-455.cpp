#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int n;
	string s, gar;
	cin >> n;
	getline(cin,s); // a '\n'
	while(n) {
		getline(cin,s); // a blank
		getline(cin,s);
		int pi[80] = {0}, len = s.length(), count;
		pi[0] = -1;
		bool is_inc = false, is_match = false, fail = false;
		
		for(int i = 1, cur = -1; i < len; ++i) {
			//int pre = cur;
			while(~cur && s[i] != s[cur+1]) {
				cur = pi[cur];
			}
			if(s[i] == s[cur+1]) ++cur;
			pi[i] = cur;
			//cout << pre << ' ' << cur << endl;
			//if(pre < cur && !is_inc) { count = i; is_inc = true; }
			//if(pre > cur) { count = 0; is_inc = false; }

		}

		for(int i = 0; i < len; ++i) {
			count = i+1;
			if(len % count ==0) {
				for(int k = 0, cur = -1; k < len; ++k) {
					is_match = false;
					if(s[k] != s[cur+1]) {
						fail = true;
						while(~cur) cur = pi[cur];
					}
					if(fail) { fail = false; break; }
					if(s[k] == s[cur+1]) ++cur;
					if(cur+1 == count) {
						cur = -1;
						is_match = true;
					}
				}
			}
			if(is_match) break;
		}
		
		//for(int i = 0; i < len; ++i) cout << ' ' << pi[i];
		//cout << endl;
		
		cout << count << endl;
		//else cout << len << endl;
		if(n > 1)cout << endl;
		
		--n;
	}
	return 0;
}
