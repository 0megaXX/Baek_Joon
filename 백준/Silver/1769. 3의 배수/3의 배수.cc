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

	string str;
	cin >> str;
	int count = 0;
	while (int(str.size()) != 1)
	{
		int sum = 0;
		for (unsigned i = 0; i < str.size(); i++)
			sum += int(str[i]) - 48;

		str = to_string(sum);
		count++;
	}
	cout << count << '\n';
	if (str == "3" || str == "6" || str == "9")
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';



}