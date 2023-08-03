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

int k, p;

ll getZcy(ll n) {
	string s = to_string(n);
	string r = s; reverse(r.begin(), r.end());
	
	string t = s + r;
	ll ans = 0;
	for(char c : t) ans = ans * 10 + (c - '0');
	return ans;
}

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &k, &p) >= 1) {
		ll ans = 0;
		forr(i, 1, k + 1) {
			ll cur = getZcy(i);
			//~ printf("c: %lld\n", cur);
			ans = (ans + cur) %p;
		}
		printf("%lld\n", ans);
	}
}
