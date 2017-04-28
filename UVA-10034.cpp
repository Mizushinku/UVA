/***
* 第1行輸入N表示有N筆case
* 空一行後,第3行開始輸入第i筆測資,第1行輸入n表示有n個點
* 接下來n行依序輸入（x,y）座標點,x與y用空格分開,x和y是小數
* 每筆測資用空白行分離,輸出答案也需用空白行分離
***/
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
void Union(int,int);
int Find(int);


struct EDGE {
	int u, v;
	double d;
	bool operator<(const EDGE& cmp) const { return d < cmp.d; }
};

struct NODE {
	double x, y;
};

vector<int> p(100);


int main(void)
{
	int N, n, a, b, count;
	double x1, x2, y1, y2, ans;
	cin >> N;
	vector<struct EDGE> edge;
	vector<struct NODE> node;
	struct EDGE* ed;
	struct NODE no;
	while(N--) {
		//init
		edge.clear();
		node.clear();
		ans = 0; count = 0;
		
		cin >> n;
		for(int i = 0; i < n; ++i) {
			node.push_back(no);
			cin >> node.at(i).x >> node.at(i).y;
			p.at(i) = i;
			for(int j = 0; j < i; ++j) {
				ed = new struct EDGE;
				ed->u = j;  ed->v = i;
				x1 = node.at(i).x;
				y1 = node.at(i).y;
				x2 = node.at(j).x;
				y2 = node.at(j).y;
				ed->d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
				edge.push_back(*ed);
				delete ed;
			}
		}
		sort(edge.begin(),edge.end());
		for(int i = 0; i < edge.size() && count < n-1; ++i) {
			a = edge.at(i).u;
			b = edge.at(i).v;
			if(Find(a) == Find(b)) continue;
			
			ans += edge.at(i).d;
			//cout << "a is : " << a << '\t' << "b is : " << b << endl;
			Union(a,b);
			++count;
		}
		printf("%.2f\n", ans);
		if(N) printf("\n");

		#ifdef DEBUG
		for(int i = 0; i < node.size(); ++i) {
			cout << "node " << i << " is " << node.at(i).x << "  " << node.at(i).y << endl;
			
		}
		for(int i = 0; i < edge.size(); ++i) {
			cout << edge.at(i).u << "   " << edge.at(i).v << "   ";
			printf("%f\n", edge.at(i).d);
		}
		#endif
	}
	return 0;
}

void Union(int a,int b)
{
	int A = Find(a);
	int B = Find(b);
	p.at(B) = A;
}

int Find(int a)
{
	if(p.at(a) == a) return a;
	return p.at(a) = Find(p.at(a));
}
