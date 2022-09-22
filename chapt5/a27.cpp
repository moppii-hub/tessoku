#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
A B
900 700
117 432
998224353 1000000000

100
9
1
*/

ll A, B;

ll GCD( ll a, ll b ){
	while(true){
		if( a < b ){
			ll a_ = a;
			a = b;
			b = a_;
		}
		a = a % b;
		if( a == 0 ) return b;
	}
}

int main(){
	cin >> A >> B;
	cout << GCD( A, B ) << endl;
	return 0;
}