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
using namespace std;




char arr[500][500];
int visit[500][500]{ 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col;
	cin >> row >> col;



	cin.ignore();

	for (int a = 0; a < row; a++)
	{
		string s;
		getline(cin, s);

		for (int b = 0; b < s.length(); b++)
			arr[a][b] = s[b];
	}


	/*for (int a = 0; a < row; a++)
	{

		for (int b = 0; b < col; b++)
			cout << arr[a][b];
		cout << endl;
	}*/

	int ct = 0;

	//방문 0이면 미방문, 1이면 여기를 방문하면 탈출가능, 2면 밟으면 무한루프
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
		{

			
			if (visit[a][b] == 0)
			{
				stack<pair<int, int>>st;
				stack<pair<int, int>>st2;

				st.push({ a,b });
				st2.push({ a,b });
				while (!st.empty())
				{
					int rrow = st.top().first;
					int ccol = st.top().second;
					st.pop();

					if (visit[rrow][ccol] == 0)
					{
						if (arr[rrow][ccol] == 'R')
						{
							if (ccol + 1 == col)
							{
								ct++;
								while (!st2.empty())
								{
									int rrow = st2.top().first;
									int ccol = st2.top().second;
									st2.pop();
									visit[rrow][ccol] = 1;
								}
								break;
							}
							else
							{
								visit[rrow][ccol] = 2;
								st.push({ rrow,ccol + 1 });
								st2.push({ rrow,ccol + 1 });
							}
						}

						else if (arr[rrow][ccol] == 'L')
						{
							if (ccol - 1 == -1)
							{
								ct++;
								while (!st2.empty())
								{
									int rrow = st2.top().first;
									int ccol = st2.top().second;
									st2.pop();
									visit[rrow][ccol] = 1;
								}
								break;
							}
							else
							{
								visit[rrow][ccol] = 2;
								st.push({ rrow,ccol - 1 });
								st2.push({ rrow,ccol - 1 });
							}
						}
						else if (arr[rrow][ccol] == 'U')
						{
							if (rrow - 1 == -1)
							{
								ct++;
								while (!st2.empty())
								{
									int rrow = st2.top().first;
									int ccol = st2.top().second;
									st2.pop();
									visit[rrow][ccol] = 1;
								}
								break;
							}
							else
							{
								visit[rrow][ccol] = 2;
								st.push({ rrow - 1,ccol });
								st2.push({ rrow - 1,ccol });
							}
						}
						else if (arr[rrow][ccol] == 'D')
						{
							if (rrow + 1 == row)
							{
								ct++;
								while (!st2.empty())
								{
									int rrow = st2.top().first;
									int ccol = st2.top().second;
									st2.pop();
									visit[rrow][ccol] = 1;
								}
								break;
							}
							else
							{
								visit[rrow][ccol] = 2;
								st.push({ rrow + 1,ccol });
								st2.push({ rrow + 1,ccol });
							}
						}
					}

					else if (visit[rrow][ccol] == 1)
					{
						while (!st2.empty())
						{
							int rrow = st2.top().first;
							int ccol = st2.top().second;
							st2.pop();
							visit[rrow][ccol] = 1;
						}
						ct++;

					}
					else
						break;



				}





			}
			else if (visit[a][b] == 1)
				ct++;
			else
				continue;





		}
	}



	cout << ct;


}
