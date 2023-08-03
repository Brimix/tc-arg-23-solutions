#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = (int) a; i < (int) b; i++)
#define forn(i, n) forr(i, 0, n)
#define dforr(i, a, b) for(int i = (int) b-1; i >= (int) a; i--)
#define dforn(i, n) dforr(i, 0, n)
#define sz(x) ((int) x.size())
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
const int MAXN = -1;

int n;
string s;

map<char, vector<int>> ids;
void processText() {
	ids.clear();

	forn(i, n) {
		char letter = s[i];
		ids[letter].pb(i);
	}
}

map<char, int> cnt;
int solve(string &p) {
	cnt.clear();
	forn(i, sz(p)) {
		char letter = p[i];
		cnt[letter]++;
	}
	
	int ans = -1;
	for (ii t : cnt) {
		char letter = t.fst;
		int neededAmount = t.snd;
		
		int neededId = ids[letter][neededAmount - 1];
		ans = max(ans, neededId);
	}
	return ans + 1;
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> s) {
		processText();
		
		int m; cin >> m;
		forn(i, m) {
			string p; cin >> p;
			cout << solve(p) << endl;
		}
	}
}
