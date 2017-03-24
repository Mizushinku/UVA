#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	long int n;
	while(cin >> n && n != 0)
	{
		long int ans, tmp, d, t, c = 0, k = 1;
		while(n > k) { k *= 2; ++c; }
		ans = k; tmp = k;
		for(int i = 2; i <= c; ++i) {
			d = pow(2,i);
			for(t = 3; t <= d; t *= 3) {
				tmp = k / d * t;
				if(tmp < ans && tmp >= n) ans = tmp;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
