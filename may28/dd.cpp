#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f(i, l, n) for(decltype(n) i = l; (l < n) ? i < n : i > n; (l < n) ? i++ : i--)
#define ll long long
#define pb push_back
#define endl '\n'
#define nl cerr << '\n'
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
	int n, k, t; cin >> n >> k;
	unordered_map<int, int> xs;

	int x_mn = INT_MAX, x_mx = INT_MIN;

	for(int i = 0; i < n; i++) {
		cin >> t;
		xs[t]++;
		x_mx = max(t, x_mx);
		x_mn = min(t, x_mn);
		for (int j = t - k; j <= t + k; j++) {
			xs[j] = xs[j];
		}
	}

	// read in rest
	for (int i = 0; i < n; i++) cin >> t;
	
	vector<int> v(x_mx - x_mn + 2 * k - 1);
	for (auto [x, f] : xs) {
		v[x - x_mn + k] = f;
	}

	int m=INT_MIN, s=0, outer=0;

	for(int a = 0; a <= k; a++) outer+=v[a];

	v.push_back(0);
	
	s = outer;

	dbg(s); nl;
	
	for(int i = 0; i < v.size() - k; i++) {
		// iterate for this sum
		outer -= v[i-1];
		outer += v[i+k];
		s = outer;

		for(int j = i; j < v.size() - k; j++) {
			
			m = max(s, m);
			s += v[j+k+1];
			if (j - i > k) s -= v[j];
		}
	}

	cout << m << '\n';
}

int main() {
	fastio
	ll t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}