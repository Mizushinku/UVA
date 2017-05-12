/***
* 存入setA後,逐一檢查setB的element是否為setA各個element的倍數（小心0）
* 若是倍數則建邊,最終完成二分圖
* 找最大點覆蓋
***/
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

#define k 110

bool DFS(int);

int llink[k], rlink[k], vis[k], setA[k];
vector<int> edge[k];

int main(void)
{
	int case_cnt, case_num = 1, n, m, b;
	scanf("%d", &case_cnt);
	while(case_cnt--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &setA[i]);
		scanf("%d", &m);
		for(int i = 1; i <= m; ++i) {
			scanf("%d", &b);
			for(int j = 1; j <= n; ++j) {
				if(setA[j] == 0) {
					if(b == 0) edge[j].push_back(i);
				}
				else if(b % setA[j] == 0) edge[j].push_back(i);
			}
		}

		int ans = 0;
		memset(llink,0,sizeof(llink));
		memset(rlink,0,sizeof(rlink));
		for(int i = 1; i <= n; ++i) {
			memset(vis,0,sizeof(vis));
			if(DFS(i)) ++ans;
		}
		printf("Case %d: %d\n", case_num++, ans);
		//init
		for(int i = 1; i <= n; ++i) edge[i].clear();
	}
	return 0;
}

bool DFS(int cur)
{
	int next;
	for(int i = 0; i < edge[cur].size(); ++i) {
		next = edge[cur][i];
		if(!vis[next]) {
			vis[next] = 1;
			if(!rlink[next] || DFS(rlink[next])) {
				llink[cur] = next;
				rlink[next] = cur;
				return true;
			}
		}
	}
	return false;
}
