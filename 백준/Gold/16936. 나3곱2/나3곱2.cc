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

vector<unsigned long long> v;
bool visited[101];
int n;

void Solve(unsigned long long start)
{

    vector<unsigned long long> ans;
    ans.push_back(start);

    for (int a = 1; a < n; a++) 
        for (int b = 0; b < n; b++) 
        {
            if (v[b] * 3 == ans.back()) // 배열 맨 끝이 3으로 나눠지고 3으로 나눌때 현재 위치의 값이라면
                ans.push_back(v[b]);
            
            else if (v[b] == ans.back() * 2) //배열 맨끝의 값 * 2가 현재 위치의 값이라면
                ans.push_back(v[b]);
            
        }


    if (ans.size() == n) // 조합이 완성되었다면
    {
        for (int a = 0; a < n; a++)
            cout << ans[a] << " ";
        exit(0);
    }

    else
        return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
   
    for (int a = 0; a < n; a++)
    {
        unsigned long long b;
        cin >> b;
        v.push_back(b);
    }

    sort(v.begin(), v.end());
    for (int a = 0; a < n; a++) 
        Solve(v[a]);
}