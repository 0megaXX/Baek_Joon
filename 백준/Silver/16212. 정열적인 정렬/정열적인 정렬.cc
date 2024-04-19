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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int ct;
	cin >> ct;
	vector<int>v;
	while (ct--)
	{
		int b;
		cin >> b;
		v.push_back(b);
	}
	sort(v.begin(), v.end());

	for (int a = 0; a < v.size(); a++)
		cout << v[a] << ' ';

}