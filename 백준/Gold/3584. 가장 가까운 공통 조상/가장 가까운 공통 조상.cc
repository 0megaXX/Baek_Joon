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

int parent[10001];
bool visit[10001];

void clear_fn()
{
	for (int a = 0; a < 10001; a++)
		parent[a] = a;

	memset(visit, false, sizeof(visit));



}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	while (cass--)
	{
		clear_fn();

		int node;
		cin >> node;

		for (int a = 0; a < node - 1; a++)
		{
			int A, B;
			cin >> A >> B;
			parent[B] = A;
		}


		int one, two;
		cin >> one >> two;

		visit[one] = true;
		while (one != parent[one]) // 루트까지 경로 찾기
		{
			one = parent[one];// 올라가기
			visit[one] = true;
		}


		while (true)
		{
			if (visit[two]) // 방문했다는 것은 처음 노드와의 공통 부모라는것
			{
				cout << two<<'\n';
				break;
			}

			two = parent[two]; // 아니라면 올라감
		}
	}
  

}
