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
	int tc; scanf("%d", &tc);
	forn (cs, tc) {
		cin >> n >> s;
		
		int acum = 0, mn = 0;
		forn(i, n) {
			acum += (s[i] == '(' ? 1 : -1);
			mn = min(acum, mn);
		}
		
		cout << -mn << endl;
	}
}
