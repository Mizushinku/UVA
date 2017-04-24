/***
輸入（n,m）表示有n個點和m條路
接下來m行輸入（u,v）,表示u與v互連
不可有點獨立
輸入（0,0）結束程式
***/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(int,int);

vector<int> node[1001], dfn(1001), low(1001);
int dfsc;

int main(void)
{
	int n, m, u, v, case_num = 1;
	while(cin >> n >> m && n && m) {
		//init
		for(int i = 1; i <= n; ++i) {
			node[i].clear();
			dfn.at(i) = 0;
			low.at(i) = 0;
		}
		for(int i = 0; i < m; ++i) {
			cin >> u >> v;
			node[u].push_back(v);
			node[v].push_back(u);
		}
		printf("%d\n\n", case_num++);
		dfsc = 1;
		dfs(dfsc,-1);
		printf("#\n");
	}
	return 0;
}

void dfs(int cur, int pre)
{
	int child = 0;
	bool cp = false;
	dfn[cur] = dfsc;
	low[cur] = dfsc;
	++dfsc;

	for(int i = 0; i < node[cur].size(); ++i) {
		int next = node[cur].at(i);
		if(dfn[next] == 0) {
			++child;
			dfs(next,cur);
			low[cur] = min(low[cur],low[next]);
			if(low[next] >= dfn[cur]) {
				cp = true;
			}
			if(low[next] > dfn[cur]) {
				printf("%d %d\n", cur, next);
				printf("%d %d\n", next, cur);
			}
			else printf("%d %d\n", cur, next);
		}
		else if(next != pre) {
			low[cur] = min(low[cur],dfn[next]);
			if(dfn[cur] > dfn[next])
				printf("%d %d\n", cur, next);
		}
	}
}
