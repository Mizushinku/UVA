/***
* 將各個點由x小到大排,x一樣由y小到大排,然後作Andrew’s Monotone Chain
* 找到凸包,座標點儲存型態用float,用double會WA
* mark儲存的是凸包的各個點,由於一開始儲存的是逆時針序,所以要反過來印
***/
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;

float cross(const int&, const int&, const int&);
float dist(const int&, const int&);

struct Node {
	float x, y;
	bool operator<(const Node& cmp) const {
		if(x == cmp.x) return y < cmp.y;
		return x < cmp.x;
	}
}node[100010];



int main(void)
{
	int N, case_cnt = 1;
	while(scanf("%d", &N) && N != 0) {
		float x, y;
		for(int  i = 0; i < N; ++i) {
			scanf("%f %f", &node[i].x, &node[i].y);
		}
		sort(node,node+N);
		vector<int> mark;

		mark.push_back(0);
		if(N > 1) mark.push_back(1); //防止只有1個點
		else mark.push_back(0);

		for(int i = 2; i < N; ++i) { //凸包下半
			mark.push_back(i);
			while(mark.size() >= 2) {
				int a = mark[mark.size()-3];  //上上個點的index
				int b = mark[mark.size()-2];  //上個點的index
				if(cross(a,b,i) >= 0) break;
				mark.pop_back();
				mark.pop_back();
				mark.push_back(i);
			}
		}
		for(int i = N-2; i >= 0; --i) { //凸包上半
			mark.push_back(i);
			while(mark.size() >= 2) {
				int a = mark[mark.size()-3];
				int b = mark[mark.size()-2];
				if(cross(a,b,i) >= 0) break;
				mark.pop_back();
				mark.pop_back();
				mark.push_back(i);
			}
		}

		float dis = 0;
		for(int i = 1; i < mark.size(); ++i) {
			dis += dist(mark[i],mark[i-1]);
		}

		if(case_cnt > 1) printf("\n");
		printf("Region #%d:\n", case_cnt++);
		for(int i = mark.size()-1; i >= 0; --i) {
			printf("(%.1f,%.1f)", node[mark[i]].x, node[mark[i]].y);
			if(i) printf("-");
			else printf("\nPerimeter length = %.2f\n", dis);
		}
	}

}

float cross(const int& a, const int& b, const int& c)
{
	//ab x ac
	float Vab_x = node[b].x - node[a].x;
	float Vab_y = node[b].y - node[a].y;
	float Vac_x = node[c].x - node[a].x;
	float Vac_y = node[c].y - node[a].y;
	return Vab_x * Vac_y - Vab_y * Vac_x;
}

float dist(const int& a, const int& b)
{
	return sqrt( pow(node[a].x-node[b].x,2) + pow(node[a].y-node[b].y,2) );
}
