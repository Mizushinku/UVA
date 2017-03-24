#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	unsigned long long N, M;
	while(cin >> N >> M && N != 0 && M != 0) {
		if(N > M) swap(N,M);
		unsigned long long ans = 0;
		ans += N * M * (N+M-2);
		if(N == 1) { cout << ans << endl; continue; }
		for(unsigned long long i = 2; i < N; ++i) {
			ans += 4 * ( i * (i-1) );
		}
		unsigned long long tmp = M - N + 1;
		ans += tmp * 2 * (N * (N-1));
		cout << ans << endl;
	}
	return 0;
}
