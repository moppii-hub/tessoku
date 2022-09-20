#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
https://qiita.com/u2dayo/items/8c1601a61841540b4947
bit全探索の実装
Kと一致する足し方が何通りあるかを出力する

N K
A1 A2 ... An

*/

ll N, K;
vector<ll> A(31);

int main(){
	cin >> N >> K;
	loopUp(N, i) cin >> A.at(i);
	
	ll ans = 0;
	loopUpFrom( 0, (1<<N), refBitArray ){
		ll sum = 0;
		loopUpFrom( 0, N, checkBit ){
			ll checkBitArray = (1 << checkBit);
			if( refBitArray & checkBitArray ) sum += A.at(checkBit+1);
		}
		if( sum == K ) ans++;
	}
	
	cout << ans << endl;

	return 0;
}