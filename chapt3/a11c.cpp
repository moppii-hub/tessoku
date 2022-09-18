#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
15 47
11 13 17 19 23 29 31 37 41 43 47 53 59 61 67

10 80
10 20 30 40 50 60 70 80 90 100
*/

ll N, X;
vector<ll> A(100009);

bool judge(ll M){
	return A.at(M) <= X;
}

int main(){
	cin >> N >> X;
	loopUp(N, i) cin >> A.at(i);
	
	ll ans = 0;
	
	ll L = 1, R = N + 1;
	while( R-L > 1 ){
		ll M = (L+R)/2;
		if( judge(M) ) L = M;
		else R = M;
	}
	
	cout << L << endl;
	
	return 0;
}
