#include<vector>
#include<map>
#include<iostream>
using namespace std;
void search(int,int);
void isMost_v(void);

vector<int> dv[2];
map<int, vector<int> > list;
bool first_input = true;
int min_d = 9999, m = 1;
int ans[3] = {0};

int main(void)
{
	int tot_time, w, n;
	while(cin >> tot_time >> w >> n) {
		if(!first_input) cout << endl;
		int d, v;
		for(int i = 0; i < n; ++i) {
			cin >> d; dv[0].push_back(d); if(d < min_d) min_d = d;
			cin >> v; dv[1].push_back(v);
		}
		int dtime = tot_time / (3 *w);
		
		search(dtime,0);
		m = ans[2];
		cout << ans[0] << '\n' << ans[1] << endl;
		for(int i = 0; i < list[m].size(); ++i) {
			cout << dv[0][list[m][i]] << ' '
				 << dv[1][list[m][i]] << endl;
		}
		
		//init
		dv[1].clear(); dv[0].clear(); list.clear();
		for(int i = 0; i < 3; ++i) ans[i] = 0;
		min_d = 9999; m = 1;
		if(first_input) first_input = false;
	}
	return 0;
}

void search(int t,int p)
{
	if(t < min_d || p == dv[0].size()) {
		for(int i = 0; i < list[0].size(); ++i)
			list[m].push_back(list[0][i]);
		isMost_v();
		++m;
		return;
	}
	for(int i = p; i < dv[0].size(); ++i) {
		if(t >= dv[0][i]) {
			list[0].push_back(i);
			t -= dv[0][i];
			search(t,i+1);

			list[0].pop_back(); t += dv[0][i];
		}
	}
}

void isMost_v(void)
{	
	int tmp_v = 0, tmp_c = 0;
	for(int i = 0; i < list[0].size(); ++i) {
			tmp_v += dv[1][list[0][i]];
			++tmp_c;
	}
	if(ans[0] < tmp_v) {
			ans[0] = tmp_v;
			ans[1] = tmp_c;
			ans[2] = m;
	}
}
