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

ll n, m;

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%lld %lld", &n, &m) >= 1) {
		while(n > 0 && m > 0) {
			if (n >= 2*m) n %= 2*m;
			else if (m >= 2*n) m %= 2*n;
			else break;
		}
		printf("%lld %lld\n", n, m);
	}
}
