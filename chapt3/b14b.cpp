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

6 100
10 27 35 38 45 50

*/

ll N, K;
vector<ll> A(31);

bool judge( ll p, ll q, ll k ){
	return p + q == k;
}

int main(){
	cin >> N >> K;
	loopUp(N, i) cin >> A.at(i);
	
	ll B_length = N/2;
	ll C_length = N - B_length;
	vector<ll> B, C;
	
	loopUpFrom(1, B_length, i) B.push_back( A.at(i) );
	loopUpFrom(B_length+1, C_length, i) C.push_back( A.at(i) );
	
	// bit全探索
	vector<ll> P, Q;
	loopUpFrom(0, (1 << B_length), bitIndex){
		ll sum = 0;
		loopUpFrom( 0, B_length, arrayIndex){
			ll arrayBit = 1 << arrayIndex;
			if( arrayBit & bitIndex ) sum += B.at(arrayIndex);
		}
		P.push_back(sum);
	}
	loopUpFrom(0, (1 << C_length), bitIndex){
		ll sum = 0;
		loopUpFrom( 0, C_length, arrayIndex){
			ll arrayBit = 1 << arrayIndex;
			if( arrayBit & bitIndex ) sum += C.at(arrayIndex);
		}
		Q.push_back(sum);
	}
	
	// 確認
	// loopUpFrom(0, P.size(), i) cout << P.at(i) << ", ";
	// cout << endl;
	// loopUpFrom(0, Q.size(), i) cout << Q.at(i) << ", ";
	// cout << endl;
	
	// sort
	sort(P.begin(), P.end());
	sort(Q.begin(), Q.end());
	
	// 半分全探索？
	loopUpFrom(0, P.size(), i){
		//二分探索
		ll L = 0, R = Q.size() + 1, M = 1;
		while( R - L > 1 ){
			M = (L+R)/2;
			if( judge(P.at(i), Q.at(M), K) ) L = M;
			else R = M;
		}
		if( P.at(i) + Q.at(L) == K ){
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
	return 0;
}