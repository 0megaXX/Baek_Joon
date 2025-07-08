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
#include <regex>

using namespace std;
#define MAXX 2147483647

int parent[100001];
long long parentSize[100001];

vector<pair<pair<int, int>, int>> edge;

int find_parent(int a)
{
    if(a == parent[a])
        return a;
    else
        return parent[a] = find_parent(parent[a]);
}

void union_parent(int num1, int num2)
{
    parent[num2] = num1;
    parentSize[num1] += parentSize[num2];
    parentSize[num2] = 1;
}

// edge 값 기준 정렬
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.second > b.second)
        return true;
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int a = 0; a <= N;a++)
    {
         parent[a]= a;
         parentSize[a]= 1;
    }

    long long total_cost=0;
    
    for (int a = 0; a < M;a++)
    {
         int num1, num2, cost;
         cin>> num1 >> num2 >> cost;

         edge.push_back({{num1, num2}, cost });
         total_cost+= cost;
    }

    sort(edge.begin(),edge.end(), cmp); // 가격 내림차순 정렬

    long long rs = 0;

    for (int a = 0; a <edge.size(); a++)
    {
         int curNum1 = find_parent(edge[a].first.first);
         int curNum2 = find_parent(edge[a].first.second);
         int cost = edge[a].second;
        
         // 연결되지 않았다면
         if (curNum1 !=curNum2)
         {
              rs += (( (parentSize[curNum1] * parentSize[curNum2]) % 1000000000) * total_cost) % 1000000000;
              rs %= 1000000000;
              union_parent(curNum1,curNum2);
         }
         total_cost-= cost;
    }

    cout << rs;

    return 0;
}

