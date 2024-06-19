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
	
	int cass;
	cin >> cass;
	vector<int> v(cass+1);
	for (int a = 1; a <=cass; a++)
		cin >> v[a];

	vector<int>summ(cass+1);

	sort(v.begin(), v.end());

	for (int a = 1; a <= cass; a++)
		summ[a] = summ[a - 1] + v[a];




	int mainn = v[1];
	int diff = 987654321;

	for (int a = 1; a <= cass; a++)
	{
		int sub = 0;
		for (int b = 1; b <= cass; b++)
		{

			if (a == b)
			{
				int dif = (v[a] * (b - 1))-summ[b-1];
				sub += dif;
			//	cout << dif << "처음!!!\n";
			}

			if (b == cass)
			{
				int dif = (summ[b] - summ[a]) - (v[a] * (b - a));
				sub += dif;
				//cout << dif << "마지막!!!\n";
			}

		}

		if (diff > sub)
		{
			diff = sub;
			mainn = v[a];

		}

	}
	cout << mainn;
	return 0;
}