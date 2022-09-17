#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
7
1 2 5 5 2 3 1
2
3 5
4 6
*/

int main(){
	int N;
	cin >> N;
	
	vector<int> A(N+1);
	for(int i=1;i<=N;++i) cin >> A.at(i);
	
	int D;
	cin >> D;
	
	vector<int> L(D+1), R(D+1);
	for(int i=1;i<=D;++i) cin >> L.at(i) >> R.at(i);
	
	// 左からの累積最大値配列を作る
	vector<int> leftMax(N+1);
	leftMax.at(1) = A.at(1);
	for(int i=2;i<=N;++i) leftMax.at(i) = max( leftMax.at(i-1), A.at(i) );
	
	// 右からの累積最大値配列を作る
	vector<int> rightMax(N+1);
	rightMax.at(N) = A.at(N);
	for(int i=N-1;i>=1;--i) rightMax.at(i) = max( rightMax.at(i+1), A.at(i) );
	
	// 確認
	// for(int i=1;i<=N;++i) cout << A.at(i) << " ";
	// cout << endl;
	// for(int i=1;i<=N;++i) cout << leftMax.at(i) << " ";
	// cout << endl;
	// for(int i=1;i<=N;++i) cout << rightMax.at(i) << " ";
	// cout << endl;
	// cout << endl;
	
	// 答える
	for(int i=1;i<=D;++i){
		int ans_left, ans_right;
		ans_left = leftMax.at( L.at(i)-1 );
		ans_right = rightMax.at( R.at(i)+1 );
		int ans = max( ans_left, ans_right );
		cout << ans << endl;
	}
	
	return 0;
}