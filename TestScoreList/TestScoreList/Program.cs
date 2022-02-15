using System;
using System.Globalization;
using System.Linq;
using System.Runtime.Remoting.Services;
using static System.Console;

namespace TestScoreList
{
    internal class TestScore
    {
        public static void Main(string[] args)
        {
            double[] areaCodeArr = {262, 414, 608, 715, 815, 920};
            double[] rates = {0.07, 0.10, 0.05, 0.16, 0.24, 0.14};
            var areaCode = Convert.ToInt32(ReadLine());
            var arrOut = 0;
            if (areaCodeArr.Contains(areaCode))
            {
                arrOut = Array.BinarySearch(areaCodeArr, areaCode);
                var mins = Convert.ToInt32(ReadLine());
                var total = rates[arrOut] * mins;
                WriteLine("Your phone call to area {0}, costs {1} per minute.", areaCode, rates[arrOut].ToString("C", CultureInfo.GetCultureInfo("en-US")));
                WriteLine("For {0} minutes the total is {1}", mins, total);
            }
            else {
                WriteLine("Phone call not in area");
            }
            
            
        }
    }
}