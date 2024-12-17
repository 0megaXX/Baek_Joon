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

#define MAXX 1000001
using namespace std;

vector<long long> tree(4000001);  // 세그먼트 트리
vector<long long> v(1000001);  // 각 사탕의 개수를 저장하는 배열
int len = 1000000;  // 사탕의 최대 종류 수 (1부터 시작)

// 구간 트리에서 target번째 작은 값을 찾는 쿼리
long long query(int node, int start, int end, int target)
{
    if (start == end) {
        return start;  // 리프 노드에서 해당 사탕 종류 반환
    }

    int mid = (start + end) / 2;

    if (tree[node * 2] >= target)  // 왼쪽 서브트리가 target번째 사탕을 포함하는 구간이라면
        return query(node * 2, start, mid, target);  // 왼쪽 서브트리로 내려감
        
    else
        return query(node * 2 + 1, mid + 1, end, target - tree[node * 2]);  // 오른쪽 서브트리로 내려감
}

// 세그먼트 트리 재구축
void update(int node, int start, int end, int idx, int diff)
{
    if (start == end) {
        tree[node] += diff;  // 해당 사탕의 개수를 갱신
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(node * 2, start, mid, idx, diff);  // 왼쪽 자식으로
        else
            update(node * 2 + 1, mid + 1, end, idx, diff);  // 오른쪽 자식으로

        tree[node] = tree[node * 2] + tree[node * 2 + 1];  // 트리 갱신
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;  

    while (cass--)
    {
        int A, B, C;
        cin >> A;

        if(A==1) // 사탕을 꺼내는 경우
        { 
                cin >> B;

                // query(1, 1, len, B)에서 B번째 사탕 종류를 찾음
                int candy_type = query(1, 1, len, B);
                cout << candy_type << '\n';

                // 해당 사탕을 꺼냈으므로 개수를 1 감소시킴
                update(1, 1, len, candy_type, -1);
        }

        else  // 사탕을 넣는 경우
        {
            cin >> B >> C;
                // B번 사탕을 C개 만큼 추가
                update(1, 1, len, B, C);
        }     

        
     }
   

    return 0;
}