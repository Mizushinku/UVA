#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

vector<long long int> prime;

bool isprime(long long int n)
{
	for(long long int i = 0; prime[i] <= sqrt(n) && i+1 <= prime.size(); ++i) {
		if(n % prime[i] == 0) return false;
	}
	return true;
}



int main(void)
{
	long long int x;
	while(cin >> x && x >= 0) {
		prime.push_back(2); while(x % 2 == 0) { cout << "    " << 2 << endl; x /= 2; }
		prime.push_back(3); while(x % 3 == 0) { cout << "    " << 3 << endl; x /= 3; }
		for(long long int i = 5, gap = 2; i <= 1000000; i +=gap, gap = 6 - gap)
		if(isprime(i)) {
			prime.push_back(i);
			while(x % i == 0) {
				cout << "    " << i << endl;
				x /= i;
			}
		}
		if(x > 1000000) cout << "    " << x << endl;
		cout << "\n";
		prime.clear();
	}

	return 0;
}
