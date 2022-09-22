#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
N A B
First / Second

8 2 3
First
*/

ll N, A, B;

int main(){
	cin >> N >> A >> B;
	vector<bool> dp(N+1);
	
	dp.at(1) = false;
	
	loopUpFrom( 2, N-1, i ){
		if( i - A >= 1 ){
			if( dp.at(i-A) == false ){
				dp.at(i) = true;
				continue;
			}
		}
		if( i - B >= 1 ){
			if( dp.at(i-B) == false ){
				dp.at(i) = true;
				continue;
			}
		}
		dp.at(i) = false;
	}
	
	if( dp.at(N) ) cout << "First" << endl;
	else cout << "Second" << endl;
	
	return 0;
}