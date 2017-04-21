/***
輸入N（N >= 0）代表網路上有N個node,代號由0~N-1
接下來N行輸入各點所能連結到的node
格式為 ： n (m) a1 a2 ... am  (共m個, m >= 0,）, n為1到N-1 （不用照順序）
***/
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void dfs(int,int);

vector<int> node[1000], dfn(1000), low(1000);
map<int, vector<int> > bridge;
map<int, vector<int> >::iterator it;
int dfsc, ans;

int main(void)
{
	int N, u, v, n;
	string s;
	while(cin >> N) {
		if(N == 0) { printf("0 critical links\n\n"); continue; }
		//init
		for(int i = 0; i < N; ++i) {
			node[i].clear();
			dfn.at(i) = 0;
			low.at(i) = 0;
		}
		ans = 0;
		bridge.clear();

		for(int i = 0; i < N; ++i) {
			scanf("%d (%d)", &u, &n);
			for(int i = 0; i < n; ++i) {
				scanf("%d", &v);
				node[u].push_back(v);
			}
		}
		for(int i = 0; i < N; ++i) {
			if(dfn[i] == 0) {
				dfsc = 1;
				dfs(i,-1);
			}
		}
		printf("%d critical links\n", ans);
		for(it = bridge.begin(); it != bridge.end(); ++it) {
			if(it->second.size() > 1) {
				sort(it->second.begin(),it->second.end());
				for(int i = 0; i < it->second.size(); ++i)
					printf("%d - %d\n", it->first, it->second.at(i));
			}
			else printf("%d - %d\n", it->first, it->second.at(0));
		}
		printf("\n");
	}
	return 0;
}

void dfs(int cur, int pre)
{
	dfn[cur] = dfsc;
	low[cur] = dfsc;
	++dfsc;

	for(int i = 0; i < node[cur].size(); ++i) {
		int next = node[cur].at(i);
		if(dfn[next] == 0) {
			dfs(next,cur);
			low[cur] = min(low[cur],low[next]);
			if(low[next] > dfn[cur]) {
				++ans;
				if(cur < next) bridge[cur].push_back(next);
				else bridge[next].push_back(cur);
			}
		}
		else if(next != pre) {
			low[cur] = min(low[cur],dfn[next]);
		}
	}
}
