#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f(i, l, n) for(decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define ll long long
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vec_cin(v,n) f(i,0,n) cin >> v[i];
#define vec_cout(v,n) f(i,0,n) cout << v[i] << " "; cout<<endl;
#define dbg(x) cerr << #x << " = " << x << ", ";

using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll,ll>;
using vpi = vector<pi>;
using usi = unordered_set<ll>;
using si = set<ll>;
using msi = multiset<ll>;
using mi = map<ll,ll>;
using umi = unordered_map<ll,ll>;

void solve() {
	ll n; cin >> n;
	ll a, b, c; cin >> a >> b >> c;

	vi dp(n + 1, 0);

	dp[0] = 1;

	for (ll i = 1; i <= n; i++) {
		ll mx = 0;
		if (i - a >= 0) mx = max(mx, dp[i-a]);
		if (i - b >= 0) mx = max(mx, dp[i-b]);
		if (i - c >= 0) mx = max(mx, dp[i-c]);

		if (mx) dp[i] = mx + 1;
	}
	
	cout << dp[n] - 1;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}