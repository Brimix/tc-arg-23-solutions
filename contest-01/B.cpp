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
const int MAXN = 1000500;

int n, v[MAXN];

int memo[MAXN];
int solve(int p) {
	if (p >= n) return 0;
	
	int &ret = memo[p];
	if (ret != -1) return ret;
	
	int ans1 = v[p] + solve(p + 3);
	int ans2 = solve(p + 1);
	
	return ret = max(ans1, ans2);
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) >= 1) {
		forn(i, n) scanf("%d", &v[i]);
		
		forn(i, MAXN) memo[i] = -1;

		int ans = solve(0);
		printf("%d\n", ans);
	}
}
