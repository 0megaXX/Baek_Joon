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
#include <numeric>
#include <stack>

using namespace std;



int arr[41] = { 0,1 };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int a = 2; a <= 40; a++)
	{

		arr[a] = arr[a - 1] + arr[a - 2];

	}


	int cass;
	cin >> cass;
	while (cass--)
	{
		int b;
		cin >> b;

		if (b == 0)
			cout << 1 << " " << 0 << "\n";
		else
			cout << arr[b-1] << " " <<arr[b] << "\n";
	}


}