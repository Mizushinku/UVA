#include<iostream>
#include<cstdio>
using namespace std;
void Queen_pos(int,int);

int ans = 0;
int board[8][8] = {0};
bool Q_row[8], Q_slash[15], Q_back_slash[15];

int main(void)
{
	int k;
	cin >> k;
	for(int i = 0; i < k; ++i) {
		for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			cin >> board[i][j];
		for(int i = 0; i < 8; ++i) Q_row[i] = true;
		for(int i = 0; i < 15; ++i) { 
			Q_slash[i] = true;
			Q_back_slash[i] = true;
		}
		Queen_pos(0,0);
		printf("%5d\n", ans);
		ans = 0;
		for(int i = 0; i < 8; ++i) Q_row[i] = true;
		for(int i = 0; i < 15; ++i) { 
			Q_slash[i] = true;
			Q_back_slash[i] = true;
		}
	}
	return 0;
}

void Queen_pos(int col, int tmp)
{
	if(col == 8) {
		if(tmp > ans) ans = tmp;
		return;
	}
	for(int i = 0; i < 8; ++i) {
		if(Q_row[i] && Q_slash[i+col] && Q_back_slash[7-i+col]) {
			Q_row[i] = false;
			Q_slash[i+col] = false;
			Q_back_slash[7-i+col] = false;
			
			tmp += board[i][col];
			Queen_pos(col + 1,tmp);
			tmp -= board[i][col];
			
			Q_row[i] = true;
			Q_slash[i+col] = true;
			Q_back_slash[7-i+col] = true;

		}
	}
}

