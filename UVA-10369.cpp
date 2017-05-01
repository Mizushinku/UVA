/***
* 第一行輸入測資筆數
* 每筆測資第一行輸入兩個整數S P,接下來P行輸入各個點的直角座標x y
* 輸出為最小生成樹中,前S-1大的路捨去後,剩下的路的最大值
***/
#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;

int Find(int);
void Union(int,int);

struct EDGE {
	int u, v;
	double d;
	bool operator<(const EDGE& cmp) const { return d < cmp.d; }
};

vector< pair<int,int> > node;
vector<EDGE> edge;
vector<int> p(500);
vector<double> ans;

int main(void)
{
	int N, S, P, a, b, D;
	int x1, x2, y1, y2;
	EDGE ed;

	cin >> N;
	while(N--) {
		node.clear();
		edge.clear();
		ans.clear();
		cin >> S >> P;

		for(int i = 0; i < P; ++i) {
			cin >> x1 >> y1;
			node.push_back(make_pair(x1,y1));
			p.at(i) = i;
			for(int j = 0; j < i; ++j) {
				ed.u = j; ed.v = i;
				x2 = node.at(j).first;
				y2 = node.at(j).second;
				ed.d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
				edge.push_back(ed);
			}
		}
		sort(edge.begin(),edge.end());
		
		for(int i = 0, count = 0; i < edge.size() && count < P-1; ++i) {
			a = edge.at(i).u;
			b = edge.at(i).v;
			if(Find(a) == Find(b)) continue;

			ans.push_back(edge.at(i).d);
			Union(a,b);
			++count;
		}
		printf("%.2f\n", ans.at(P-S-1));
	}
	return 0;
}

int Find(int a)
{
	if(a == p.at(a)) return a;
	return p.at(a) = Find(p.at(a));
}

void Union(int a, int b)
{
	int A = Find(a);
	int B = Find(b);
	p.at(A) = B;
}
