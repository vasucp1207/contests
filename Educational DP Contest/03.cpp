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

int a[100005][4];
int dp[100005][4];
int n;

int solve(int day, int act){
	
	if(day > n) return 0;
	
	if(dp[day][act] != -1) return dp[day][act];
	
	int mx = -1;
	if(act == 0){
		mx = max(mx, a[day][1] + solve(day + 1, 1));
		mx = max(mx, a[day][2] + solve(day + 1, 2));
		mx = max(mx, a[day][3] + solve(day + 1, 3));
	}
	
	else if(act == 1){
		mx = max(mx, a[day][2] + solve(day + 1, 2));
		mx = max(mx, a[day][3] + solve(day + 1, 3));
	}
	
	else if(act == 2){
		mx = max(mx, a[day][1] + solve(day + 1, 1));
		mx = max(mx, a[day][3] + solve(day + 1, 3));
	}
	
	else{
		mx = max(mx, a[day][1] + solve(day + 1, 1));
		mx = max(mx, a[day][2] + solve(day + 1, 2)); 
	}
	dp[day][act] = mx;
	return mx;
}
 
int main() {
 
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = -1;
	}
	
	int ans = solve(1, 0);
	cout << ans << endl;
	
	
	
 
	return 0;
}
