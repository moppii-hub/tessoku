#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
N K
A1 A2 ... An

7 10
11 12 16 22 27 28 31
ans = 11
*/

ll N, K;
vector<ll> A(100009);

int main(){
	cin >> N >> K;
	loopUp(N, i) cin >> A.at(i);
	
	ll ans = 0;
	
	loopUp(N, i){
		ll L = i, R = N;
		while( L<R ){
			ll M = (L+R)/2;
			if( A.at(M) == A.at(i) + K ){
				L = M;
				break;
			}
			else if( A.at(M) < A.at(i) + K ) L = M + 1;
			else R = M - 1;
		}
		cout << i << " : " << i << ", " << L << endl;
		ans += ( L - i );
	}
	
	cout << ans << endl;
	
	return 0;
}