#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>

// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;

using namespace std;
	
int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;

	char a[n][m];
	int dp[n][m];	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			dp[i][j] = 0;
		}
	}

	dp[n - 1][m - 1] = 1;
	for(int i = n - 2; i >= 0; i--){
		if(a[i][m - 1] == '#') dp[i][m - 1] = 0;
		else dp[i][m - 1] = dp[i + 1][m - 1];
	}
	for(int i = m - 2; i >= 0; i--){
		if(a[n - 1][i] == '#') dp[n - 1][i] = 0;
		else dp[n - 1][i] = dp[n - 1][i + 1];
	}

	for(int i = n - 2; i >= 0; i--){
		for(int j = m - 2; j >= 0; j--){
			if(a[i][j] == '#') dp[i][j] = 0;
			else dp[i][j] = (dp[i + 1][j] % mod + dp[i][j + 1] % mod) % mod;
		}
	}

	cout << dp[0][0] << endl;


 

    

	return 0;
}
