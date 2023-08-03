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
const int MAXN = 1000500;

int n, m, s[MAXN];

int main() {
	while (scanf("%d %d", &n, &m) >= 1) {
		forn(i, n) scanf("%d", &s[i]);
		sort(s, s + n);
		printf("%d\n", s[m-1]);
	}
}
