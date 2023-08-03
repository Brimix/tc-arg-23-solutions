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
const int MAXN = 60, INF = 1e9;

int n, s[MAXN];

int dp[2][MAXN];
int solve(bool plays, int p) {
	if (p == n) return 0;
	
	int &ret = dp[plays][p];
	if (ret != INF) return ret;
	
	int ans1 = s[p] - solve(!plays, p + 1);
	int ans2 = -s[p] + solve(plays, p + 1);
	return ret = max(ans1, ans2);
}

int main() {
	while (scanf("%d", &n) >= 1) {
		forn(i, n) scanf("%d", &s[i]);
		
		forn(i, 2) forn(j, MAXN) dp[i][j] = INF;
		int bestDif = solve(0, 0);
		int sum = 0; forn(i, n) sum += s[i];
		
		int a = (sum + bestDif) / 2, b = sum - a;
		printf("%d %d\n", b, a);
	}
}
