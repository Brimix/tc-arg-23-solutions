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
const ll TOTAL = 1e18;

int n;
bool hasLiked;
set<ll> liked, disliked;

void addLiked(vector<ll> &V) {
	if (!hasLiked) {
		for (ll v : V) liked.insert(v);
		hasLiked = true;
		return;
	}

	set<ll> newLiked;
	for (ll v : V) if (liked.count(v)) newLiked.insert(v);
	liked = newLiked;
}

void addDisliked(vector<ll> &V) {
	for (ll v : V) disliked.insert(v);
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) >= 1) {
		hasLiked = false;
		liked.clear(), disliked.clear();
		
		forn(i, n) {
			int t, c;
			scanf("%d %d", &t, &c);

			vector<ll> v(c);
			forn(i, c) scanf("%lld", &v[i]);
			
			if (t == 1) addLiked(v);
			else        addDisliked(v);
		}
		
		if (!hasLiked) printf("%lld\n", TOTAL - sz(disliked));
		else {
			int count = 0;
			for (int l : liked) if (disliked.count(l) == 0) count ++;
			printf("%d\n", count);
		}
	}
}
