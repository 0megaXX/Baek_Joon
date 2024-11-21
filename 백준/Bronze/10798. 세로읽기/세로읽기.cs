using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;



namespace baekjoon_with_cp4
{
    class Program
    {
        static void Main(string[] args)
        {


            string[] s = new string[5];

            for (int i = 0; i < 5; i++)
            {
                s[i] = Console.ReadLine();
            }




            for (int i = 0; i <15; i++)
            {
                for (int j = 0; j <5; j++)
                {
                   if(s[j].Length>i)
                        Console.Write(s[j][i]);
                }
            }

        }

    }

   
}
