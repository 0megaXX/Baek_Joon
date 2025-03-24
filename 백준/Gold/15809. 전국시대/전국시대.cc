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
#include <unordered_map>


using namespace std;

int parent[100001];
long long population[100001];  // 각 국가의 병력
bool is_alive[100001];  // 살아있는 국가인지 여부

// 부모를 찾는 함수
int find_parent(int x) 
{
    if (parent[x] != x) 
        parent[x] = find_parent(parent[x]);  // 부모 갱신 (경로 압축)
    
    return parent[x];
}

// 두 군단을 합치는 함수 (유니온)
void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    
    if (a != b)
    {
        if (population[a] < population[b])
        {
            parent[a] = b;
            population[b] += population[a];  // 군단 b에 군단 a의 병력을 합침
        } 
        
        else
        {
            parent[b] = a;
            population[a] += population[b];  // 군단 a에 군단 b의 병력을 합침
        }
    }
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	int N, M;
    cin >> N >> M;

    // 국가 초기화
    for (int a = 1; a <= N; a++)
    {
        parent[a] = a;
        cin >> population[a];
        is_alive[a] = true;  // 처음에는 모든 국가가 살아있음
    }

    
    for (int i = 0; i < M; i++) 
    {
        int O, P, Q;
        cin >> O >> P >> Q;

        int rootP = find_parent(P);
        int rootQ = find_parent(Q);

        if (O == 1) // 동맹
        { 
           union_parent(P, Q);       
        } 
        
        else if (O == 2) // 전쟁
        {  
            if (!is_alive[rootP] || !is_alive[rootQ]) 
                continue;  // 이미 멸망한 국가끼리는 전쟁 불가

            if (population[rootP] > population[rootQ])
            {
                population[rootP] -= population[rootQ];  // P가 승리
                population[rootQ]=0;
                 union_parent(rootP, rootQ);
            }
            else if (population[rootP] < population[rootQ])
            {
                population[rootQ] -= population[rootP];  // Q가 승리
                population[rootP]=0;
                union_parent(rootP, rootQ);
            } 
            else 
            {
                is_alive[rootP] = false;  // P는 멸망
                is_alive[rootQ] = false;  // Q도 멸망
                population[rootQ]=0;
                population[rootP]=0;
            }
            
        }
    }

     // 남아있는 국가의 병력 출력
    vector<long long>v;
    for (int a = 1; a <= N; a++) 
        if (is_alive[find_parent(a)])  // 살아있는 국가만
        {  
            is_alive[find_parent(a)]=false;
            v.push_back(population[find_parent(a)]);
            
        }

    sort(v.begin(),v.end());
    cout <<v.size() << '\n';
    for (int a=0; a<v.size();a++) 
        cout << v[a] << " ";
    


    return 0;
}