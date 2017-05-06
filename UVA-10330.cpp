/***
* 第1行輸入N,表示有N個變電箱,下一行輸入N個用空格分開的int表示各個變電箱的容量
* 再下一行輸入M,表示有M條路
* 接下來M行輸入u v c,表示u與v間的容量
* 下一行輸入B D,再下一行輸入N個用空格分開的int(1~N)
* 前B個號碼表示與發電所連接的變電箱,剩餘的號碼表示與目的地相連的變電箱
* 輸出為可以到達目的地的最大電量
***/
#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

bool DFS(int,int,int);
int findflow(int,int);

#define inf 1e9
int vis[300], path[300], cap[210][210], flow[210][210];
int N, M, B, D;

int main(void)
{
	int N, M, B, D, ans;
	while(cin >> N) {
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		
		for(int i = 1; i <= N; ++i) { //cap[n][0] : cap on node
			int CapOnNode;
			cin >> CapOnNode;
			cap[i+100][i] = CapOnNode;
		}
		cin >> M;
		for(int i = 0; i < M; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			cap[u][v+100] = c;
		}
		cin >> B >> D;
		for(int i = 0; i < B; ++i) { //cap[0][n] : super source
			int s;
			cin >> s;
			cap[0][s+100] = inf;
		}
		for(int i = 0; i < D; ++i) { //cap[n][n+1] : super sink
			int t;
			cin >> t;
			cap[t][N+100+1] = inf;
		}
		
		ans = 0;
		while(1) {
			memset(vis,0,sizeof(vis));
			if(!DFS(0,N+101,0)) break;
			ans += findflow(0,N+101);
		}
		cout << ans << endl;
	}
	return 0;
}

bool DFS(int s, int t, int conj)
{
	vis[s] = 1;
	if(s == t) return true;
	for(int i = 0; i <= t; ++i) {
			if(vis[i]) continue;
			if(cap[s][i] - flow[s][i] > 0 || flow[i][s] > 0) {
				path[i] = s;
				if(DFS(i,t,0)) return true;
			}
	}
	return false;
}

int findflow(int s, int t)
{
	int f = inf;
	for(int i = t, pre; i != s; i = pre) {
		pre = path[i];
		if(cap[pre][i] - flow[pre][i] > 0)
			f = min(f,cap[pre][i] - flow[pre][i]);
		else
			f = min(f,flow[i][pre]);
	}
	for(int i = t, pre; i != s; i = pre) {
		pre = path[i];
		if(cap[pre][i] - flow[pre][i] > 0)
			flow[pre][i] += f;
		else
			flow[i][pre] -= f;
	}
	return f;
}
