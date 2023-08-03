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
const int MAXN = 50100;

int n;
ii a[MAXN];

int main() {
	//~ freopen("input.txt", "r", stdin);
	int tc; scanf("%d", &tc);
	forn(cs, tc) {
		scanf("%d", &n);
		forn(i, n) scanf("%d", &a[i].fst), a[i].snd = i + 1;
		sort(a, a + n);
		
		bool win = (a[0].fst + a[1].fst <= a[n-1].fst);
		if (win) {
			vector<int> ids = {a[0].snd, a[1].snd, a[n-1].snd};
			sort(ids.begin(), ids.end());
			printf("%d %d %d\n", ids[0], ids[1], ids[2]);
		}
		else printf("-1\n");
	}
}
