#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
Q
X1
...
XQ

4
17
31
35
49

Yes
Yes
No
No

*/

ll Q;
vector<ll> X(10009);

int main(){
	cin >> Q;
	loopUp(Q, i) cin >> X.at(i);
	
	// 素数チェックは、1からXまで総当たりする必要が無い
	// x^(1/2)まででよい
	loopUp(Q, i){
		if( X.at(i) <= 3 ){
			cout << "Yes" << endl;
			continue;
		}
		bool isPrime = true;
		for( int j=3; j*j <= X.at(i); ++j ){
			if( X.at(i) % j == 0 ){
				isPrime = false;
				break;
			}
		}
		if( isPrime ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}