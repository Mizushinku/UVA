#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
void dfs(int,int);

vector<int> node[101];
int dfn[101], low[101];
int dfsc = 1, ans = 0;

int main(void)
{
	int N, u, v;
	string s;
	while(cin >> N && N != 0) {
		// init
		for(int i = 1; i <= N; ++i) {
			node[i].clear();
			dfn[i] = 0;
			low[i] = 0;
		}
		getline(cin,s); // a '\n'
		for(int i = 0; i <= N; ++i) {
			getline(cin,s);
			stringstream ss(s);
			ss >> u;
			if(!u) break;
			while(ss >> v) {
				node[u].push_back(v);
				node[v].push_back(u);
			}
		}
		dfs(1,-1);
		cout << ans << endl;
		dfsc = 1; ans = 0;
	}
	return 0;
}

void dfs(int now, int pre)
{
	int child = 0;
	bool cp = false;
	dfn[now] = dfsc;
	low[now] = dfsc;
	++dfsc;

	for(int i = 0; i < node[now].size(); ++i) {
		int next = node[now][i];
		if(dfn[next] == 0) {
			++child;
			dfs(next,now);
			low[now] = min(low[now],low[next]);
			if(low[next] >= dfn[now]) cp = true;
		}
		else if(next != pre) low[now] = min(low[now],dfn[next]);
	}
	if((child >= 2 || pre != -1) && cp) ++ans;
}
