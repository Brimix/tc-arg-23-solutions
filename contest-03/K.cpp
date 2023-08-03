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
typedef pair<char, int> ci;
const int ABC_SIZE = 26;

bool specialComp(ci a, ci b) {
	if (a.fst == b.fst) return a.snd < b.snd;
	return a.fst > b.fst;
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	int tc; cin >> tc;
	forn(cs, tc) {
		string s; cin >> s;
		int n = sz(s);
		
		vector<ci> sorted(n);
		forn(i, n) sorted[i] = {s[i], i + 1};
		
		if (s[0] <= s[n-1]) sort(sorted.begin(), sorted.end());
		else sort(sorted.begin(), sorted.end(), specialComp);
		
		bool adding = false;
		vector<ci> ans;
		forn(i, n) {
			if (sorted[i].snd == 1) adding = true;
			if (adding) ans.pb(sorted[i]);
			if (sorted[i].snd == n) adding = false;
		}
		
		cout << abs(s[0] - s[n-1]) << " " << sz(ans) << endl;
		forn(i, sz(ans)) {
			if (i) cout << " ";
			cout << ans[i].snd;
		} cout << endl;
	}
}
