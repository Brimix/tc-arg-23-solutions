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
const int MAXN = 200500;

vector<int> g[1<<K];int n;  // K such that 2^K>=n
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	for(int y:g[x]){if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	forr(k,1,K)forn(x,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}


memo[current][p][q[["casa"]

int q;

int main() {
	while (scanf("%d %d", &n, &q) >= 1) {
		forn(i, n) {
			int p; scanf("%d", &p);
			if (p >= 0) g[p].pb(i);
		}
		
		forn(i, n) {
			printf("%d:", i); for(int j : g[i]) printf(" %d", j);
			puts("");
		}
		
		lca_init();
		forn(i, q) {
			int x, y;
			scanf("%d %d", &x, &y);
			int p = lca(x, y);
			printf("Holi: %d-%d -> %d\n", x, y, p);
			
			printf("%s\n", (p == y ? "Yes" : "No"));
		}
	}
}
	
