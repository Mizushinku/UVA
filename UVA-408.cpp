#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int,int);

int main(void)
{
	int a, b, r;
	while(cin >> a && cin >> b) {
		r = gcd(a,b);
		printf("%10d%10d", a, b);
		if(r == 1) printf("    Good Choice\n\n");
		else printf("    Bad Choice\n\n");
	}
	return 0;
}

int gcd(int a, int b)
{
	if(a == 0) return b;
	gcd(b % a, a);
}
