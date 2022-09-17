#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

/*
15 47
11 13 17 19 23 29 31 37 41 43 47 53 59 61 67

10 80
10 20 30 40 50 60 70 80 90 100
*/

int main(){
	int N, X;
	cin >> N >> X;
	
	vector<int> A(N+1);
	for(int i=1;i<=N;++i) cin >> A.at(i);
	
	vector<int>::iterator itr = lower_bound(A.begin()+1, A.end(), X);
	int ans = distance(A.begin(), itr);
	
	cout << ans << endl;
	return 0;
}