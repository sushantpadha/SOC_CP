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
	ll n, k; cin >> n >> k;
	vector<ll> a(n), b(n);
	vector<ll> diff(n);
	vec_cin(a, n);
	vec_cin(b, n);

	ll s = 0;
	for(int i = 0; i < n; i++) {
		diff[i] = a[i] - b[i];
		s += b[i];
	}

	sort(all(diff));
	diff.push_back(-1);

	// vec_cout(diff, n)

	for (int i = 0; (i < n) && (diff[i] < 0 || i < k); i++) {
		s += diff[i];
	}
	cout << s;
}

int main() {
	fastio
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}