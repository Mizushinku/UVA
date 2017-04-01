#include<iostream>
#include<string>
#include<cstring>
using namespace std;

typedef struct TRIE {
	struct TRIE* a[26];
	int count;

	TRIE()
	{
		memset(a, 0, sizeof(TRIE*) * 26);
		count = 0;
	}
} trie;

int main(void)
{
	int n;
	string s;
	while(cin >> n && cin >> s) {
		trie root;
		int m = 0;
		string pwd;
		
		for(int i = 0; i < s.length()-n+1; ++i) {
			string sub;
			trie *p = &root;
			for(int j = 0; j < n; ++j)
				sub += s[i+j];
			for(int j = 0; j < n; ++j) {
				int index = sub[j] - 'a';
				if(p -> a[index] == NULL) p -> a[index] = new TRIE();
				p = p -> a[index];
			}
			p -> count++;
			if(p -> count > m) { m = p -> count; pwd = sub; }
		}
		cout << pwd << endl;
	}
	return 0;
}
