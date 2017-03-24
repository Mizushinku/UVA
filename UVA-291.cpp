#include<cstdio>
using namespace std;
void DFS(int, int);

int route[5][5] = {{0, 2, 3, 0, 5},
				   {1, 0, 3, 0, 5},
				   {1, 2, 0, 4, 5},
				   {0, 0, 3, 0, 5},
				   {1, 2, 3, 4, 0}};
long int ans = 1;

int main(void)
{
	DFS(1, 0);
}

void DFS(int L, int point)
{
	if(L == 9) {
		printf("%ld\n", ans);
		return;
	}

	for(int i = 0; i < 5; ++i) {
		if(route[point][i] == 0) continue;
		ans = ans * 10 + route[point][i];
		int tmp = route[point][i] - 1;
		route[point][i] = 0;
		route[i][point] = 0;
		
		DFS(L+1,tmp);
		
		route[point][i] = i + 1;
		route[i][point] = point + 1;
		ans /= 10;
	}
	return;
}
