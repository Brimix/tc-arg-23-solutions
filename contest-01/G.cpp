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
const int MAXN = 100500;
const ll INF = 1e18;

int n, m, a[MAXN], b[MAXN];

ll calcFor(int v) {
	ll acum = 0;
	forn(i, n) if (a[i] < v) acum -= a[i] - v;
	forn(i, m) if (b[i] > v) acum += b[i] - v;
	return acum;
}

int main() {
	while (scanf("%d %d", &n, &m) >= 1) {
		forn(i, n) scanf("%d", &a[i]);
		forn(i, m) scanf("%d", &b[i]);
		
		int l = 0, r = 1e9 + 50;
		while(r - l > 10) {
			int d = (r - l + 2) / 3;
			int t1 = l + d;
			int t2 = r - d;
			
			ll v1 = calcFor(t1), v2 = calcFor(t2);
			if (v1 < v2) r = t2;
			else         l = t1;
		}
		
		ll ans = INF;
		//~ printf("%d %d\n", l, r);
		forr(i, l, r+1) ans = min(ans, calcFor(i));
		printf("%lld\n", ans);
	}
}
