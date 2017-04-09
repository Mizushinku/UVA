#include<iostream>
#include<vector>
using namespace std;
#define inf 1e9

typedef struct THE_EDGE {
	int beg, end, t;
}EDGE;

int main (void)
{
	int N, n, m, u, v, w, i, j;
	cin >> N;
	vector<EDGE> edge;
	vector<int> dis(1000);
	EDGE *p;
	while(N--) {
		cin >> n >> m;
		dis.at(0) = 0;
		for(i = 1; i < n; ++i) {
			if(dis.at(i) != inf) dis.at(i) = inf;
		}
		for(i = 0; i < m; ++i) {
			p = new EDGE;
			edge.push_back(*p);
			delete p;
			cin >> u >> v >> w;
			edge.at(i) = {.beg = u, .end = v, .t = w};
		}
		for(i = 0; i < n - 1; ++i) {
			for(j = 0; j < edge.size(); ++j) {
				u = edge.at(j).beg;
				v = edge.at(j).end;
				w = edge.at(j).t;
				if(dis.at(u) + w < dis.at(v))
					dis.at(v) = dis.at(u) + w;
			}
		}
		bool neg_cyc = false;
		for(j = 0; j < edge.size(); ++j) {
			u = edge.at(j).beg;
			v = edge.at(j).end;
			w = edge.at(j).t;
			if(dis.at(u) + w < dis.at(v))
				neg_cyc = true;
		}
		if(neg_cyc) cout << "possible" << endl;
		else cout << "not possible" << endl;
		edge.clear();
	}
	return 0;
}
