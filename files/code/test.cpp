#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxN = 2e5;
int n, k;
int a[maxN] = {};

bool works(ll mid){
	int groups = 0;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > mid) return false;
		if(sum + a[i] > mid){
			sum = 0;
			groups++;
		}
		sum += a[i];
	}
	return (groups < k);
}

int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll lo = 0; ll hi = 2e14+1;

	while(lo < hi){
		ll mid = lo + (hi - lo)/2;
		if(works(mid)){
			hi = mid;
		} else {
			lo = mid+1;
		}
	}

	cout << hi;

	return 0;
}