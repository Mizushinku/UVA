#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(void)
{
	int case_num = 1;
	string a, b;
	while(getline(cin,a)) {
		if(a == "#") break;
		getline(cin,b);
		int city[101][101] = {0};
		for(int i = 1; i <= a.length(); ++i)
		for(int j = 1; j <= b.length(); ++j) {
			if(a[i - 1] == b[j - 1]) city[i][j] = city[i - 1][j - 1] + 1;
			else city[i][j] = max(city[i - 1][j],city[i][j - 1]);
		}
		printf("Case #%d: you can visit at most %d cities.\n"
			   , case_num++, city[a.length()][b.length()]);
	}
	return 0;
}
