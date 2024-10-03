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

#define MAXX 987654321
using namespace std;

int row, col;
vector<string> arr;
bool connect = false;
pair<int, int> swan;
queue<pair<int, int>> Move, Water, tmpMove, tmpWater;
// Move = 이동할곳이 담겨있는 큐 , Water = 물들이 있는 곳이 담겨있는 큐
// tmpMove = 이동한곳이 빙하라 녹을때까지 기다리는 큐, tmpWater = 빙하가 녹아 물이되길 기다리는 큐

int dx[4]{ 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };
bool visit[1501][1501];

void swanBFS() // 빙하에 모든 이동이 막힐 때 까지 거위를 이동시키는 함수
{
	while (!Move.empty()) 
	{
		int x = Move.front().first;
		int y = Move.front().second;

		Move.pop();

		int nx, ny;
		for (int a = 0; a < 4; a++) 
		{
		    nx = x + dx[a];
		    ny = y + dy[a];

			if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visit[nx][ny])
			{
				visit[nx][ny] = true; // 방문처리

				if (arr[nx][ny] == 'X')// 간곳이 빙하라면
					tmpMove.push({ nx,ny }); 

				else if (arr[nx][ny] == '.') // 간곳이 물이라면
					Move.push({ nx,ny });

				else if (arr[nx][ny] == 'L') // 간곳이 백조라면
				{
					connect = true;
					break;
				}
			}
		}
	}
}

void waterBFS() // 물에 붙어있는 빙하를 녹이는 함수
{
	while (!Water.empty())
	{
		int x = Water.front().first;
		int y = Water.front().second;
		Water.pop();

		int nx, ny;
		for (int a = 0; a < 4; a++) 
		{
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && ny >= 0 && nx < row && ny < col) 
			{
				if (arr[nx][ny] == 'X') // 물이 이동할 곳이 빙하라면
				{
					arr[nx][ny] = '.';
					tmpWater.push({ nx,ny });
				}
			}
		}
	}
}

int fn()
{
	int day = 0; // 경과 일

	while (!connect) // 백조가 만날때까지 반복
	{
		swanBFS(); // 백조부터 이동

		if (connect)
			break; // 연결되면 종료

		waterBFS();

		Move = tmpMove; // 빙하였던곳을 녹였기에 이동이 가능
		Water = tmpWater; // 한번씩 녹인 빙하정보를 갱신

		while (!tmpMove.empty()) //초기화
			tmpMove.pop();

		while (!tmpWater.empty()) //초기화
			tmpWater.pop();

		day++;
	}

	return day;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row >> col;
	for (int a = 0; a < row; a++) 
	{
		string s;
		cin >> s;
		arr.push_back(s);
	}

	for (int a = 0; a < row; a++) 
	{
		for (int b = 0; b < col; b++)
		{
			if (arr[a][b] == 'L') // 백조라면
			{
				swan.first = a;
				swan.second = b;
			}
			if (arr[a][b] != 'X') // 빙하가 아니라면 (백조역시 물에 떠있기 때문에 else if 아님)
				Water.push({ a,b }); 
		}
	}
	visit[swan.first][swan.second] = true; // 백조의 위치 방문처리
	Move.push(swan);
	cout << fn() << '\n';
	return 0;
}