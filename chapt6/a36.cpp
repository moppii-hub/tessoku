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
N K
5 10
Yes
*/

ll N, K;

int main(){
	cin >> N >> K;
	string ans = "No";
	
	if( K < (N-1)*2 ) ans = "No";
	else if( K == (N-1)*2 ) ans = "Yes";
	else if( ( K - ((N-1)*2) ) % 2 == 0 ) ans = "Yes";
	else ans = "No";
	
	cout << ans << endl;
	
	return 0;
}