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
#define MAXX 987654321
using namespace std;

int sizz;

char arr[5][5];
int dp[5][5];
int dx[2]{ 0,1 };
int dy[2]{ 1,0 };

struct MyStruct
{
	int x, y;
	int accumulate; // 누적
	char me;
};

void max_dfs()
{
	stack<MyStruct>st;
	st.push({ 0,0,arr[0][0]-'0',NULL});
	while (!st.empty())
	{
		int x = st.top().x;
		int y = st.top().y;
		int acc = st.top().accumulate;
		char me= st.top().me;
		st.pop();

		char cur = arr[x][y];




		int nx, ny;
		for (int a = 0; a < 2; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx < sizz && ny < sizz)
			{
				if (me == NULL) // 현재 칸이 수식이 아니였다면 다음 칸은 수식임
				{
					st.push({ nx,ny,acc,arr[nx][ny] });

				}
				else // 현재 칸이 수식이라면 계산 가능
				{
					int sub;
					switch (me)
					{
					case '+': sub = acc + (arr[nx][ny] - '0');
						break;
					case '-' :  sub = acc - (arr[nx][ny] - '0');
						break;
					case '*': sub = acc * (arr[nx][ny] - '0');
						break;
					}

					if (dp[nx][ny]==-MAXX|| sub > dp[nx][ny])
					{
						dp[nx][ny] = sub;
						st.push({ nx,ny,sub,NULL });
					}


				}



			}


		}

	}


}

void min_dfs()
{
	stack<MyStruct>st;
	st.push({ 0,0,arr[0][0] - '0',NULL });
	while (!st.empty())
	{
		int x = st.top().x;
		int y = st.top().y;
		int acc = st.top().accumulate;
		char me = st.top().me;
		st.pop();

		char cur = arr[x][y];




		int nx, ny;
		for (int a = 0; a < 2; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx < sizz && ny < sizz)
			{
				if (me == NULL) // 현재 칸이 수식이 아니였다면 다음 칸은 수식임
				{
					st.push({ nx,ny,acc,arr[nx][ny] });

				}
				else // 현재 칸이 수식이라면 계산 가능
				{
					int sub;
					switch (me)
					{
					case '+': sub = acc + (arr[nx][ny] - '0');
						break;
					case '-':  sub = acc - (arr[nx][ny] - '0');
						break;
					case '*': sub = acc * (arr[nx][ny] - '0');
						break;
					}

					if (dp[nx][ny] == MAXX || sub < dp[nx][ny])
					{
						dp[nx][ny] = sub;
						st.push({ nx,ny,sub,NULL });
					}


				}



			}


		}

	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int a = 0; a < 5; a++)
		for (int b = 0; b < 5; b++)
			dp[a][b] = -MAXX;
	cin >> sizz;

	for (int a = 0; a < sizz; a++)
		for (int b = 0; b < sizz; b++)
			cin >> arr[a][b];

	dp[0][0] = arr[0][0]-'0';

	max_dfs();
	
	/*for (int a = 0; a < sizz; a++)
	{
		for (int b = 0; b < sizz; b++)
			cout << dp[a][b] << ' ';
		cout << endl;
	}*/


	cout << dp[sizz - 1][sizz - 1] << ' ';



	for (int a = 0; a < 5; a++)
		for (int b = 0; b < 5; b++)
			dp[a][b] = MAXX;

	dp[0][0] = arr[0][0] - '0';

	min_dfs();

	/*for (int a = 0; a < sizz; a++)
	{
		for (int b = 0; b < sizz; b++)
			cout << dp[a][b] << ' ';
		cout << endl;
	}*/


	cout << dp[sizz - 1][sizz - 1];
}