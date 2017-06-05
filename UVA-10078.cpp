/***
* 檢查圖形是不是凸包,因為題目給點已經有順序,所以按照輸入測資繞一圈檢查外積
* 若有一個地方的外積與前面異號,則圖形不是凸包
* 記得外積(Pn-1 - Pn-2) X (P - Pn-2) 需要繞回起點--> Pn-2 = node[N-1]的地方
* 因所有node都是邊邊角角的點--> 沒有邊上的點--> 外積不為零,所以不考慮外積 = 0
***/
#include<cstdio>
using namespace std;

struct Node {
	int x, y;
}node[55];

int cross(const int&, const int&, const int&);

int main(void)
{
	int N;
	while(scanf("%d", &N) && N) {
		bool flag = false;
		for(int i = 0; i < N; ++i) {
			scanf("%d %d", &node[i].x, &node[i].y);
		}
		node[N] = node[0]; //記得要繞回起點
		node[N+1] = node[1];
		if(cross(0,1,2) > 0) {
			for(int i = 3; i < N+2; ++i) {
				if(cross(i-2,i-1,i) < 0) {
					flag = true;
					break;
				}
			}
		}
		else {
			for(int i = 3; i < N+2; ++i) {
				if(cross(i-2,i-1,i) > 0) {
					flag = true;
					break;
				}
			}
		}
		
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

int cross(const int& p, const int& a, const int& b)
{
	return (node[a].x-node[p].x)*(node[b].y-node[p].y) - (node[a].y-node[p].y)*(node[b].x-node[p].x);
}
