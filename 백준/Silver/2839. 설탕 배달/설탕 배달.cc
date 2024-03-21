#include <iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main(void)
{
    int n;
    int count = 0;

    cin>>n;

   

    if ((n % 5) == -0)
    {
        cout << n / 5;
    }
    else if ((n % 5) % 3 == 0)
    {
        cout << (n / 5) + (n % 5) / 3 ;
    }
    else if ((n % 5) % 3 != 0)
    {
        while ( ((n % 5)% 3) != 0) {
            n -= 3;
            ++count;

            if (n < 0)
            {
                cout << -1 ;
                return 0;
            }
       
        }
    cout << (n / 5) + ++count;
}

  

}
