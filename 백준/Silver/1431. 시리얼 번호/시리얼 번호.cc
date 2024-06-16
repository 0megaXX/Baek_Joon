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

bool compare(string a, string b)
{
	if (a.length() != b.length())
		return a.length() < b.length();
	
	int a_sum = 0,b_sum=0;

	for (int l = 0; l < a.length(); l++)
	{
		if (a[l] >= 48 && a[l] < 58)
			a_sum += a[l] - '0';

		if (b[l] >= 48 && b[l] < 58)
			b_sum += b[l] - '0';
	}

	if (a_sum != b_sum)
		return a_sum < b_sum;
	else
		return a < b;


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int cass;
	cin >> cass;
	vector<string>v;
	while (cass--)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(),compare);


	for (int a = 0; a < v.size(); a++)
		cout << v[a] << '\n';


	return 0;
}