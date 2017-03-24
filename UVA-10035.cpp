#include<iostream>
#include<string>
#include<vector>
using namespace std;

unsigned int num1[15] = {0}, num2[15] = {0};

void into_digit(unsigned int n, unsigned int num[15])
{
	unsigned int tmp = n;
	for(int i = 0; n; ++i) {
		tmp %= 10;
		num[i] = tmp;
		n /= 10;
		tmp = n;
	}
}

int main(void)
{
	unsigned int a, b;
	while(cin >> a >> b && a + b != 0) {
		into_digit(a,num1); into_digit(b,num2);
		unsigned int count = 0, sum[15] = {0};
		for(int i = 0; i < 15; ++i) {
			sum[i] += num1[i] + num2[i];
			if(sum[i] >= 10) {
				++sum[i+1];
				sum[i] %= 10;
				++count;
			}
		}
		switch(count) {
			case 0: cout << "No carry operation." << endl; break;
			case 1: cout << count << " carry operation." << endl; break;
			default : cout << count << " carry operations." << endl; break;
		}
		for(int i = 0; i < 15; ++i) { num1[i] = 0; num2[i] = 0; sum[i] = 0; }
	}
	return 0;
}
