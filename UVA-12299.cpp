/***
* 一般的Segment Tree,加上shift功能,改tree時記得改s陣列
***/
#include<cstdio>
#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

struct NODE {
	int minval;
	NODE *l, *r;

	void updata(int v)
	{
		this->minval = v;
	}
	void pull()
	{
		this->minval = min(l->minval,r->minval);
	}
};

NODE *build(int,int);
int querymin(NODE *,int,int,int,int);
void modify(NODE *,int,int,int,int);

int s[100010];

//MAIN
int main(void)
{
	int n, q;
	string od;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &s[i]);
	NODE *root = build(1,n);
	getline(cin,od);
	
	for(int i = 1; i <= q; ++i) {
		getline(cin,od);
		if(od[0] == 'q') {
			int t = 0, b[2];
			b[0] = 0; b[1] = 0;
			for(int j = 6; j < od.length(); ++j) {
				if(isdigit(od[j])) {
					b[t] = b[t]*10 + (od[j]-'0');
				}
				else if(od[j] == ',') ++t;
				else break;
			}
			printf("%d\n", querymin(root,1,n,b[0],b[1]));
		}
		else if(od[0] == 's') {
			int v = 0, first = 0, pre = 0;
			for(int j = 6; j < od.length(); ++j) {
				if(isdigit(od[j])) {
					v = v*10 + (od[j]-'0');
				}
				else if(od[j] == ',') {
					if(!pre) {
						first = s[v];
						pre  = v;
						v = 0;
						continue;
					}
					modify(root,1,n,pre,s[v]);
					pre = v;
					v = 0;
				}
				else if(od[j] == ')') {
					modify(root,1,n,pre,s[v]);
					modify(root,1,n,v,first);
					break;
				}
			}
		}
	}
}

NODE * build(int L, int R)
{
	NODE * now = new NODE();
	if(L == R) {
		now->updata(s[L]);
		return now;
	}
	int mid = (L+R)>>1;
	now->l = build(L,mid);
	now->r = build(mid+1,R);
	now->pull();
	return now;
}

int querymin(NODE * now,int L, int R, int x, int y)
{
	if(x > R || y < L) return 1e9;
	if(x <= L && y >= R) return now->minval;
	int mid = (L+R)>>1;
	return min( querymin(now->l,L,mid,x,y) , querymin(now->r,mid+1,R,x,y) );
}

void modify(NODE *now, int L, int R, int x, int v)
{
	if(L == R) {
		now->updata(v);
		s[x] = v;
		return;
	}
	int mid = (L+R)>>1;
	if(x <= mid) {
		modify(now->l,L,mid,x,v);
	}
	else {
		modify(now->r,mid+1,R,x,v);
	}

	now->pull();
}
