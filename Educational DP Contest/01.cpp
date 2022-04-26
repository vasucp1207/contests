#include<bits/stdc++.h>

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define popcount(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){
	
	ll n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> dp(n);
	dp[n - 1] = 0;
	
	for(int i = n - 2; i >= 0; i--){
		if(i == n - 2) dp[i] = abs(a[i] - a[i + 1]);
		else dp[i] = min(dp[i + 1] + abs(a[i] - a[i + 1]), dp[i + 2] + abs(a[i] - a[i + 2]));
	}
	
	cout << dp[0] << endl;

	return 0;
}
