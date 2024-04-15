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

	int M, N;
	int sum = 0, min = -1;
	int cnt = 0;
	cin >> M >> N;

	for (int i = M; i <= N; i++)
	{
		for (int div = 1; div <= i; div++)
		{
			if (i % div == 0)
				cnt++;
		}
		if (cnt == 2) 
		{		
			if (min == -1)		
				min = i;
			sum += i;
		}
		cnt = 0;
	}
	if (min == -1)
		cout << -1 << '\n';
	else
		cout << sum << '\n' << min << '\n';

}