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

int n, w, h;

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d %d %d", &w, &h, &n) >= 1) {
		vector<int> H = {0, h}, V = {0, w};
		
		forn(i, n) {
			char t;
			int d;
			scanf(" %c %d", &t, &d);
			if (t == 'H') H.pb(d);
			if (t == 'V') V.pb(d);
		}
		sort(H.begin(), H.end());
		sort(V.begin(), V.end());
		
		ll mxh = 0, mxv = 0;
		forn(i, sz(H) - 1) mxh = max(mxh, (ll)H[i + 1] - H[i]);
		forn(i, sz(V) - 1) mxv = max(mxv, (ll)V[i + 1] - V[i]);
		
		printf("%lld\n", mxh * mxv);
	}
}
