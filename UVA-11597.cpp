/***
* 輸入n表示有n個點,共有Cn取2條邊
* 輸出為這些編共可以建出幾顆最小生成樹,每棵樹的任一邊都不共用
* 輸入0結束程式
***/
#include<cstdio>
using namespace std;

int main(void)
{
	int X = 1, n;
	while(scanf("%d", &n) && n) {
		printf("Case %d: %d\n", X++, n/2);
	}
	return 0;
}
