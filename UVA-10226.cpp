#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	int case_num;
	vector<string> v;
	string tree;
	
	cin >> case_num;
	getline(cin,tree); // a '\n'
	getline(cin,tree); // a blank
	while(case_num--) {
		int a = 1;
		while(a) {
			getline(cin,tree);
			if(tree != "\0") v.push_back(tree);
			else --a;
		}
		sort(v.begin(), v.end());
		int tot = v.size();
		for(int i = 0, count = 1; i < tot; ++i) {
			if(v[i] == v[i+1] && i != tot-1) ++count;
			else {
				cout << v[i] << ' ';
				printf("%.4f\n", (float)count / tot * 100);
				count = 1;
			}
		}
		if(case_num) cout << endl;
		v.clear();
	}
	return 0;
}
