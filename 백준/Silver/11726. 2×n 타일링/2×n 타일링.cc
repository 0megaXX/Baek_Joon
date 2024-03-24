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

long long arr[1001] = {0,1,2};
long long fn(int a)
{
	if (arr[a] != 0)
		return arr[a];
	else
		return arr[a] =( fn(a - 1) + fn(a - 2))%10007;

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int cass;
	cin >> cass;

	long long b= fn(cass);
	cout << b ;
	
	
}

	