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

int n;

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) >= 1) {
		vector<int> d(n);
		forn(i, n) scanf("%d", &d[i]);
		
		int mx = 0;
		forn(i, n) mx = max(mx, d[i]);
		printf("%d\n", max(mx - 25, 0));
	}
}
