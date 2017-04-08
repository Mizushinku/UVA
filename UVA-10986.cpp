#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inf 2*1e9

typedef struct NODE {
	vector<int> v[2];
}Node;

int main(void)
{
	int N, n, m, S, T, i, j, u, v, w, case_num = 1;
	cin >> N;
	vector<Node> node;
	vector<bool> inque(20000);
	vector<int> dis(20000);
	while(N--) {
		cin >> n >> m >> S >> T;
		Node *p;
		for(i = 0; i < n; ++i) {
			p = new Node;
			node.push_back(*p);
			if(inque.at(i)) inque.at(i) = false;
			if(dis.at(i) != inf) dis.at(i) = inf;
		}
		for(i = 0; i < m; ++i) {
			cin >> u >> v >> w;
			node.at(u).v[0].push_back(v);
			node.at(u).v[1].push_back(w);
			node.at(v).v[0].push_back(u);
			node.at(v).v[1].push_back(w);
		}
		queue<int> que;
		que.push(S);
		inque.at(S) = true;
		dis.at(S) = 0;
		while(!que.empty()) {
			u = que.front();
			que.pop();
			inque.at(u) = false;
			for(i = 0; i < node.at(u).v[0].size(); ++i) {
				v = node.at(u).v[0].at(i);
				w = node.at(u).v[1].at(i);
				if(dis.at(u) + w < dis.at(v)) {
					dis.at(v) = dis.at(u) + w;
					if(!inque.at(v)) {
						que.push(v);
						inque.at(v) = true;
					}
				}
			}
		}
		if(dis.at(T) != inf) cout << "Case #" << case_num++ << ": " << dis.at(T) << endl;
		else cout << "Case #" << case_num++ << ": unreachable" << endl;
		
		node.clear();
	}
	return 0;
}
