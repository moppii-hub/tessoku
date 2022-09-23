#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

#define loopUpFromTo(startNum, endNum, indexName) for( int indexName=startNum; indexName<endNum; ++indexName )
#define loopUpFrom(startNum, loopCount, indexName) loopUpFromTo(startNum, loopCount+startNum, indexName)
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
N M B
A1 A2 ... AN
C1 C2 ... CN

2 3 100
10 20
1 2 3

702
*/

ll N, M, B;
vector<ll> A(200009), C(200009);

int main(){
	cin >> N >> M >> B;
	loopUp(N, i) cin >> A.at(i);
	loopUp(M, i) cin >> C.at(i);
	
	ll sum = 0;
	
	// A
	loopUp(N, i) sum += A.at(i)*M;
	
	// B
	sum += ( B * N * M );
	
	// C
	loopUp(M, i) sum += C.at(i)*N;
	
	cout << sum << endl;
	
	return 0;
}