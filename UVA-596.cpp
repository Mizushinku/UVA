/***
* 範例輸出的"Sample X"是騙人的！！！！！！！！！！！！！！
* 範例輸出的"Sample X"是騙人的！！！！！！！！！！！！！！
* 範例輸出的"Sample X"是騙人的！！！！！！！！！！！！！！
* 輸入測資的 S 後面接的是' 自定義名稱',也就是說那邊輸入什麼就要輸出什麼！！！
* 剩下的就是單純的凸包,注意有重複點,且起點要從x最大,y最小的地方逆時針輸出
***/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct Node {
	int x, y;
	bool operator<(const Node& cmp) const {
		if(x == cmp.x) return y < cmp.y;
		return x > cmp.x;
	}
}node[100010];

int cross(const int&, const int&, const int&);

int main(void)
{
	char c, op[3];
	string s;
	int N, n, x, y;
	scanf("%c", &c);
	while(1) {
		cin.ignore();
		getline(cin,s);
		N = s[s.length()-1] - '0';
		int cnt = 0;
		while(scanf("%s", op) && op[0] == 'P') {
			scanf("%d", &n);
			while(n--) {
				scanf("%d %d", &x, &y);
				node[cnt].x = x; node[cnt].y = y;
				++cnt;
			}
		}
		sort(node,node+cnt);
		
		vector<int> mark;
		for(int i = 0; i < cnt; ++i) { //凸包下半
			if(i && node[i].x == node[i-1].x && node[i].y == node[i-1].y) continue;
			mark.push_back(i);
			while(mark.size() >= 2) {
				int a = mark[mark.size()-3];  //上上個點的index
				int b = mark[mark.size()-2];  //上個點的index
				if(cross(a,b,i) <= 0) break;
				mark.pop_back();
				mark[mark.size()-1] = i;
			}
		}
		for(int i = cnt-2; i >= 0; --i) { //凸包上半
			if(i && node[i].x == node[i-1].x && node[i].y == node[i-1].y) continue;
			mark.push_back(i);
			while(mark.size() >= 2) {
				int a = mark[mark.size()-3];
				int b = mark[mark.size()-2];
				if(cross(a,b,i) <= 0) break;
				mark.pop_back();
				mark[mark.size()-1] = i;
			}
		}
		
		cout << s;
		printf(" convex hull:\n");
		
		for(int i = mark.size()-1; i > 0; --i) {
			printf(" (%d,%d)", node[mark[i]].x, node[mark[i]].y);
			if(i == 1) printf("\n");
		}

		if(op[0] == 'E') break;
	}
	return 0;
}

int cross(const int& a, const int& b, const int& c)
{
	//ab x ac
	int Vab_x = node[b].x - node[a].x;
	int Vab_y = node[b].y - node[a].y;
	int Vac_x = node[c].x - node[a].x;
	int Vac_y = node[c].y - node[a].y;
	return Vab_x * Vac_y - Vab_y * Vac_x;
}
