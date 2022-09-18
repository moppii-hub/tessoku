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
	
	vector<ll> R(100009);
	loopUp(N-1, i){
		// 尺取り虫の右端（インデックス）の開始位置を決める
		if( i == 1 ) R.at(i) = 1;
		else R.at(i) = R.at(i-1);
		
		// 右端を広げていく
		ll additiveIndex = 1;
		while(( R.at(i) < N )&&( A.at(R.at(i)+1) <= A.at(i) + K )) R.at(i)++;
	}
	
	ll ans = 0;
	loopUp(N-1, i){
		ans += R.at(i) - i;
	}
	cout << endl;
	
	cout << ans << endl;
	
	return 0;
}