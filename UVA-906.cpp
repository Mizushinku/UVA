#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	long long int a, b, c, d;
	double n;
	while(cin >> a >> b >> n) {
		for(d = 1; ;++d) {
			long double x = (long double)a/b;
			c = (long long int)(x * d);
			while(a * d >= c * b) ++c;
			if((long double)c/d - x <= n) {
				printf("%lld %lld\n", c, d);
				break;
			}
		}
	}
	return 0;
}
