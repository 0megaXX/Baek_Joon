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
int N, K;

vector<long long> v(1000001);
vector<long long> tree(3000001);

// 구간 트리 = 온도의 갯수 누적

// 구간 트리 초기화
void init(int node, int start, int end, int temperature, int ct)
{
    if (start == end) 
    {tree[node] +=ct;
     return;
    }
    int mid = (start + end) / 2;
    
    if(mid>= temperature) // 현재 온도에 대한 이분탐색
        init(node*2, start, mid, temperature, ct); // 좌 탐색
    else 
        init(node*2+1, mid+1, end, temperature, ct); // 우 탐색

    tree[node]=tree[node*2] + tree[node*2+1];
}

// 구간 트리에서 쿼리
long long query(int node, int start, int end, int ran)
{
     if (start == end) 
        return start;
    
    int mid = (start + end) / 2;
    
    if(tree[node*2]>= ran) // 현재 온도에 대한 이분탐색
        return query(node*2, start, mid, ran); // 좌 탐색
    else 
        return query(node*2+1, mid+1, end, ran - tree[node*2]); // 우 탐색
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >>K;

    for (int a = 0; a < N; a++) 
             cin >> v[a];


    for (int a=0;a<(K-1) ; a++) // 온도를 재기 전 구간트리 구축
             init(1,0,65535,v[a],1); // 65535는 문제에서 주어진 원소의 최대 값
        


    long long summ=0;
    int sub = 0;
    for (int a = K-1; a < N; a++)
    {
        
       init(1, 0, 65535,v[a], 1);
       summ+=query(1,0,65535,(K+1)/2);
       init(1, 0, 65535,v[sub], -1); // 슬라이딩 윈도우
        sub++;

    }
    cout<<summ;

    return 0;
}