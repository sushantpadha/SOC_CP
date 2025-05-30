#include <bits/stdc++.h>
using namespace std;


// fix first k elements, and for rest swap (k) with (k)...(n-1) and recurse
// at d-depth recursion, d-th elements vary so all unique
// terminate when n-k=1

// total swaps = n + n(n-1) + n(n-1)(n-2) + ... + n(n-1)...2
void permute(int n, vector<int>& arr, int k = 0) {
	if (n - k == 1) {
		// for(auto i: arr) cout << i << " ";
		// cout << "\n";
	}
	for (int i = k; i < n; i++) {
		swap(arr[k], arr[i]);
		permute(n, arr, k+1);
		swap(arr[k], arr[i]);  // reset
	}
}

// build the permutation as:
// push an element from the unchosen elements (using boolean index `chosen`)
void search(int n, vector<int>& arr, vector<bool>& chosen) {
	if ((int)arr.size() == n) {
		// for(auto i: arr) cout << i << " ";
		// cout << "\n";
	} else {
		for (int i = 0; i < n; i++) {
		if (chosen[i]) continue;
		chosen[i] = true;
		arr.push_back(i);
		search(n, arr, chosen);
		chosen[i] = false;
		arr.pop_back();
	}
}
}

int main() {
	int n = 11;
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	permute(n, a);

	cout << "-----------------------------\n";

	vector<int> perm = {};
	vector<bool> chosen(n);

	search(n, perm, chosen);

	// basic gprof-iling suggests same speed?
}