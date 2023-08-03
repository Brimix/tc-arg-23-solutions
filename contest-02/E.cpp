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
const int MAXN = 1000100;

int f(int n) {
	int ans = 1;
	while(n) {
		int d = n%10;

		if (d) ans *= d;
		n /= 10;
	}
	return ans;
}

int s[MAXN];
int g(int n) {
	if (n < 10) return n;
	
	int &ret = s[n];
	if (ret != -1) return ret;
	
	int m = f(n);
	return g(m);
}

int n;
vector<int> ids[10];

int main() {
	//~ freopen("input.txt", "r", stdin);
	forn(i, MAXN) s[i] = -1;
	forr(i, 1, MAXN) {
		int v = g(i);
		ids[v].pb(i);
	}

	while (scanf("%d", &n) >= 1) {
		forn (i, n) {
			int l, r, k;
			scanf("%d %d %d", &l, &r, &k);
			
			int li = lower_bound(ids[k].begin(), ids[k].end(), l) - ids[k].begin();
			int ri = lower_bound(ids[k].begin(), ids[k].end(), r + 1) - ids[k].begin();
			printf("%d\n", ri - li);
		}
	}
}
