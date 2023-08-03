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
const int MAXN = 100500;

int n, V[MAXN], T[MAXN];
ll ST[MAXN];

int tod(ll v, int i) {
	int l = i, r = n + 1;
	while(r - l > 1) {
		int m = (l + r) / 2;
		if (ST[m] - ST[i] >= v) r = m;
		else l = m;
	}
	return r - 1;
}

int main() {
	while (scanf("%d", &n) >= 1) {
		forn(i, n) scanf("%d", &V[i]);
		forn(i, n) scanf("%d", &T[i]);
		
		ST[0] = 0; forr(i, 1, n+1) ST[i] = ST[i-1] + T[i-1];
		
		vector<int> count(n+3, 0);
		vector<ll> ans(n, 0);
		
		forn(i, n) {
			int j = tod(V[i], i);
			
			count[i]++; count[j]--;
			ans[j] += V[i] - (ST[j] - ST[i]);
			//~ printf("C: "); forn(j, n + 1) printf(" %d", count[j]); puts("");
			//~ printf("S: "); forn(j, n + 1) printf(" %lld", ans[j]); puts("");
		}
		
		int totalCount = 0;
		forn(i, n) {
			totalCount += count[i];
			ans[i] += totalCount * T[i];
		}
		
		forn(i, n) {
			if (i) printf(" ");
			printf("%lld", ans[i]);
		} puts("");
	}
}
