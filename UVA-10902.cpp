/***
* 將所有棍子讀入後，由第1根棍子開始往編號大（後丟入）的棍子找，若有交點，則該棍子不是top
* 最後將top值是true的編號印出
***/
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
using namespace std;

struct Line {
	float x1, y1, x2, y2;
}line[100010];

bool top[100010];

int main(void)
{
	int N;
	while(scanf("%d", &N) && N) {
		for(int i = 1; i <= N; ++i) {
			scanf("%f %f %f %f", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
			top[i] = true;
		}
		for(int i = 1; i <= N; ++i) {
			pair<float,float> V1 = make_pair(line[i].x2-line[i].x1,line[i].y2-line[i].y1);
			
			for(int j = i+1; j <= N; ++j) {
				pair<float,float> V2 = make_pair(line[j].x1-line[i].x1,line[j].y1-line[i].y1);
				pair<float,float> V3 = make_pair(line[j].x2-line[i].x1,line[j].y2-line[i].y1);
				pair<float,float> V4 = make_pair(line[j].x2-line[j].x1,line[j].y2-line[j].y1);
				pair<float,float> V5 = make_pair(line[i].x1-line[j].x1,line[i].y1-line[j].y1);
				pair<float,float> V6 = make_pair(line[i].x2-line[j].x1,line[i].y2-line[j].y1);
				if((V1.first*V2.second - V1.second*V2.first) * (V1.first*V3.second - V1.second*V3.first) < 0) {
					if((V4.first*V5.second - V4.second*V5.first) * (V4.first*V6.second - V4.second*V6.first) < 0) {
						top[i] = false;
						break;
					}
				}
				else if((V4.first*V5.second - V4.second*V5.first) == 0) {
					if(line[i].x1 >= min(line[j].x1,line[j].x2) &&
					   line[i].x1 <= max(line[j].x1,line[j].x2) &&
					   line[i].y1 >= min(line[j].y1,line[j].y2) &&
					   line[i].y1 <= max(line[j].y1,line[j].y2)   ) {
						top[i] = false;
						break;
					}
				}
				else if((V4.first*V6.second - V4.second*V6.first) == 0) {
					if(line[i].x2 >= min(line[j].x1,line[j].x2) &&
					   line[i].x2 <= max(line[j].x1,line[j].x2) &&
					   line[i].y2 >= min(line[j].y1,line[j].y2) &&
					   line[i].y2 <= max(line[j].y1,line[j].y2)   ) {
						top[i] = false;
						break;
					}
				}
			}
		}
		printf("Top sticks:");
		for(int i = 1; i <= N; ++i) {
			if(top[i] && i < N) printf(" %d,", i);
			else if(top[i] && i == N) printf(" %d.\n", i);
		}
	}
	return 0;
}
