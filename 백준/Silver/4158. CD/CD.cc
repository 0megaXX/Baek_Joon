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


vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int he, she;
	cin >> he >> she;
	while (he!=0 && she!=0)
	{
		int ct = 0;
		for (int a = 0; a < he; a++)
		{
			long long b;
			cin >> b;
			v.push_back(b);

		}
		for (int a = 0; a < she; a++)
		{
			long long b;
			cin >> b;
			if (binary_search(v.begin(), v.end(), b))
				ct++;
		}
		cout << ct << '\n';
		v.clear();
		cin >> he >> she;
	}

}