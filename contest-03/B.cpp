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
priority_queue<int> pq;

int main() {
	//~ freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> n) {
		while (!pq.empty()) pq.pop();
		vector<string> ans;

		forn(i, n) {
			string queryType; cin >> queryType;
			if (queryType == "insert") {
				int val; cin >> val;
				pq.push(-val);

				ans.pb(queryType + ' ' + to_string(val));
			} else if (queryType == "removeMin") {
				if (pq.empty()) ans.pb("insert 1"), pq.push(1);
				pq.pop();

				ans.pb(queryType);
			} else if (queryType == "getMin") {
				int val; cin >> val;

				while (!pq.empty() && pq.top() > -val) ans.pb("removeMin"), pq.pop();

				if (pq.empty() || pq.top() < -val) ans.pb("insert " + to_string(val)), pq.push(-val);
				
				ans.pb(queryType + ' ' + to_string(val));
			} else assert(false);
		}
		
		cout << sz(ans) << endl;
		for (string q : ans) cout << q << endl;
	}
}
