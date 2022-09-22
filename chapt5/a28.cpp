#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define loopUpFrom(startNum, loopCount, indexName) for( int indexName=startNum; indexName<loopCount+startNum; ++indexName )
#define loopUp(loopCount, indexName) loopUpFrom(1, loopCount, indexName)

/*
N
T1 A1
...
TN AN

4
+ 57
+ 43
* 100
- 1

57
100
0
9999
*/

ll N;
vector<char> T(100009);
vector<ll> A(100009);

int main(){
	cin >> N;
	loopUp(N, i) cin >> T.at(i) >> A.at(i);
	
	ll figure = 0;
	loopUp(N, i){
		switch( T.at(i) ){
			case '+':
			{
				figure += A.at(i);
				figure %= 10000;
				break;
			}
			case '-':
			{
				figure -= A.at(i);
				while( figure < 0 ) figure += 10000;
				figure %= 10000;
				break;
			}
			case '*':
			{
				figure *= A.at(i);
				figure %= 10000;
				break;
			}
			default:
				break;
		}
		cout << figure << endl;
	}
	

	return 0;
}