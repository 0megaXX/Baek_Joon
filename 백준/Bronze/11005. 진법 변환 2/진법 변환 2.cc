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
#include <unordered_set>
#include <chrono>

using namespace std;
#define MAXX 99999999




int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, B;

	cin >> N >> B;

	string str;

	while (N > 0)
	{
		int temp = N % B;

		if (temp > 9)
		{
			str += temp - 10 + 'A';
		}
		else
		{
			str += temp + '0';
		}
		N /= B;
	}

	reverse(str.begin(), str.end());

	cout << str;

}
