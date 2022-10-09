#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

#define loopUpFromTo(startNum, endNum, indexName) for( int indexName=startNum; indexName<endNum; ++indexName )
#define loopUpFrom(startNum, loopCount, indexName) loopUpFromTo(startNum, loopCount+startNum, indexName)
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)
#define loopUpFrom0(loopCount, indexName) loopUpFrom(0, loopCount, indexName)

ll N, M;
vector<vector<ll>> G(100009, vector<ll>());

int main(){
	cin >> N >> M;
	
	loopUp(M, i){
		ll a, b;
		cin >> a >> b;
		G.at(a).push_back(b);
		G.at(b).push_back(a);
	}
	
	loopUp(N, i){
		cout << i << ": {";
		ll size = G.at(i).size();
		loopUpFrom0( size, j ){
			if( j > 0 ) cout << ", ";
			cout << G.at(i).at(j);
		}
		cout << "}" << endl;
		// loopUpFrom0(size-1, j){
		// 	cout << G.at(i).at(j) << ", ";
		// }
		// cout << G.at(i).at(size-1) << "}" << endl;
	}
	
	return 0;
}