#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cstdlib>
using namespace std;

vector<string> cont[2];

int main(void)
{
	string cer;
	int a = 0;
	while(cin >> cer) {
		if(cer == "#") {
			++a;
			if(a < 2)continue;
		}
		else {
			cont[a].push_back(cer);
			continue;
		}
		int len1 = cont[0].size(), len2 = cont[1].size();
		int LCS[101][101] = {0};
		char pre[101][101];
		for(int i = 1; i <= len1; ++i)
		for(int j = 1; j <= len2; ++j) {
			if(cont[0][i-1] == cont[1][j-1]) {
				LCS[i][j] = LCS[i-1][j-1] + 1;
				pre[i][j] = 'S';
			}
			else if(LCS[i][j-1] > LCS[i-1][j]) {
				 	LCS[i][j] = LCS[i][j-1];
					pre[i][j] = '<';
				 }
			else {
				LCS[i][j] = LCS[i-1][j];
				pre[i][j] = '^';
			}
		}
		stack<string> lcs_cont;
		while(len1 > 0 && len2 > 0) {
			switch(pre[len1][len2]) {
				case 'S':
					lcs_cont.push(cont[0][len1-1]);
					--len1; --len2;
					break;
				case '<':
					--len2;
					break;
				case '^':
					--len1;
					break;
				default :
					cout << "wrong char!" << endl;
					exit(1);
			}
		}
		while(!lcs_cont.empty()) {
			if(lcs_cont.size() == 1) cout << lcs_cont.top() << endl;
			else cout << lcs_cont.top() << ' ';
			lcs_cont.pop();
		}
		
		//init
		a = 0; cont[0].clear(); cont[1].clear();
	}
	return 0;
}
