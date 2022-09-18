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
B
c
D

3 50
3 9 17
4 7 9
10 20 30
1 2 3
*/

ll N, K;
vector<ll> A(100009), B(100009), C(100009), D(100009);
vector<ll> P(1000009), Q(1000009);

bool judge(ll t, ll v){
	if( v <= t) return true;
	return false;
}

int main(){
	cin >> N >> K;
	loopUp(N, i) cin >> A.at(i);
	loopUp(N, i) cin >> B.at(i);
	loopUp(N, i) cin >> C.at(i);
	loopUp(N, i) cin >> D.at(i);
	loopUp(N, i) loopUp(N, j){
		P.at((i-1)*N + j) = A.at(i) + B.at(j);
		Q.at((i-1)*N + j) = C.at(i) + D.at(j);
		// P.at(i*N + j) = A.at(i) + B.at(j);
		// Q.at(i*N + j) = C.at(i) + D.at(j);
	}
	sort(P.begin()+1, P.begin() + N*N + 1);
	sort(Q.begin()+1, Q.begin() + N*N + 1);
	
	// 確認
	// loopUp(N*N, i){
	// 	cout << P.at(i) << " ";
	// }
	// cout << endl;
	// loopUp(N*N, i){
	// 	cout << Q.at(i) << " ";
	// }
	// cout << endl;
	
	loopUp(N*N, i){
		ll targetNumber = K - P.at(i);
		ll L=1, M=1, R=N*N+1;
		while( R - L > 1 ){
			M = (L+R)/2;
			if( judge(targetNumber, Q.at(M)) ) L = M;
			else R = M;
		}
		if( Q.at(L) == targetNumber ){
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
	return 0;
}