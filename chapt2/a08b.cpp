#include <iostream>
#include <vector>
using namespace std;

/*
5 5
2 0 0 5 1
1 0 3 0 0
0 8 5 0 2
4 1 0 0 6
0 9 2 7 0
2
2 2 4 5
1 1 5 5
*/

int main(){
	int H, W;
	cin >> H >> W;
	
	vector<vector<int>> X(H+1, vector<int>(W+1));
	for(int i=1;i<=H;++i) for(int j=1;j<=W;++j) cin >> X.at(i).at(j);
	
	int Q;
	cin >> Q;
	vector<int> A(Q+1), B(Q+1), C(Q+1), D(Q+1);
	
	for(int i=1;i<=Q;++i) cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i);
	
	// 二次元累積和を求める
	vector<vector<int>> sum(H+1, vector<int>(W+1));

	for(int i=1;i<=H;++i) sum.at(i).at(1) = X.at(i).at(1);
	for(int i=1;i<=W;++i) sum.at(1).at(i) = X.at(1).at(i);
	for(int i=2;i<=H;++i) for(int j=1;j<=W;++j) sum.at(i).at(j) = sum.at(i-1).at(j) + X.at(i).at(j);
	for(int i=1;i<=H;++i) for(int j=2;j<=W;++j) sum.at(i).at(j) = sum.at(i).at(j-1) + sum.at(i).at(j);
	
	// 確認
	// for(int i=1;i<=H;++i){
	// 	for(int j=1;j<=W;++j) cout << sum.at(i).at(j) << " ";
	// 	cout << endl;
    // }

	// 答える
	for(int i=1;i<=Q;++i){
		int a = sum.at(C.at(i)).at(D.at(i));
		int b = sum.at(C.at(i)).at(B.at(i)-1);
		int c = sum.at(A.at(i)-1).at(D.at(i));
		int d = sum.at(A.at(i)-1).at(B.at(i)-1);
		int ans = a - b - c + d;
		// cout << a << "," << b << "," << c << "," << d << endl;
		cout << ans << endl;
	}
	
	return 0;
}