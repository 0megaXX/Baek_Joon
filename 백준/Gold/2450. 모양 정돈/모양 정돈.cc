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



int arr[100001];
int arr2[100001];
int ans = 200002;
int ct[4];
int order[4];
bool check[4];
int n;

int fn()
{
    int k = 0;
    int pos[4][4] = { {0} };
    int ct1 = 0;
    int ct2 = 0;
   
    for (int a = 1; a <= 3; a++)
        for (int b = 0; b < ct[order[a]]; b++)
            arr2[k++] = order[a];
 
    for (int a = 0; a < n; a++)
        pos[arr2[a]][arr[a]]++;
   
    for (int a = 1; a < 3; a++)
    {
        for (int b = a + 1; b <= 3; b++)
        {
            k = min(pos[a][b], pos[b][a]);
            ct1 += k;
            ct2 += pos[a][b] + pos[b][a] - (k * 2);
        }
    }
   
    return ct1 + ct2 / 3 * 2;
}

 
void DFS(int tp)
{
    if (tp > 3)
    {
        ans = min(ans, fn());
        return;
    }
   
    for (int a = 1; a <= 3; a++)
    {
        if (check[a]) // 방문처리 돼있다면 퍄스
            continue;
       
        check[a] = 1;
        order[tp] = a;
        DFS(tp + 1);
        check[a] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for (int a=0; a<n; a++ )
    {
        int b;
        cin>>b;
        arr[a]=b;
        ct[b]++;
    }

    DFS(1);

    cout<<ans;

}