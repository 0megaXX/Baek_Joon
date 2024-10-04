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

vector<pair<double, double>> pos;
vector<pair<double, pair<double, double>>> edge;
int parent[101];

int find_parent(int x) 
{
	if (parent[x] == x)
        return x;

	return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int same_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a == b)
        return 1;

	else
        return 0;
}


int main() {
	ios_base::sync_with_stdio(false);

    double ans = 0;
    int n;
    cin >> n;

    for (int a = 0; a < n; a++)
    {
        double x, y;
        cin >> x >> y;
        pos.push_back({ x, y });
    }

    for (int a = 0; a < pos.size(); a++) 
    {
        double x_a = pos[a].first;
        double y_a = pos[a].second;

        for (int b = a + 1; b < pos.size(); b++)
        {
            double x_b = pos[b].first;
            double y_b = pos[b].second;

            double dist = sqrt(pow((x_b - x_a), 2) + pow((y_b - y_a), 2));
            //피타고라스를 이용한 거리 차이
            edge.push_back({ dist, {a + 1, b + 1} });
        }
    }

    sort(edge.begin(), edge.end());

    for (int a = 1; a <= n; a++) 
        parent[a] = a;

    for (int a = 0; a < edge.size(); a++)
    {

        double dist = edge[a].first;
        int first = edge[a].second.first;
        int second = edge[a].second.second;
       

        if (same_parent(first, second)) // 이미 연결되었다면
            continue;

        union_parent(first, second); // 아니면 연결

        ans += dist; // 거리추가
    }

    cout << ans;

    return 0;
}