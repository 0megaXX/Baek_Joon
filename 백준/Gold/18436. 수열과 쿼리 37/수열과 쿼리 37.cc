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

vector<int > v(1000002);
vector<int>tree(3000001); // 짝수의 수를 저장할거임

// 구간 트리 초기화
int init(int node, int start, int end)
{

    if (start == end) // 단말노드까지 간다면
        return tree[node] = v[start]%2 == 0 ? 1 : 0; // 짝수면 1 저장 아니면 0임


    int mid = (start + end) / 2;
    int l = init(node * 2, start, mid);
    int r = init(node * 2 + 1, mid + 1, end);


    return tree[node] = l+r;

}

// 구간 트리에서 짝수의 수를 리턴하는 쿼리
int query(int node, int start, int end, int left, int right)
{

    if (right<start || left > end) // 범위밖이라면
        return 0;

    if (left <= start && right >= end) // 완전 범위 내라면
        return tree[node];

    int mid = (start + end) / 2;
    int l = query(node * 2, start, mid, left, right);
    int r = query(node * 2 + 1, mid + 1, end, left, right);



    return l+r;



}


// 세그먼트 트리 재구축
int re_init(int node, int start, int end, int target)
{

    if (start == end)
        return tree[node] = v[start] % 2 == 0 ? 1 : 0; // 짝수면 1 저장 아니면 0임


    int mid = (start + end) / 2;



    if (target <= mid) // 중간보다 왼쪽에 존재한다면
    {
        int l = re_init(node * 2, start, mid, target);
        return tree[node] =l + tree[node * 2 + 1];
    }
    else // 중간보다  오른쪽에 존재한다면
    {
        int r = re_init(node * 2 + 1, mid + 1, end, target);
        return tree[node] = tree[node * 2] + r;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    v[0] = MAXX;
    for (int a = 1; a <= N; a++)
        cin >> v[a];


    init(1, 1, N);


    int M;
    cin >> M;
    while (M--)
    {
        int type;
        cin >> type;

        int a, b;
        cin >> a >> b;

        if (type == 1) // 변환
        {
            
            v[a] = b;
            re_init(1, 1, N, a);
        }

        else if (type == 2) // 짝수 출력

            cout << query(1, 1, N, a, b)<< '\n';

        else // 홀수 출력
            cout << (b-a+1) - query(1, 1, N, a, b) << '\n';

    }

    return 0;
}