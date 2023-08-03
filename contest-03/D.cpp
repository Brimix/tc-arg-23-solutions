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
const int MAXN = 120, INF = 1e9;

int n, a[MAXN];

int main() {
	//~ freopen("input.txt", "r", stdin);
	int tc; scanf("%d", &tc);
	forn (cs, tc) {
		scanf("%d", &n);
		forn(i, n) scanf("%d", &a[i]);
		
		int mni = -1, mxi = -1;
		forn(i, n) {
			if (a[i] == 1) mni = i;
			if (a[i] == n) mxi = i;
		}
		
		if (mni > mxi) swap(mni, mxi);
		
		int pref = mni;
		int suf = n - mxi - 1;
		int mid = mxi - mni - 1;
		
		int areLeft = max({pref, suf, mid});
		printf("%d\n", n - areLeft);
	}
}
