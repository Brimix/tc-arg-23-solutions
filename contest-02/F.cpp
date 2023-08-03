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

int n, R, D;

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &R, &D) >= 1) {
		scanf("%d", &n);
		
		int cnt = 0;
		forn(i, n) {
			ll x, y, r;
			scanf("%lld %lld %lld", &x, &y, &r);
			
			ll d = x*x + y*y;
			ll low = (R - D + r) * (R - D + r);
			ll high = (R - r) * (R - r);
			
			//~ printf("%lld %lld %lld\n", low, d, high);
			bool inside = (low <= d) && (d <= high);
			if (inside) cnt++;
		}
		
		printf("%d\n", cnt);
	}
}
