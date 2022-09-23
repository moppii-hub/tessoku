#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

#define loopUpFromTo(startNum, endNum, indexName) for( int indexName=startNum; indexName<endNum; ++indexName )
#define loopUpFrom(startNum, loopCount, indexName) loopUpFromTo(startNum, loopCount+startNum, indexName)
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)
#define loopUpFrom0(loopCount, indexName) loopUpFrom(0, loopCount, indexName)

/*
D N
L1 R1 H1
...
Ln Rn Hn
*/

ll D, N;
vector<ll> L(10009), R(10009), H(10009);
vector<ll> hour(365);

int main(){
	cin >> D >> N;
	
	loopUp(N, i) cin >> L.at(i) >> R.at(i) >> H.at(i);
	loopUpFrom0(D, i) hour.at(i) = 24;
	
	loopUp(N, i){
		for( int j=L.at(i); j<= R.at(i); ++j ){
			hour.at(j-1) = min( H.at(i), hour.at(j-1) );
		}
	}
	ll ans = 0;
	loopUpFrom0(D, i) ans += hour.at(i);
	
	cout << ans << endl;
	return 0;
}