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


struct INFO {
	int S, E, C;
};

vector<INFO> Edge;
int Parent[250010];

int Find(int a)
{
	if (Parent[a] == a) 
		return a;
	return Parent[a] = Find(Parent[a]);
}

void Union(int X, int Y)
{
	int PX = Find(X);
	int PY = Find(Y);
	if (PX < PY) 
		Parent[PY] = PX;
	else 
		Parent[PX] = PY;
	
}

bool Comp(INFO A, INFO B) 
{
	return (A.C < B.C);
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int T, R, C;
    
    cin >> T;
	while (T--)
    {
		cin >> R >> C;

        // 초기화 
    	for (int a = 0; a < (R * C); a++) 
    		Parent[a] = a;
	
    	Edge.clear();
    	int ans = 0;

        // 가로 관계 비용 저장
		for (int a = 0; a < R; a++)
        {
			for (int b = 0; b < C - 1; b++) 
            {
				int Cs;
				cin >> Cs;
				int S = (a * C) + b;
				int E = (a * C) + b + 1;
				Edge.push_back({ S,E,Cs });
			}
		}

        // 세로 관계 비용 저장
		for (int a = 0; a < (R - 1); a++) 
        {
			for (int b = 0; b < C; b++) 
            {
				int Cs;
				cin >> Cs;
				int S = (a * C) + b;
				int E = (a + 1) * C + b;
				Edge.push_back({ S,E,Cs });
			}
		}
		sort(Edge.begin(), Edge.end(), Comp);
        
    	for (int a = 0; a < Edge.size(); a++) // 연결되지 않은 최소 비용들 우선으로 연결
        {
    		int S = Edge[a].S;
    		int E = Edge[a].E;
    		int Cs = Edge[a].C;
            
    		if (Find(S) != Find(E))
            {
    			Union(S, E);
    			ans += Cs;
    		}
    	}
        
		cout<< ans<<'\n';
	};

    
    
}