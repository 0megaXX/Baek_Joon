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

	int human;
	cin >> human;
	
	for (int a = 0; a < human; a++)
	{
		int b;
		cin >> b;
		v.push_back(b);
	}
	sort(v.rbegin(), v.rend());
	long long  summ = 0;
	for (int a = 0; a < human; a++)
	{
		long long  rs = v[a] - (a + 1 - 1);
		//cout << a << " " << rs << endl;
		if (rs>0)
			summ += rs;
		else
			break;
		
	}

	cout << summ;
}