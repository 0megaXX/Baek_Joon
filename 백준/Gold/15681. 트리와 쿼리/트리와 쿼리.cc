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
#define RED 1
#define BLUE 2
using namespace std;


int N, R, Q;


vector<int>v[100001]; // 관계
bool visit[100001]; // 방문배열
int sub_node[100001]; // 해당 n의 루트의 트리에 대한 노드의 갯수

int DFS(int root)
{
    

    if (sub_node[root]) // 이미 현재노드의 서브노드의 수를 안다면 탐색없이 반환
        return sub_node[root];

    visit[root] = true; // 방문처리
    int next;
    int ct = 1;

    for (int a = 0; a < v[root].size(); a++)
    {
        next = v[root][a];

        if (!visit[next]) // 트리니 부모 노드가 아니라면 DFS 실행
            ct += DFS(next); // 
        
        


    }

    return sub_node[root] = ct;

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    memset(visit, 0, sizeof(visit));
    memset(sub_node, 0, sizeof(sub_node));


    cin >> N >> R >> Q;

    for (int a = 0; a < N - 1; a++)
    {
        int b, c;
        cin >> b >> c;
        v[b].push_back(c);
        v[c].push_back(b);
    }

    DFS(R); // 루트로서 DFS를 한번 실행해야 R을 루트로한 트리가 구현됨.


    for (int a = 0; a < Q; a++)
    {

        int b;
        cin >> b;
        cout << DFS(b) << '\n';

    }


  /*  cout << "--------------\n";

    for (int a = 0; a <= N; a++)
        cout << sub_node[a] << ' ';*/
}
