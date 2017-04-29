/***
* 第1行輸入n m表示有n個點,以及m個候選點
* 接下來任意行數輸入u v,表示u與v相連,輸入-1 -1表示結束該部份
* 答案為一數組x y,y表示圖被分成幾部份,x為點代號（0 ~ n-1）
* 輸入0 0結束程式
***/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(int,int);

struct BOMB {
	int station, pigeon;
	bool operator<(const BOMB& cmp) const {
		if(pigeon != cmp.pigeon) return pigeon > cmp.pigeon;
		return station < cmp.station;
	}
};

vector<int> node[10000], dfn(10000), low(10000);
vector<struct BOMB> bomb;
int dfsc;

int main(void)
{
	int n, m, u, v;
	struct BOMB* p;
	while(cin >> n >> m && n != 0 && m != 0) {
		bomb.clear();                 //init
		for(int i = 0; i < n; ++i) {
			node[i].clear();
			dfn.at(i) = 0;
			low.at(i) = 0;
			p = new struct BOMB;
			p->station = i;
			p->pigeon = 1;
			bomb.push_back(*p);
			delete p;
		}
		
		while(cin >> u >> v && u != -1 && v != -1) {
			node[u].push_back(v);
			node[v].push_back(u);
		}

		dfsc = 1;
		dfs(0,-1);
		for(int i = 0; i < n; ++i) {
			if(bomb.at(i).pigeon > node[i].size())
				--bomb.at(i).pigeon;
		}
		sort(bomb.begin(),bomb.end());
		for(int i = 0; i < m; ++i) {
			cout << bomb.at(i).station << ' ' << bomb.at(i).pigeon << endl;
		}
		cout << endl;
		/*
		for(int i = 0; i < ans.size(); ++i)
			cout << ans.at(i) << endl;
		for(int i = 0; i < n; ++i)
			cout << "low[" << i << "] is : " << low.at(i) << endl;
		*/
	}
	return 0;
}

void dfs(int cur, int pre)
{
	dfn.at(cur) = dfsc;
	low.at(cur) = dfsc++;
	int child = 0;
	bool cp = false;

	for(int i = 0; i < node[cur].size(); ++i) {
		int next = node[cur].at(i);
		if(dfn.at(next) == 0) {
			++child;
			dfs(next,cur);
			low.at(cur) = min(low.at(cur),low.at(next));
			if(low.at(next) >= dfn.at(cur)) cp = true;
		}
		else if(next != pre) low.at(cur) = min(low.at(cur),dfn.at(next));
	}
	
	if((child >= 2 || pre != -1) && cp) {
		for(int i = 0; i < node[cur].size(); ++i) {
			int next = node[cur].at(i);
			if(low.at(next) > dfn.at(cur)) {
				++bomb.at(cur).pigeon;
				++bomb.at(next).pigeon;
			}
		}
	}
}
