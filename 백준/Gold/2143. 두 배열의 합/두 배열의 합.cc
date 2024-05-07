#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <stack>
#include <cstring> 
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int target;
	cin >> target;
	int a_cass, b_cass;
	cin >> a_cass;

	vector<int>v_a{0};
	vector<int>a_sum;

	for (int a = 1; a <= a_cass; a++) //a집합의 누적합을 만드는 과정
	{
		int b;
		cin >> b;
		v_a.push_back(v_a[a - 1] + b);
	}

	for(int a=0;a<=a_cass;a++)         //a집합의 누적합을 통해 만들수있는 연속된 수를 전부 만듬
		for (int b = 0; b < a; b++)
			a_sum.push_back(v_a[a] - v_a[b]);

	cin >> b_cass;
	vector<int>v_b{0};
	vector<int>b_sum;
	for (int a = 1; a <= b_cass; a++) //b집합의 누적합을 만드는 과정
	{
		int b;
		cin >> b;
		v_b.push_back(v_b[a - 1] + b);
	}

	for (int a = 0; a <= b_cass; a++)    //b집합의 누적합을 통해 만들수있는 연속된 수를 전부 만듬
		for (int b = 0; b < a; b++)
			b_sum.push_back(v_b[a] - v_b[b]);


	sort(a_sum.begin(), a_sum.end()); //정렬
	sort(b_sum.begin(), b_sum.end()); //정렬


	
	long long ct = 0;
	for (auto A : a_sum)
	{
		int ub=upper_bound(b_sum.begin(),b_sum.end(),target-A)-b_sum.begin();
		//a+b를 통해 target을 만들수 있는 수를 찾기 위한 upper_bound - lower_bound 를 함
		
		int lb=lower_bound(b_sum.begin(), b_sum.end(), target - A) - b_sum.begin();

		ct += (ub - lb); //만약 (a+b)!=target인 경우 ub - lb 의 값은 0임
	}
	cout << ct;
}