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
	while (cin >> n >> s) {
		int cnt = 0;
		for(int i = 0; i < n; i += 2) if (s[i] == s[i+1]) {
			cnt++;
			if (s[i] == 'a') s[i+1] = 'b';
			else             s[i] = 'a';
		}
		cout << cnt << endl << s << endl;
	}
}
