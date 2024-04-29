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

set<string>s;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	for (int a = 0; a < str.length(); a++)
	{
		
		string sub_str = "";
		for (int b = a; b <str.length(); b++)
		{
			sub_str += str[b];
			s.insert(sub_str);
		}
	}
	cout << s.size() ;


}