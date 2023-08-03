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

int a, b, c;

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d %d %d", &a, &b, &c) >= 1) {
		int mn = min({a, b, c});
		int mx = max({a, b, c});
		printf("%d\n", mx - mn);
	}
}
