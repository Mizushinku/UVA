/***
* bolt 與 nut 的二分圖,照題目給的測資建邊
* 找最大匹配數
***/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

#define k 510

bool DFS(int);

int llink[k], rlink[k], vis[k];
vector<int> edge[k];

int main(void)
{
	int case_num, n, m, fit, case_count = 1;
	cin >> case_num;
	while(case_num--) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf("%d", &fit);
				if(fit) edge[i].push_back(j);
			}
		}

		int ans = 0;
		memset(llink,0,sizeof(llink));
		memset(rlink,0,sizeof(rlink));
		for(int i = 1; i <= n; ++i) {
			memset(vis,0,sizeof(vis));
			if(DFS(i)) ++ans;
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", case_count++, ans);
		//init
		for(int i = 1; i <= n; ++i) edge[i].clear();
	}
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
