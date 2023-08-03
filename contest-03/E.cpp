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

int n, m, k, a, ableK, hits[MAXN];
set<ii> s;

int calcAble(ii iv) {
	int len = iv.snd - iv.fst;
	return (len + 1) / (a + 1);
}

void splitIn(int t) {
	ii iv = *prev(s.lower_bound({t+1, -1}));
	
	s.erase(iv);
	ableK -= calcAble(iv);
	
	ii iv1 = {iv.fst, t};
	ii iv2 = {t+1, iv.snd};
	
	if (iv1.fst < iv1.snd) s.insert(iv1), ableK += calcAble(iv1);
	if (iv2.fst < iv2.snd) s.insert(iv2), ableK += calcAble(iv2);
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d %d %d", &n, &k, &a) >= 1) {
		scanf("%d", &m);
		forn (i, m) scanf("%d", &hits[i]), hits[i]--;

		s = {{0, n}};
		ableK = calcAble({0, n});
		
		if (ableK < k) { printf("0\n"); continue; }
		
		int ans = -1;
		forn (i, m) {
			splitIn(hits[i]);
			if (ableK < k) { ans = i+1; break; }
		}
		printf("%d\n", ans);
	}
}
