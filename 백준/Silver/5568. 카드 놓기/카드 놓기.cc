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

using namespace std;



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	vector <int> v;
	for (int a = 0; a < n; a++) {
		int x;
		cin >> x;
		v.push_back(x);
	}


	sort(v.begin(), v.end());


	set <string> s;
	do {
		string res;
		for (int i = 0; i < k; i++) {
			res += to_string(v[i]);
		}
		s.insert(res);
	} while (next_permutation(v.begin(), v.end()));
	cout << s.size();
}
