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
ll sx, sy, tx, ty;

int main() {
	while (scanf("%d", &n) >= 1) {
		scanf("%lld %lld %lld %lld", &sx, &sy, &tx, &ty);
		
		ll d = abs(sx - tx) + abs(sy - ty);
		if (n < d) { printf("0\n"); continue; }
		
		if (d == 0) { printf("%d\n", n / 2); continue; }
		
		ll wins = (n - d + 2) / 2;
		printf("%lld\n", wins);
	}
}
