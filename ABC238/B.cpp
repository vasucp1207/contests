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

// const int mod = 1e9 + 7;

using namespace std;

int main(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> angle;
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		angle.pb(sum % 360);
	}
	
	sort(all(angle));
	int res = angle[0];
	int curr;
	for(int i = 1; i < angle.size(); i++){
		curr = angle[i] - angle[i - 1];
		res = max(res, curr);
	}
	res = max(res, 360 - angle[angle.size() - 1]);
	cout << res << endl;
	


return 0;
}
