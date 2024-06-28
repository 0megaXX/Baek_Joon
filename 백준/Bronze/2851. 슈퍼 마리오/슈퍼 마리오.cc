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



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[10];
	for (int i = 0; i < 10; i++) 
		cin >> arr[i];
	
	int sum = 0;
	for (int i = 0; i < 10; i++) 
	{
		int afterSum = sum + arr[i];
		if (afterSum >= 100) {
			if (afterSum - 100 <= 100 - sum) 		
				cout << afterSum;
			else 
				cout << sum;
			
			return 0;
		}
		sum = afterSum;
	}
	cout << sum;
}


