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

using namespace std;
#define MAXX 2147483647


int n, m;
string arr[502];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int a = 0; a < n; a++) 
        cin >> arr[a];
    
    queue<pair<int, int> > q;
    for (int a = 0; a < n; a++) 
        for (int b = 0; b < m; b++) 
            if (arr[a][b] == 'W') 
                q.push(make_pair(a, b));
            
        
    

    bool check = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int a = 0; a < 4; a++)
        {
            int nx = x + dx[a];
            int ny = y + dy[a];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue;
            if (arr[nx][ny] == 'S') 
            {
                check = false;
                break;
            }
            if (arr[nx][ny] == '.') 
                arr[nx][ny] = 'D';
            

        }

    }
    if (!check) 
    {
        cout << 0 << "\n";
        return 0;
    }
    else 
    {
        cout << 1 << "\n";
        for (int a = 0; a < n; a++)
        
            cout << arr[a] << "\n";
        
        return 0;
    }
    return 0;
}

