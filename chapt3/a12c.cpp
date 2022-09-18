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

4 10
1 2 3 4
ans = 6

*/

ll N, K;
vector<ll> A(100009);

bool judge(ll time){
	ll count = 0;
	loopUp(N, i){
		count += time / A.at(i);
	}
	return count < K;
}

int main(){
	cin >> N >> K;
	loopUp(N, i) cin >> A.at(i);
	
	ll ans = 0;
	
	ll L = 1, R = 1000000001;
	while( R-L > 1 ){
		ll M = (L+R)/2;
		cout << L << ", " << R << ", " << M << endl;
		if( judge(M) ) L = M;
		else R = M;
	}
	
	cout << R << endl;
	
	return 0;
}
