#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
N K
A1 A2 ... An

4 10
1 2 3 4
ans = 6

*/

int main(){
	int N, K;
	cin >> N >> K;
	
	vector<int> A(N+1);
	for(int i=1;i<=N;++i) cin >> A.at(i);
	
	// 印刷速度が早い順に並べかえる
	// sort(A.begin(), A.end());
	
	int k = 0;
	int t = 0;
	while( k < K ){
		t++;
		for(int i=1;i<=N;++i){
			if( t < A.at(i) ) continue;
			if( t % A.at(i) == 0) k++;
		}
	}
	
	cout << t << endl;
	
	return 0;
}