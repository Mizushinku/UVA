#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<cctype>
using namespace std;

int main(void)
{
	int case_num = 1;
	string a, b;
	while(getline(cin,a) && getline(cin,b)) {
		if(a.length() == 0 || b.length() == 0) {
			printf("%2d", case_num);
			cout << ". Blank!" << endl;
			++case_num;
			continue;
		}

		string Ma[1000], Mb[1000];
		int tmp1, tmp2, i, j;
		for(i = 0, j = 0; i < a.length(); ++i) {
			if(!isalnum(a[i])) continue;

			else {
				while(isalnum(a[i]))
					Ma[j] += a[i++];
				--i; ++j;
			}
		}
		tmp1 = j;
		//for(int i = 0; i < 3; ++i) cout << Ma[i] << endl;
		for(i = 0, j = 0; i < b.length(); ++i) {
			if(!isalnum(b[i])) continue;
			
			else {
				while(isalnum(b[i]))
					Mb[j] += b[i++];
				--i; ++j;
			}
		}
		tmp2 = j;
		//for(int i = 0; i < 3; ++i) cout << Mb[i] << endl;
		/*if(tmp1 == -1 || tmp2 == -1) {
			printf("%2d", case_num);
			cout << ". Length of longest match: " 
				 << 0 << endl;
			++case_num;
			continue;
		}*/
		int LCS[1100][1100];
		memset(LCS,0,sizeof(LCS));
		//for(int i = 0; i < 100; ++i) cout << LCS[1099][999+i]+i << endl;
		//for(int i = 0; i < tmp1; ++i) LCS[i][0] = 0;
		//for(int i = 0; i < tmp2; ++i) LCS[0][i] = 0;
		
		for(i = 1; i <= tmp1; ++i)
		for(j = 1; j <= tmp2; ++j) {
			if(Mb[j-1] == Ma[i-1]) {
				LCS[i][j] = LCS[i-1][j-1] + 1;
			}
			else if(LCS[i-1][j] > LCS[i][j-1]) LCS[i][j] = LCS[i-1][j];
				 else LCS[i][j] = LCS[i][j-1];
		}
		printf("%2d", case_num);
		cout << ". Length of longest match: " 
			 << LCS[tmp1][tmp2] << endl;
		++case_num;
	}
	return 0;
}
