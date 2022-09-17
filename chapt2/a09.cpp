#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
5 5 2
1 1 3 3
2 2 4 4
*/

int main(){
	int H, W, N;
	cin >> H >> W >> N;
	
	vector<int> A(N+1), B(N+1), C(N+1), D(N+1);
	for(int i=1;i<=N;++i) cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i);
	
	// 差分表を作る
	vector<vector<int>> diff(H+1+1, vector<int>(W+1+1));
	for(int i=0;i<=H+1;++i) fill(diff.at(i).begin(), diff.at(i).end(), 0);
	for(int i=1;i<=N;++i){
		diff.at(A.at(i)  ).at(B.at(i)  )++;
		diff.at(C.at(i)+1).at(D.at(i)+1)++;
		diff.at(A.at(i)  ).at(D.at(i)+1)--;
		diff.at(C.at(i)+1).at(B.at(i)  )--;
	}
	

	// 確認
	// for(int i=1;i<=H;++i){
	// 	for(int j=1;j<=W;++j){
	// 		if( j!=1 ) cout << " ";
	// 		cout << diff.at(i).at(j);
	// 	}
	// 	cout << endl;
	// }

	// 差分表の累積和表を作る
	vector<vector<int>> sum(H+1+1, vector<int>(W+1+1));

	for(int i=1;i<=H;++i) sum.at(i).at(1) = diff.at(i).at(1);
	for(int i=1;i<=W;++i) sum.at(1).at(i) = diff.at(1).at(i);

	for(int i=2;i<=H;++i) for(int j=1;j<=W;++j) sum.at(i).at(j) = sum.at(i-1).at(j) + diff.at(i).at(j);
	for(int i=1;i<=H;++i) for(int j=2;j<=W;++j) sum.at(i).at(j) = sum.at(i).at(j-1) + sum.at(i).at(j);
	
	// 答え（累積和表）を出力する
	for(int i=1;i<=H;++i){
		for(int j=1;j<=W;++j){
			if( j!=1 ) cout << " ";
			cout << sum.at(i).at(j);
		}
		cout << endl;
	}
	
	return 0;
}