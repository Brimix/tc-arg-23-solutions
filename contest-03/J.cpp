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
typedef pair<int, bool> ib;
const int MAXN = 300500;

int n, a, b;
vector<int> g[MAXN];

int beesSize, flowerSize;

ib dfs(int p, int parent) {
	int treeSize = 1, beesSubtreeSize = 0;
	bool hasBees = p == b;

	for(int q : g[p]) if (q != parent) {
		ib childAns = dfs(q, p);
		
		treeSize += childAns.fst;
		hasBees |= childAns.snd;
		if (childAns.snd) beesSubtreeSize = childAns.fst;
	}
	
	if (p == b) { // Subtree of bees
		beesSize = treeSize;
		//~ printf("Bees %d\n", beesSize);
	}
	if (p == a) { // Subtree of root
		flowerSize = n - beesSubtreeSize;
		//~ printf("Flowers %d\n", flowerSize);
	}
	//~ printf("%d: %d %s\n", p, treeSize, (hasBees ? "has bees!" : ""));
	
	return {treeSize, hasBees};
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d %d %d", &n, &a, &b) >= 1) {
		a--; b--;
		forn(i, n) g[i].clear();

		forn(i, n-1) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
			g[u].pb(v); g[v].pb(u);
		}
		
		dfs(a, -1);
		
		ll total = (ll)n * (n-1);
		ll bad = (ll) flowerSize * beesSize;
		printf("%lld\n", total - bad);
	}
}
