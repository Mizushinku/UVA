#include<iostream>
using namespace std;
void change_list(int);

#define max 7490
int dp[max];
int v[4] = {5,10,25,50};

int main(void)
{
	for(int i = 0; i < max; ++i) dp[i] = 1;
	for(int i = 0; i < 4; ++i) change_list(v[i]);
	int cent;
	while(cin >> cent) {
		cout << dp[cent] << endl;
	}
	return 0;
}

void change_list(int v)
{
	for(int i = v; i < max; ++i ) {
		if(dp[i - v]) dp[i] += dp[i - v];
	}
}
