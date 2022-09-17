#include <iostream>
#include <vector>
using namespace std;

/*
8
5
2 3
3 6
5 7
3 7
1 5
*/

int main(){
	int D, N;
	cin >> D;
	cin >> N;
	
	vector<int> L(N+1), R(N+1);
	for(int i=1;i<=N;++i) cin >> L.at(i) >> R.at(i);
	
	// 差分配列を作る
	vector<int> diff(D+1);
	for(int i=1;i<=N;++i){
		int incDate = L.at(i);
		int decDate = R.at(i)+1;
		diff.at(incDate)++;
		diff.at(decDate)--;
	}
	
	// 差分配列の累積和を作る
	vector<int> sum(D+1);
	sum.at(1) = diff.at(1);
	for(int i=2;i<=D;++i){
		sum.at(i) = sum.at(i-1) + diff.at(i);
	}
	
	// 答える
	for(int i=1;i<=D;++i){
		cout << sum.at(i) << endl;
	}
	
	return 0;
}