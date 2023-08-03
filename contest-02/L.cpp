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
typedef pair<ii, int> iii;
const int MAXN = 200500;

bool sps(iii a, iii b) {
	if (a.fst == b.fst) return a.snd < b.snd;
	
	ii af = a.fst, bf = b.fst;
	if (af.fst == bf.fst) return af.snd > bf.snd;
	return af.fst < bf.fst;
}

int n;
iii iv[MAXN];

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) >= 1) {
		forn(i, n) scanf("%d %d", &iv[i].fst.fst, &iv[i].fst.snd), iv[i].snd = i+1;
		sort(iv, iv + n, sps);
		
		//~ printf("Hola!\n");
		//~ forn(i, n) printf("%d: %d-%d\n", iv[i].snd, iv[i].fst.fst, iv[i].fst.snd);
		
		int inversionId = -1;
		forn(i, n-1) if (iv[i].fst.snd >= iv[i+1].fst.snd)
			inversionId = iv[i+1].snd;
			
		//~ printf("Inversion! %d\n", inversionId);
		if (inversionId > -1) { printf("%d\n", inversionId); continue; }
		
		int sol = -1;
		forn(i, n-2) {
			int rt = iv[i].fst.snd, lf = iv[i+2].fst.fst;
			if (rt + 1 >= lf) {
				sol = iv[i+1].snd;
				break;
			}
		}
		printf("%d\n", sol);
	}
}
