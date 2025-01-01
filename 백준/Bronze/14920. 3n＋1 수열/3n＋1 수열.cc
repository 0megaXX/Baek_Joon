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
	

	int rs = 1;

	long long N;
	cin >> N;

	while (N != 1)
	{
		rs++;
		if (N & 1) // 홀수면 (N%2 ==1)과 동일
			N = 3 * N + 1;

		else //짝수면
			N /= 2;
	}

	cout << rs;
	return 0;

}
