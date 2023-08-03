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
const int MAXN = 55;

int n, m;
string b[MAXN];

bool works(int si, int sj, char c) {
	forr(i, si, si+2) forr(j, sj, sj+2) {
		if (b[i][j] == c) return true;
	}
	return false;
}

bool works(int si, int sj) {
	if (!works(si, sj, 'f')) return false;
	if (!works(si, sj, 'a')) return false;
	if (!works(si, sj, 'c')) return false;
	if (!works(si, sj, 'e')) return false;
	return true;
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (cin >> n >> m) {
		forn(i, n) cin >> b[i];
		
		int ans = 0;
		forn(i, n-1) forn(j, m-1) {
			if (works(i, j)) ans++;
		}
		printf("%d\n", ans);
	}
}
