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
const int MAXN = 200500;

int n, a[MAXN], b[MAXN], d[MAXN];

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) >= 1) {
		forn(i, n) scanf("%d", &a[i]);
		forn(i, n) scanf("%d", &b[i]);
		forn(i, n) d[i] = a[i] - b[i];
		
		sort(d, d + n);
		//~ printf("D:"); forn(i, n) printf(" %d", d[i]); puts("");
		
		int r = n;
		ll ans = 0;
		forn(l, n) {
			while (r > 0 && d[r-1] + d[l] > 0) r--;
			//~ printf("%d-%d\n", l, r);
			ans += n - r;
		}
		
		forn(i, n) if (d[i] > 0) ans--;
		ans /= 2;
		printf("%lld\n", ans);
	}
}
