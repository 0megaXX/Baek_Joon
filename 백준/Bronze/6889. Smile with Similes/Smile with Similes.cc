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
#include <numeric>
using namespace std;

vector<string>adjectives;
vector<string>nouns;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for (int a=0;a<n ;a++ ) // 형용사 삽입
        {
            string s;
            cin>>s;
            adjectives.push_back(s);
        
        }

    for (int a=0;a<m ;a++ ) // 명사 삽입
        {
            string s;
            cin>>s;
            nouns.push_back(s);
        
        } 


  for (int a=0;a<n ;a++ )
      for (int b=0;b<m ;b++ )
          cout<<adjectives[a]<<" as "<<nouns[b]<<'\n';
}