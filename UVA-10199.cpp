/***
* 一筆測資輸入如下：（可有n筆）
* 第1行輸入N表示有N個區域,接下來N行輸入各個區域的名稱（string）
* 再輸入R表示有R條路（雙向）,接下來R行輸入兩個區域名稱,用空格隔開
* 輸出為關節點個數與其名稱
***/
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
void dfs(int,int);

map<string,int> m;
map<int,string> w;
vector<string> node[100];
vector<int> dfn(100), low(100);
vector<string> ans;
int dfsc;

int main(void)
{
	int N, R, c = 1;
	string s, t;
	bool is_first_data = true;
	while(cin >> N && N != 0) {
		if(!is_first_data) cout << endl;

		m.clear(); ans.clear();
		for(int i = 0; i < N; ++i) {
			node[i].clear();
			dfn.at(i) = 0;
			low.at(i) = 0;
			cin >> s;
			m[s] = i;
			w[i] = s;
		}
		cin >> R;
		for(int i = 0; i < R; ++i) {
			cin >> s >> t;
			node[m[s]].push_back(t);
			node[m[t]].push_back(s);
		}
		
		for(int i = 0; i < N; ++i) {
			if(dfn.at(i) == 0) {
				dfsc = 1;
				dfs(i,-1);
			}
		}
		sort(ans.begin(),ans.end());
		printf("City map #%d: %lu camera(s) found\n", c++, ans.size());
		for(int i = 0; i < ans.size(); ++i)
			cout << ans.at(i) << endl;
		is_first_data = false;
	}
	return 0;
}

void dfs(int cur, int pre)
{
	int child = 0;
	bool cp = false;
	dfn.at(cur) = dfsc;
	low.at(cur) = dfsc++;

	for(int i = 0; i < node[cur].size(); ++i) {
		int next = m[ node[cur].at(i) ];
		if(dfn.at(next) == 0) {
			++child;
			dfs(next,cur);
			low.at(cur) = min(low.at(cur),low.at(next));
			if(low.at(next) >= dfn.at(cur)) cp = true;
		}
		else if(next != pre) low.at(cur) = min(low.at(cur),dfn.at(next));
	}

	if((child >= 2 || pre != -1) && cp) ans.push_back(w[cur]);
}
