#include<iostream>
#include<string>
using namespace std;


int main(void)
{
	string num1;
	while(getline(cin,num1)) {
		int a[250] = {0}, b[250] = {0}, c[500] = {0};
		int i, j, k, tmp, count_1, count_2;
		string num2;
		getline(cin,num2);
		count_1 = num1.length() - 1;
		count_2 = num2.length() - 1;
		tmp = count_1;
		for(i = 0; tmp >= 0; --tmp, ++i) a[i] = num1[tmp] - '0';
		tmp = count_2;
		for(i = 0; tmp >= 0; --tmp, ++i) b[i] = num2[tmp] - '0';
		for(i = 0; i <= count_1; ++i) {
				k = i;
				if(a[i] == 0) continue;
				for(j = 0; j <= count_2; ++j, ++k) {
						c[k] += a[i] * b[j];
				}
		}
		for(i = 0; i < 500; ++i) 
				if(c[i] >= 10) {
						c[i+1] += c[i] / 10;
						c[i] %= 10;
				}
		for(i = 499; i > 0; --i) if(c[i] != 0) break;
		for(; i >= 0; --i) cout << c[i];
		cout << "\n";
	}
	return 0;
}
