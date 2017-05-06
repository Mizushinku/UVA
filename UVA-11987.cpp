/***
* 第1行輸入N M,表示有N個數字,M條命令
* 接下來M行輸入c u v
* init : {1} {2} {3} ...... {N} 共N個集合
* c = 1 表示將含有u與v的兩集合合併
* c = 2 表示將u移動至含有v的集合
* c = 3 （不需輸入v）表示將含有u的集合之元素個數及總和印出
***/
#include<iostream>
#include<vector>
using namespace std;
#define index 200020

void Union(int,int);
int Find(int);

vector<int> p(index), s(index), n(index), np(index);

int main(void)
{
	int N, M, c, u, v, fu, fv;
	while(cin >> N >> M) {
		for(int i = 1; i <= N; ++i) {
			p[i] = i;
			s[i] = i;
			np[i] = i;
			n[i] = 1;
		}
		for(int i = 0; i < M; ++i) {
			cin >> c;
			switch(c) {
				case 1 :
					cin >> u >> v;
					fu = Find(np[u]);
					fv = Find(np[v]);
					if(fu == fv) continue;
					Union(fu,fv);
					break;
				case 2 :
					cin >> u >> v;
					fu = Find(np[u]);
					fv = Find(np[v]);
					if(fu == fv) continue;
					s[fu] -= u;
					--n[fu];
					np[u] = ++N;
					p[N] = N;
					s[N] = u;
					n[N] = 1;
					fu = Find(np[u]);
					Union(fu,fv);
					break;
				case 3 :
					cin >> u;
					fu = Find(np[u]);
					cout << n[fu] << ' ' << s[fu] << endl;
					break;
				default : break;
			}
		}
	}
	return 0;
}

int Find(int x)
{
	if(x == p[x]) return x;
	return p[x] = Find(p[x]);
}

void Union(int U, int V)
{
		p[U] = V;
		s[V] += s[U];
		n[V] += n[U];
}
