#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	while(getline(cin,s)) {
		if(s == ".") break;
		
		bool is_match = false, is_fail = false;
		int sublen;
		for(int i = 0; i < s.length() && !is_match; ++i) {
			sublen = i + 1;
			if(s.length() % sublen == 0) {
				for(int j = 0, k = 0; j < s.length(); ++j, ++k) {
					if(s[j] != s[k]) break;
					if(k+1 == sublen) k = -1;
					if(j+1 == s.length()) is_match = true;
				}
			}
		}
		cout << s.length()/sublen << endl;
	}
	return 0;
}
