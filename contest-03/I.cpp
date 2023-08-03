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

int n;
string s;

int main() {
	//~ freopen("input.txt", "r", stdin);
	while (cin >> s) {
		n = sz(s);
		
		ll ans = 0;
		forn (i, n) ans += (s[i] == '0' || s[i] == '4' || s[i] == '8');
		
		forn(i, n-1) {
			int val = stoi(s.substr(i, 2));
			if (val%4 == 0) ans += i + 1;
		}
		printf("%lld\n", ans);
	}
}
