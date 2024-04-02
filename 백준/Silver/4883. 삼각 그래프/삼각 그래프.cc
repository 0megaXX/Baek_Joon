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


int arr[100003][4];
int dp[100003][4];




void fn(int sizz)
{
	for (int a = 2; a <= sizz; a++)
	{

		dp[a][2] = min(dp[a][2], dp[a][1] + arr[a][2]);
		dp[a][3] = min(dp[a][3], dp[a][2] + arr[a][3]);


		dp[a + 1][1] = min(dp[a][1] + arr[a + 1][1], dp[a][2] + arr[a + 1][1]);
		dp[a + 1][2] = min({ dp[a][1] + arr[a + 1][2], dp[a][2] + arr[a + 1][2] ,dp[a][3] + arr[a + 1][2] });
		dp[a + 1][3] = min({ dp[a][2] + arr[a + 1][3] ,dp[a][3] + arr[a + 1][3] });

	}


}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int not_0;
	int ct = 1;

	cin >> not_0;
	while (not_0 != 0)
	{
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));

		for (int a = 1; a <= not_0; a++)
		{
			int b, c, d;
			cin >> b >> c >> d;
			arr[a][1] = b;
			arr[a][2] = c;
			arr[a][3] = d;
		}

		
		arr[1][3] = arr[1][2] + arr[1][3];
		dp[1][1] = arr[1][1];
		dp[1][2] = arr[1][2];
		dp[1][3] = arr[1][3];


		dp[2][1] = arr[1][2] + arr[2][1];
		dp[2][2] = min({ arr[1][2] + arr[2][2],arr[1][3]+arr[2][2]});
		dp[2][3] = min({ arr[1][2] + arr[2][3],arr[1][3] + arr[2][3] });



		fn(not_0);

		/*for (int a = 1; a <= not_0; a++)
		{
			cout << dp[a][1] << ' ' << dp[a][2] << ' ' << dp[a][3] << ' ';
			cout << endl;
		}*/


		cout << ct << ". " << dp[not_0][2] << '\n';
		cin >> not_0;
		ct++;

	}
}
