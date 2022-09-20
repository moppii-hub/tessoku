#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
N
A1 A2 ... An

5
46 80 11 77 46

2 4 1 3 2
*/

ll N;
vector<ll> A(100009);

bool judge( ll x, ll a ){
	return x <= a;
}

int main(){
	cin >> N;
	vector<ll> Asorted(N);
	loopUpFrom( 0, N, i ){
		cin >> A.at(i);
		Asorted.at(i) = A.at(i);
	}
	sort(Asorted.begin(), Asorted.end());

	vector<ll> X;
	ll val = -1;
	loopUpFrom( 0, N, i ){
		if( val == Asorted.at(i) ) continue;
		val = Asorted.at(i);
		X.push_back(val);
	}

	vector<ll> B;
	loopUpFrom( 0, N, i ){
		ll L=0, R=X.size(), M=0;
		while( R-L > 1 ){
			M = (L+R)/2;
			if( judge( X.at(M), A.at(i) ) ) L = M;
			else R = M;
		}
		B.push_back( L + 1 );
	}

	loopUpFrom( 0, B.size(), i ) cout << B.at(i) << " ";
	cout << endl;
	
	return 0;
}