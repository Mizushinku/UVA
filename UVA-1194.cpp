/***
* 將每個job視為一邊,連接二分圖,左邊是A電腦的mode,右邊是B電腦mode
* 若job可用mode 0執行則不建邊
* 一條邊代表一個job,要執行這個job則要把兩端點的其中一台電腦restart一次
* restart過後的電腦可執行所有連到該mode上的job,不必restart
* 求最大匹配數,因為一匹配邊代表兩端點的其中之一restart一次,並執行所有連接該mode的job
* 所以,也可以說成是最小點覆蓋,覆蓋所有的邊完成job
* 因初始狀態為mode 0,因此可用mode 0執行的job不需restart就可執行,故不計算次數
***/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool DFS(int);

#define index 110

int llink[index], rlink[index], vis[index];
vector<int> edge[index];

int main(void)
{
	int n, m, k, a, b;
	while(cin >> n && n) {
		cin >> m >> k;
		for(int i = 1; i <= k; ++i) {
			cin >> a >> a >> b;
			if((a*b)) {
				edge[a].push_back(b);
			}
		}

		int ans = 0;
		memset(llink,0,sizeof(llink));
		memset(rlink,0,sizeof(rlink));
		for(int i = 1; i <= n; ++i) {
			memset(vis,0,sizeof(vis));
			if(DFS(i)) ++ans;
		}
		cout << ans << endl;
		//init
		for(int i = 1; i < n; ++i) edge[i].clear();
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
