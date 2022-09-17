#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<=loopCount-startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)


/*
N K
A1 A2 ... An

4 10
1 2 3 4
ans = 6
*/

ll N, K;
vector<ll> A(100009);

ll calcPrintCount(const ll time){
	int printCount = 0;
	loopUp(N, i){
		printCount += time / A.at(i);
	}
	return printCount;
}
// time秒までの印刷枚数がK以上かどうか
//		K以上 --> timeピッタリ or より短いtime
//		Kより小さい --> 答えはもっと長いtime
bool countIsUpperThanK(const ll time){
	ll printCount = calcPrintCount(time);
	if( printCount >= K ) return true;
	return false;
}

int main(){
	cin >> N >> K;
	loopUp(N, i) cin >> A.at(i);
	
	ll L=1, R=1'000'000'000, M=1;
	while(L<R){
		M = (L+R)/2;
		// true なら、答えはM以下
		// false なら、答えはMより上
		bool isUpper = countIsUpperThanK(M);
		if( isUpper ) R = M;	// もっと下を探す
		else L = M+1;			// もっと上を探す
	}
	
	// L=Rの時にここに来る
	// L, Rいずれも答えを示す
	cout << L << endl;
	
	return 0;
}