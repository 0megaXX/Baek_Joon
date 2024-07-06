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
#define MAXX 987654321
using namespace std;


int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };;

struct Node {
    int cost;
    int x;
    int y;
};


struct Compare {
    bool operator()(const Node& a, const Node& b) {
        if (a.cost != b.cost) return a.cost > b.cost;
     
        return false; 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sizz;
    cin >> sizz;
    vector<vector<int>> grid(sizz, vector<int>(sizz));
    vector<vector<int>> cost(sizz, vector<int>(sizz, MAXX));
    for (int a = 0; a < sizz; a++) {
        string s;
        cin >> s;
        for (int b = 0; b < sizz; b++) 
            grid[a][b] = s[b] - '0';
        
    }

    priority_queue<Node, vector<Node>, Compare> pq;
    pq.push({ 0, 0, 0 }); // cost, x, y
    cost[0][0] = 0;

    
    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();
        int currentCost = top.cost;
        int x = top.x;
        int y = top.y;

        if (x == sizz - 1 && y == sizz - 1)
            break;

        int nx, ny;
        for (int a = 0; a < 4; a++) 
        {
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && ny >= 0 && nx < sizz && ny < sizz)
            {
                int nextCost = currentCost + (grid[nx][ny] == 0);

                if (cost[nx][ny] > nextCost)
                {
                    cost[nx][ny] = nextCost;
                    pq.push({ nextCost, nx, ny });
                }
            }
        }
    }

    cout << cost[sizz - 1][sizz - 1] << '\n';
}