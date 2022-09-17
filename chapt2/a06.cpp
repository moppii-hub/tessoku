#include <iostream>
#include <vector>
using namespace std;

/*
15 3
62 65 41 13 20 11 18 44 53 12 18 17 14 10 39
4 13
3 10
2 15
*/

int main(){
	int N, Q;
	cin >> N >> Q;
	
	vector<int> A(N);
	for(int i=0;i<N;++i) cin >> A.at(i);
	
	vector<int> L(Q), R(Q);
	for(int i=0;i<Q;++i) cin >> L.at(i) >> R.at(i);
	
	// 累積和を求める
	vector<int> sum(N);
	sum.at(0) = A.at(0);
	for(int i=1;i<N;++i) sum.at(i) = sum.at(i-1) + A.at(i);
	
	// 質問に答える
	for(int i=0;i<Q;++i){
		int totalDate = R.at(i) - 1;
		int total = sum.at( totalDate );
		int notIncludedDate = L.at(i) - 1 - 1;
		int notIncluded = sum.at( notIncludedDate );
		int ans = total - notIncluded;
		cout << ans << endl;
	}
	
	return 0;
}