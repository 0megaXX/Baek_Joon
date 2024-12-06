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

map<string,string>m; // 접두사, 원본
map<string,int>m2; // 원본, 순서

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin>>cass;

    string rs1,rs2;
     int len = 0;
    int ct=1;
    while(cass--)
        {
           
            string s;
            cin>>s;
            if(m2[s]==0 ) // 처음 등장한다면
            {
                m2[s]=ct;
                ct++;
            }
            else
                continue;
            
            string tmp="";
            for(int a=0;a<s.length();a++)
                {
                    tmp+=s[a];
                    if(m.find(tmp)==m.end()) // 현재와 같은 접두사가 없다면ㅑ
                        m[tmp]=s;
                    else // 현재 접두사와 같은 접두사를 가진 단어가 있다면
                    {
                        if(tmp.length()>len) // 현 접두사의 길이가 기존 '최장 접두사' 길이보다 길다면 '최장 접두사' 갱신.
                        {
                            len = tmp.length();
                           
                            rs1=m[tmp];
                            rs2= s;

                            // cout<<"갱신 길이 : "<<len<<" : "<<rs1<<' '<<rs2<<endl;
                        }     
                        if(tmp.length() == len) // 길이가 같다면
                        {
                            if(m2[rs1]>m2[m[tmp]]) // 기존게 더 작다면조
                            {
                                 len = tmp.length();
                           
                            rs1=m[tmp];
                            rs2= s;
                            }
                            
                        }
                    }
                }
        }

        cout<<rs1<<'\n';
        cout<<rs2;
}