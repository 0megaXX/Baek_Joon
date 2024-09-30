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


struct nutrient
{
    int protin = 0;
    int province = 0;
    int carbohydrate = 0;
    int vitamin = 0;
    int price=0;


}; // 영양소 구조체

nutrient Max_n; // 최소 요건

vector < nutrient>v; // 영양소 배열

bool visit[18]; // 방문배열

int cass;
int min_price=MAXX; // 최소가격
vector<int>min_mem; // 최소가격의 맴버들
void back(int start)
{
    nutrient cur; // 현재 조합의 영양소들의 합
    for (int a = 0; a < cass; a++)
    {

        if (visit[a]) // 현재 만드는 조합은 모두 방문처리되어있음
        {
            cur.protin += v[a].protin;
            cur.province += v[a].province;
            cur.carbohydrate += v[a].carbohydrate;
            cur.vitamin += v[a].vitamin;
            cur.price += v[a].price;
        }

    }

    if (cur.protin >= Max_n.protin && cur.province >= Max_n.province &&
        cur.carbohydrate >= Max_n.carbohydrate && cur.vitamin >= Max_n.vitamin)
        // 최소 요건을 충족한다면
    {
        if (cur.price < min_price) // 최소가격을 갱신하였다면
        {
            min_mem.clear();

            for (int a = 0; a < cass; a++)
                if (visit[a]) // 현재 조합을 전부 삽입
                    min_mem.push_back(a);


            min_price = cur.price;

        }

    }

    for (int a = start; a < cass; a++)
    {

        if (!visit[a]) // 이 조합을 한 적이 없다면
        {
            visit[a] = true; // 방문처리
            back(a + 1); // 백트래킹
            visit[a] = false; // 방문해제
        }


    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> cass;
    v.resize(cass);
    memset(visit, false, sizeof(visit));
    cin >> Max_n.protin >> Max_n.province >> Max_n.carbohydrate >> Max_n.vitamin;
    // 최소 요구 영양소
   

    for (int a = 0; a < cass; a++)
    {
        cin >> v[a].protin >> v[a].province >> v[a].carbohydrate >> v[a].vitamin
            >> v[a].price;
        
    }
  
    back(0);
    if (min_price == MAXX) // 조합이 없다면
    {
        cout << -1;
        return 0;
    }
    cout << min_price<<'\n';

    
    for (int a = 0; a < min_mem.size(); a++)
        cout << min_mem[a]+1 << ' ';
}
