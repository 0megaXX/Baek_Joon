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

vector<int> v(100002);
vector<int> tree(300001);

// 세그먼트 트리 구축
int init(int node, int start, int end) 
{
    if (start == end)
    {
        // 양수, 음수, 0만 알면됨

        if (v[start] > 0)  
            return tree[node] = 1;

        else if (v[start] < 0)
            return tree[node] = -1;

        else
            return tree[node] = 0;
    }
    int mid = (start + end) / 2;
    int l = init(node * 2, start, mid);
    int r = init(node * 2 + 1, mid + 1, end);

    return tree[node] = l * r;
}


int query(int node, int start, int end, int left, int right) {
    
    if (right < start || left > end)  // 범위를 벗어나면 영향을 주면 안됨
        return 1;

    if (left <= start && right >= end )
        return tree[node];

    int mid = (start + end) / 2;
    int l = query(node * 2, start, mid, left, right);
    int r = query(node * 2 + 1, mid + 1, end, left, right);
    return l * r;
}


// 세그먼트 트리 재구축
long long re_init(int node, int start, int end, int target) {
    
    if (start == end) 
    {
        // 양수, 음수, 0만 알면됨
        if (v[start] > 0)
            return tree[node] = 1;
        else if (v[start] < 0)
            return tree[node] = -1;
        else 
            return tree[node] = 0;
    }
    int mid = (start + end) / 2;

    if (target <= mid)
        re_init(node * 2, start, mid, target);

    else 
        re_init(node * 2 + 1, mid + 1, end, target);

    return tree[node] = tree[node * 2] * tree[node * 2 + 1];
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    while (cin >> n >> k)
    {
        string s = "";


        for (int a = 0; a < n; a++)
            cin >> v[a];


        init(1, 0, n - 1);

        for (int a = 0; a < k; a++)
        {
            char commend;
            cin >> commend;

            int b, c;
            cin >> b >> c;

            if (commend == 'C') // 변경명령
            {
                v[b - 1] = c;
                re_init(1, 0, n - 1, b - 1);
            }

            else // 출력명령
            { 
                long long rs = query(1, 0, n - 1, b - 1, c - 1);

                if (rs > 0)//양수인 경우
                    s += '+';
                else if (rs < 0) //음수인 경우
                    s += '-';
                else // 0인경우
                    s += '0';


            }



        }

        cout << s << '\n';



    }
    return 0;
}