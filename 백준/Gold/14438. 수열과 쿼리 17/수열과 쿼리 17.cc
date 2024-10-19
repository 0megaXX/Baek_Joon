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

#define MAXX 1000000005
using namespace std;
int N, Q;

vector<long long > v(1000002);
vector<long long>tree(3000001);

// 구간 트리 초기화
long long init(int node, int start, int end)
{
    
    if (start == end) // 단말노드까지 간다면
        return tree[node] = v[start];

    int mid = (start + end) / 2;

    long long l = init(node * 2, start, mid);
    long long r = init(node * 2 + 1, mid + 1, end);


    return tree[node] = min(l,r);

}




// 구간 트리에서 쿼리
long long query(int node, int start, int end, int left, int right)
{
    
    if (right<start || left > end) // 범위밖이라면
        return MAXX;

    if (left <= start && right >= end) // 완전 범위 내라면
        return tree[node];

    int mid = (start + end) / 2;
    long long l = query(node * 2, start,mid,left, right);
    long long r = query(node * 2 + 1, mid+1, end, left, right);



    return min(l, r);



}


// 세그먼트 트리 재구축
long long re_init(int node, int start, int end, int target)
{

    if (start == end)
        return tree[node]=v[start];


    int mid = (start + end) / 2;



    if (target <= mid) // 중간보다 왼쪽에 존재한다면
    {
        long long l = re_init(node * 2, start, mid, target);
        return tree[node] = min(l,tree[node * 2 + 1]);
    }
    else // 중간보다  오른쪽에 존재한다면
    {
        long long r = re_init(node * 2 + 1, mid + 1, end, target);
        return tree[node] = min(tree[node*2], r);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int a = 0; a < N; a++)
        cin >> v[a];


    init(1, 0, N-1);


    int M;
    cin >> M;
    while (M--)
    {
        int type;
        cin >> type;
        
        int a, b;
        if (type == 1) // 변환
        { 
            cin >> a >> b;
            v[a-1] = b;
            re_init(1, 0, N-1 , a-1);
        }

        else // 출력
        {
            cin >> a >> b;
            cout << query(1, 0, N-1, a-1, b-1)<<'\n';
        }
    }
    
    return 0;
}