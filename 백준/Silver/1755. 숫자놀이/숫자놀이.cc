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

string arr[10]{ "zero","one","two","three","four","five","six","seven","eight","nine" };


bool compare(string a, string b)
{

	string tmp_a = "";
	for (int i = 0; i < a.length(); i++)
	{
		int cur =a[i]-'0';
		tmp_a += arr[cur];

	}
	string tmp_b = "";
	for (int i = 0; i < b.length(); i++)
	{
		int cur = b[i] - '0';
		tmp_b += arr[cur];
	}


	return tmp_a < tmp_b;



}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int start, end;
	cin >> start >> end;
	vector<string> v;
	for (int a = start; a <= end; a++)
	{
		v.push_back(to_string(a));
	}

	sort(v.begin(), v.end(), compare);

	for (int a = 1; a <= v.size(); a++)
	{ 
		
			cout << v[a-1] << ' ';
		if (a % 10 == 0)
			cout << endl;
	}
	return 0;
}