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
const ld INF = 1e18;

struct pt {
	ll x, y;
	pt (ll x = 0, ll y = 0): x(x), y(y) {}
	pt operator-(pt q) { return pt(q.x - x, q.y - y); }
	ll operator^(pt q) { return x*q.y - y*q.x; }
	
	ld norm() { return hypotl(x, y); }
};

ld getD(pt a, pt b, pt c) {
	pt ba = a - b, bc = c - b, ac = c - a;
	
	ld area2 = abs(ba^bc);
	ld len = ac.norm();
	return area2 / len;
}

int n;
vector<pt> p;

int main() {
	while (scanf("%d", &n) >= 1) {
		p.resize(n);
		forn(i, n) scanf("%lld %lld", &p[i].x, &p[i].y);
		
		ld ans = INF;
		forn(i, n) ans = min(ans, getD(p[i], p[(i+1)%n], p[(i+2)%n]));
		printf("%.10Lf\n", ans/2);
	}
}
