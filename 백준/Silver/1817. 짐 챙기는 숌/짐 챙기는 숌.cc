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
struct Mystruct
{
	int start, end, len;
};
int city, cass;
int MAXX = 987654321;
int arr[401][401];
vector<Mystruct>v;



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int arr[51];

	cin >> n >> m;
	if (n == 0) 
	{
		cout << "0\n" ;
		return 0;
	}

	for (int a = 0; a < n; a++) 
		cin >> arr[a];
	int ans = 0;
	int now = 0;
	for (int a = 0; a < n; a++)
	{
		if (now + arr[a] <= m)
			now += arr[a];
		else
		{
			ans++;
			now = arr[a];
		}
	}
	if (now != 0) 
		ans++;

	cout << ans << '\n';

}
