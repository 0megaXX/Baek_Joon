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

using namespace std;
#define MAXX 99999999

map<string, int>public_1;
map<int,int>public_2;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    while(n--)
        {
            int len;
            cin>>len;

            for(int a=0;a<len;a++)
                {
                    string s;
                    cin>>s;
                    public_1[s]=a;
                    
                }

            vector<int>v_1(len);
            for(int a=0;a<len;a++)
                {
                    string s;
                    cin>>s;
                   // public_2[public_1[s]]=a; // 기존 암호의 순서를 2의 순서에 매핑 punlic_2[@] 의 뜻은 기존조
                   // public_2[a]=public_1[s];
                    v_1[public_1[s]]=a;
                    
                }

            vector<string>v(len);
            for(int a=0;a<len;a++)
                {
                    cin>>v[a];
   
                }
             for(int a=0;a<len;a++)
                 {
                     int next = v_1[a];
                     cout<<v[next]<<' ';
                 }
            cout<<'\n';
        }
    

}