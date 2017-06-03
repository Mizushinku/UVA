/***
* 利用線性規劃求有無相交 
***/
#include<cstdio>
#include<utility>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

int main(void)
{
	int n, xs, ys, xe, ye, xtl, ytl, xbr, ybr;
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d %d %d", &xs, &ys, &xe, &ye);
		scanf("%d %d %d %d", &xtl, &ytl, &xbr, &ybr);
		if(xtl > xbr) swap(xtl,xbr);	//測資有可能亂給,自己換一下
		if(ytl < ybr) swap(ytl,ybr);	
		bool flag = false;
		if((xs >= xtl && xs <= xbr && ys >= ybr && ys <= ytl) || (xe >= xtl && xe <= xbr && ye >= ybr && ye <= ytl)) {
			flag = true;	//若線段其中一點(甚至一個點)在矩型中,則稱其為有相交,輸出T
			printf("T\n");
		}

		int a = ys - ye, b = xe - xs;	//直線方程式
		int c = a*xs + b*ys;
		
		vector< pair<int,int> > V;
		int l = abs(xtl - xbr);
		int w = abs(ytl - ybr);

		V.push_back(make_pair(xtl,ytl));	//矩型4個點
		V.push_back(make_pair(xtl+l,ytl));
		V.push_back(make_pair(xbr,ybr));
		V.push_back(make_pair(xbr-l,ybr));
		int k = 0;
		while(!flag) {
			for(int i = k+1; i < V.size(); ++i) {
				int x1 = V[k].first, y1 = V[k].second;	//兩兩點嘗試相乘
				int x2 = V[i].first, y2 = V[i].second;
				if((a*x1 + b*y1 -c) * (a*x2 + b*y2 -c) < 0) {
					if((x1 >= min(xs,xe) && x1 <= max(xs,xe)) || (y1 >= min(ys,ye) && y1 <= max (ys,ye))) {
						if((x2 >= min(xs,xe) && x2 <= max(xs,xe)) || (y2 >= min(ys,ye) && y2 <= max (ys,ye))) {
							flag = true;	//兩點若在'直線'不同邊,尚須判斷其在'線段'不同邊
							break;
						}
					}
				}
				if(a*x1 + b*y1 -c == 0) {	//線段端點在矩型邊上
					if(x1 >= min(xs,xe) && x1 <= max(xs,xe) && y1 >= min(ys,ye) && y1 <= max (ys,ye)) {
						flag = true;
						break;
					}
				}
				if(a*x2 + b*y2 -c == 0) {
					if(x2 >= min(xs,xe) && x2 <= max(xs,xe) && y2 >= min(ys,ye) && y2 <= max (ys,ye)) {
						flag = true;
						break;
					}
				}
			}
			if(flag) {
				printf("T\n");
				break;
			}
			++k;
			if(k >= V.size()-1) {
				printf("F\n");
				break;
			}
		}
	}
	return 0;
}
