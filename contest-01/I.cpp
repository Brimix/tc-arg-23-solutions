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

int main() {
	map<string, string> allGems;
	allGems["purple"] = "Power";
	allGems["green"] = "Time";
	allGems["blue"] = "Space";
	allGems["orange"] = "Soul";
	allGems["red"] = "Reality";
	allGems["yellow"] = "Mind";
	
	while (cin >> n) {
		map<string, string> gems = allGems;
		forn(i, n) {
			string color; cin >> color;
			gems.erase(color);
		}
		
		cout << sz(gems) << endl;
		for(auto t : gems) cout << t.snd << endl;
	}
}
