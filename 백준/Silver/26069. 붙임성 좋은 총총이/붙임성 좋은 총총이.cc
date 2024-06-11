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

set<string>s;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cass;
	cin >> cass;
	s.insert("ChongChong");
	int ct = 1;
	while (cass--)
	{
		string Human_A,Human_B;
		cin >> Human_A >> Human_B;

		bool q1 = (s.find(Human_A) == s.end());
		bool q2 = (s.find(Human_B) == s.end());
		if (q1 != q2)
		{

			ct++;
			s.insert(Human_A);
			s.insert(Human_B);
		}


	}
	cout << ct;
	return 0;
}