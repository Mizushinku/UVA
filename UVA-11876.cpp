#include<iostream>
#include<vector>
using namespace std;
void build_the_prime(void);
bool isprime(int);
void NOD(int);
int bis(int,int,int);

vector<int> prime, S;

int main(void)
{
	int case_num, c = 1;
	cin >> case_num;
	build_the_prime();
	NOD(1000000);
	while(c <= case_num) {
		int A, B, start, end;
		int len = S.size() - 1;
		cin >> A >> B;
		start = bis(0,len,A);
		if(S[start] < A) ++start;
		end = bis(start-1,len,B);
		//cout << end << '\t' << S[end] << endl;
		while(S[end] <= B) ++end;
		//cout << "start = " << start << '\t' << S[start] << endl
		//	 << "end = " << end << '\t' << S[end] << endl;
		cout << "Case " << c++ << ": " << end - start << endl;
	}
	return 0;
}

int bis(int left, int right, int T)
{
	while(left < right) {
		if(T == S[left]) return left;
		if(T == S[right]) return right;
		int mid = (left + right) / 2;
		if(T <= S[mid]) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

void NOD(int B) //this B means the max of input B. Not the cin's B.
{
	S.push_back(1);
	for(int j = 0; S[j] <= B; ++j) {
		int nod = 1, power = 1, tmp = S[j];
		for(int i = 0; tmp != 1 && i < prime.size(); ++i) {
				while(tmp % prime[i] == 0) {
						tmp /= prime[i];
						++power;
				}
				nod *= power;
				power = 1;
		}
		S.push_back(S[j]+nod);
	}
	return;
}

void build_the_prime(void)
{
	prime.push_back(2);
	prime.push_back(3);
	for(int i = 5, gap = 2; i < 999999; i += gap, gap = 6 - gap)
		if(isprime(i)) prime.push_back(i); 
}

bool isprime(int n)
{
	for(int i = 0; prime[i] * prime[i] <= n && i < prime.size(); ++i) {
		if(n % prime[i] == 0) return false;
	}
	return true;
}
