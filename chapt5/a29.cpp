#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
a b

2 8
7 3
2 42

256
343
46480318

*/

ll a, b;
ll A = 1000000007;

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
	cin >> a >> b;
	
	ll ans = Power(a, b, A);
	
	cout << ans << endl;

	return 0;
}