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
#include <chrono>
#include <tuple>

using namespace std;
#define MAXX 2147483647

int arr[201][201];
int parents[201];
vector<pair<int, pair<int, int>>> roads;
vector<pair<int, int>> useds;

int find_parent(int x)
{
    if (x == parents[x])
        return x;
    

    return parents[x] = find_parent(parents[x]);
}

void union_parent(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if (x == y)
        return;

    else if (x > y)
        swap(x, y);
    

    parents[y] = x;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int N, cost=0;
    cin >> N;

    for (int a = 1; a <= N; a++)
    {
        parents[a] = a;

        for (int b = 1; b <= N; b++)
            cin >> arr[a][b];
        
    }

    for (int a = 1; a <= N; a++)
    {
        for (int b = a + 1; b <= N; b++)
        {
            if (arr[a][b] < 0) // 이미 설치됨
            {
                union_parent(a, b);
                cost += (-arr[a][b]);
            }
            else
                roads.push_back({arr[a][b], {a, b}});
            
        }
    }

    sort(roads.begin(), roads.end());

    for (auto roadInfo : roads)
    {
        pair<int, int> road = roadInfo.second;

        if (find_parent(road.first) == find_parent(road.second))
            continue;

        union_parent(road.first, road.second);
        cost += roadInfo.first;
        useds.push_back(road);
    }

    cout << cost << " " << useds.size() << "\n";

    for (auto usedRoad : useds)
        cout << usedRoad.first << " " << usedRoad.second << "\n";
    
    return 0;
}