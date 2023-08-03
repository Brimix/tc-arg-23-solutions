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
typedef pair<ll, int> li;
const int LIM = 26;
const ll INF = 1e18 + 50;

int n;
ll ady[LIM][LIM], dists[LIM][LIM];
string s;

ll dist[LIM];
void dijkstra(ll st) {
	forn(i, LIM) dist[i] = INF;
	
	priority_queue<li> Q;
	dist[st] = 0; Q.push({0, st});
	
	while(!Q.empty()) {
		li nxt = Q.top(); Q.pop();
		ll d = -nxt.fst; int p = nxt.snd;
		
		forn(q, LIM) {
			ll nd = d + ady[p][q];
			
			if (nd < dist[q]) {
				dist[q] = nd; Q.push({-nd, q});
			}
		}
	}
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	//~ forn(_, 4) {
	//~ forn(i, LIM) forn(j, LIM) dists[i][j] = INF;

	forn(i, LIM) forn(j, LIM) cin >> ady[i][j];
	
	forn(i, LIM) {
		dijkstra(i);
		forn(j, LIM) dists[i][j] = dist[j];
	}
	
	//~ forn(i, 5) {
		//~ forn(j, 5) printf("%lld ", dists[i][j]);
		//~ puts("");
	//~ }
	
	ll ans = 0;
	cin >> s; n = sz(s);
	forn(i, n/2) {
		int a = s[i] - 'a', b = s[n-1-i] - 'a';
		
		//~ printf("Pruebo %d y %d\n", a, b);
		ll bst = INF;
		forn(c, LIM) bst = min(bst, dists[a][c] + dists[b][c]);
		//~ cout << bst << endl;
		ans += bst;
	}
	cout << ans << endl;
	//~ }
}
