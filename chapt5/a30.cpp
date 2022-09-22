#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
n r

4 2
19284 3294

6
326406609
*/

ll n, r;
ll A = 1000000007; // prime

ll Power( ll a, ll b, ll M ){
	ll ans = 1;
	ll x = a;
	// b乗を分解する
	while( b > 0 ){
		if( b & 0x01 ){
			ans *= x;
			ans %= M;
		}
		x *= x;
		x %= M; // これも必要
		b >>= 1;
	}
	return ans;
}

int main(){
	cin >> n >> r;
	
	// nまでの階乗を求める（随時modをとる）
	vector<ll> kaijo(n+1);
	kaijo.at(1) = 1;
	loopUpFrom(2, n-1, i) kaijo.at(i) = (kaijo.at(i-1) * i)%A;
	
	// n!, r!x(n-r)! を求める
	ll bunbo, bunshi;
	bunshi = kaijo.at(n);
	bunbo =( kaijo.at(r) * kaijo.at(n-r) ) % A;
	
	// bunbo を掛け算に変換
	// bunshi / bunbo --> bunshi x bunbo^(A-2)
	ll ans = ( bunshi * Power(bunbo, A-2, A) ) % A;
	
	cout << ans << endl;
	
	return 0;
}