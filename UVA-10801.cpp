#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<cmath>
using namespace std;

#define inf 1e9

typedef struct elevator {
	int time;
	vector<int> floor;
	vector<bool> ariv;
}elevator;

int main(void)
{
	int n, k, t, i;
	string s;
	stringstream ss;
	vector<elevator> eva(5);
	vector<bool> bv(100);
	int dis[100];
	queue<int> que;
	bool inque[100];
	while(cin >> n >> k) {
		for(i = 0; i < 100; ++i) { //init
			dis[i] = inf;
			inque[i] = false;
		}
		for(i = 0; i < n && cin >> t; ++i) {
			eva.at(i).time = t;
			eva.at(i).ariv = bv;
		}
		getline(cin,s); // a '\n'
		for(i = 0; i < n; ++i) {
			getline(cin,s);
			ss.str(""); ss.clear(); // clear the stringstream
			ss.str(s);
			while(1) {
				ss >> t;
				if(ss.fail()) break;
				eva.at(i).floor.push_back(t);
				eva.at(i).ariv.at(t) = true;
			}
		}
		que.push(0);
		inque[0] = true;
		dis[0] = 0;
		while(!que.empty()) {
			int now = que.front();
			inque[now] = false;
			que.pop();
			for(i = 0; i < n; ++i) {
				if(!eva.at(i).ariv.at(now)) continue;
				for(int j = 0; j < eva.at(i).floor.size(); ++j) {
					int v = eva.at(i).floor.at(j);
					int d = abs(v-now) * eva.at(i).time;
					if(dis[now] + d + 60< dis[v]) {
						dis[v] = dis[now] + d + 60;
						//cout << "dis[" << v << "] is : " << dis[v] << endl;
						if(!inque[v]) {
							que.push(v);
							inque[v] = true;
						}
					}
				}
			}
		}
		if(dis[k] != inf) dis[k] == 0 ? cout << dis[k] << endl :
										cout << dis[k] - 60 << endl;
		else cout << "IMPOSSIBLE" << endl;
		//init
		for(i = 0; i < n; ++i) {
			eva.at(i).floor.clear();
			eva.at(i).ariv.clear();
		}
	}
}
