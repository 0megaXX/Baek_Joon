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

#define MAXX 1000000000
using namespace std;
int N, M, K;

vector<long long> v(1000001);
vector<long long> tree(3000001);

// 구간 트리 초기화
long long init(int node, int start, int end)
{
    if (start == end) 
        return tree[node] =v[start];
    
    int mid = (start + end) / 2;
    long long left = init(2 * node, start, mid);
    long long right = init(2 * node + 1, mid + 1, end);

    return tree[node] =  left+right ;
}

// 구간 트리에서 쿼리
long long query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
        return 0 ; // 범위 밖

    if (left <= start && end <= right) 
        return tree[node]; // 범위 안

    int mid = (start + end) / 2;
    long long l = query(2 * node, start, mid, left, right);
    long long r = query(2 * node + 1, mid + 1, end, left, right);

    return l+r ;
}


// 세그먼트 트리 재구축
long long re_init(int node, int start, int end, int target)
{


    if (start == end) // 도착했다면
        return tree[node]=v[target];

    int mid = (start + end) / 2;

    if (target > mid) // 찾는 위치가 중앙보다 크다면
        return tree[node] = tree[node * 2]+re_init(node * 2 + 1, mid + 1, end, target);

    else
        return tree[node] = re_init(node * 2, start,mid, target) + tree[node * 2+1];


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M>>K;

    for (int a = 0; a < N; a++) 
        cin >> v[a];
    

    // 구간 트리 초기화
    init(1, 0, N - 1);
    

    for (int a = 0; a < M + K; a++)
    {
        
        int cass;
        cin >> cass;
        
        int b;
        long long c;
        cin >> b >> c;
     

        if (cass == 1)// 1인경우는 변경임
        {       
            v[b-1] = c;
            re_init(1, 0, N - 1, b - 1);
        }
        else // 2인 경우 탐색임
            cout << query(1, 0, N - 1, b-1, c-1) << '\n';


    }

    return 0;
}