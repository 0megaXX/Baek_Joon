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

int parent[1000001];


int find_parent(int a)
{

    if (a == parent[a])
        return a;
    else
        return  parent[a]=find_parent(parent[a]);


}

void union_parent(int a, int b)
{

    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node, edge;
    cin >> node >> edge;

    for (int a = 1; a <= node; a++)
        parent[a] = a;

    for (int a = 1; a <= edge; a++)
    {

        int cass,b,c;
        cin >> cass>>b>>c;
            int b_p = find_parent(b);
            int c_p = find_parent(c);

        if (cass == 0) // 0은 연결
        {

           
            if (b_p != c_p) // 만약 연결되지 않았다면
                union_parent(b_p, c_p);
         
        }
        else // 1은 확인
        {


            if (b_p == c_p) // 연결되어있다면
                cout << "YES\n";
            else
                cout << "NO\n";

        }

    }

}
