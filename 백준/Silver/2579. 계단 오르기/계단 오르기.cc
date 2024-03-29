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
#include <deque>
using namespace std;













int arr[301]{ 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int ct = 0;

	cin >> ct;
	int floor[301]{ 0 };
	for (int a = 1; a <= ct; a++)
	{
		int b = 0;
		cin >> b;
		floor[a]=b;
	}

	arr[1] = floor[1];
	arr[2] = floor[2]+floor[1];
	arr[3] = max(floor[2] + floor[3], floor[1] + floor[3]);

	for (int a = 4; a <= ct+1; a++)
	{
		arr[a] = max(arr[a - 3] + floor[a - 1] + floor[a], arr[a - 2] + floor[a]);
		

	}
	cout << arr[ct];

}
