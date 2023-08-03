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
const ld PI = acosl(-1);

int n, r1, r2;

int main() {
	while (scanf("%d %d %d", &n, &r1, &r2) >= 1) {
		ld angle = PI / n;
		ld triangleArea = (ld)r1 * r2 * sinl(angle) / 2;
		
		ld polygonArea = triangleArea * 2 * n;
		printf("%.9Lf\n", polygonArea);
	}
}
