#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

void backtrack(int);
vector<int> v;
int a[6] = {0};
bool no_first_data = false;

int main(void)
{
	int k;
	while(cin >> k && k != 0) {
		if(no_first_data) printf("\n");
		no_first_data = true;
		int n;
		for(int i = 0; i < k; ++i) {
			cin >> n;
			v.push_back(n);
		}
		backtrack(0);
		v.clear();
		for(int i = 0; i < 5; ++i) a[i] = 0;
	}
	return 0;
}

void backtrack(int count)
{
	if(count == 6) {
		for(int i = 0; i < 6; ++i) {
			printf("%d", a[i]);
			if(i < 5) printf(" ");
			else printf("\n");
		}
		return;
	}
	for(int i = count;i < v.size() ;++i) {
		if(count == 0 || v[i] > a[count - 1]) {
			a[count] = v[i];
			backtrack(count+1);
		}
	}
	return;
}
