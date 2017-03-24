#include<iostream>
#include<cstdio>
using namespace std;

int exGCD(int a, int b, int *X, int *Y)
{
	if(b == 0) {
		*X = 1;
		*Y = 0;
		return a;
	} else {
		int gcd = exGCD(b, a % b, X, Y);
		int tmp = *X;
		*X = *Y;
		*Y = tmp - (a/b) * (*Y);
		return gcd;
	}
}

int main(void)
{
	int a, b;
	while(cin >> a && cin >> b) {
		int X, Y, D;
		D = exGCD(a,b,&X,&Y);
		printf("%d %d %d\n", X, Y, D);
	}
	return 0;
}
