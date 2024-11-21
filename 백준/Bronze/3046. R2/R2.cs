using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace baekjoon_with_cp4
{
    class Program
    {
        static void Main(string[] args)
        {

            string[] s = Console.ReadLine().Split();
            int a = int.Parse(s[0]);
            int average = int.Parse(s[1]);

            Console.WriteLine(average*2-a);

        }
    }

   
}
