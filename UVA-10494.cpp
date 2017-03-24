#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

void division(long long, char);

queue< long long> q, ans;

int main(void)
{
	string s;
	while(getline(cin,s)) {
		char opera;
		long long n = 0;
		int i;
		for(i = 0; ; ++i) {
			if(s[i] == ' ') {
				if(s[i + 1] != ' ') break;
				else continue;
			}
			q.push(s[i] - '0');
		}
		if(q.front() == 0) { 
			printf("0\n");  
			while(!q.empty()) q.pop();
			continue;
		}
		
		opera = s[++i];
		while(s[i+1] == ' ') ++i;
		
		for( ++i; i < s.length(); ++i) {
			n += s[i] - '0';
			if(i == s.length() -1) break;
			n *= 10;
		} 
		division(n, opera);
		while(!q.empty()) q.pop();
		while(!ans.empty()) ans.pop();
	}
	return 0;
}

void division(long long n, char opera)
{
	long long x = 0, tmp = 0, quo = 0;
	while(!q.empty()) {
		while(tmp < n) {
			x += q.front();
			q.pop();
			if(x >= n) break;
			ans.push(0);
			if(q.empty()) break;
			tmp = x;
			x *= 10;
		} 
		tmp = 0;
		quo = x / n;
		if(x >= n) ans.push(quo);
		x -= n * quo;
		if(!q.empty()) x *= 10;
	}
	if(opera == '/') {
		while(ans.front() == 0) { 
			ans.pop();
			if(ans.empty()) {
				printf("0");
				break;
			}
		}
		while(!ans.empty()) {
			printf("%lld", ans.front());
			ans.pop();
		}
	}
	else printf("%lld", x);
	printf("\n");
}

