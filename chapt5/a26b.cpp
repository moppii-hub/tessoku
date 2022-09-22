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
ll N = 300009;
vector<bool> table(N+1);

int main(){
	cin >> Q;
	loopUp(Q, i) cin >> X.at(i);
	loopUp(N, i) table.at(i) = true;
	
	// N までの数について、チェック済みかどうか確認
	// チェック対象：i（1～N）
	// チェック済みなら無視
	// チェック済みでなければ素数とみなす
	// その数の倍数をチェック済みにする
	loopUpFrom(2, N-1, i){
		if( i*i > N ) break;
		if( table.at(i) == false ) continue;
		ll baisu = i * 2;
		while( baisu <= N ) {
			table.at(baisu) = false;
			baisu += i;
		}
	}
	
	loopUp(Q, i){
		if( table.at( X.at(i) ) ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}