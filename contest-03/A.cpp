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

int getPad(int a, int b, int f) {
	if (b < a) swap(a, b);
	return (a < f && f < b ? 2 : 0);
}

int main() {
	int tc; scanf("%d", &tc);
	forn(cs, tc) {
		int ax, ay, bx, by, fx, fy;
		scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &fx, &fy);
		
		int ans = abs(ax - bx) + abs(ay - by);
		
		if (ay == by && ay == fy) ans += getPad(ax, bx, fx);
		if (ax == bx && ax == fx) ans += getPad(ay, by, fy);
		printf("%d\n", ans);
	}
}
