using System;
using System.Globalization;
using static System.Console;
namespace ConvertMilesToKilometers
{
    static class ConvertMilesToKilometers
    {
        public static void Main()
        {
            double a = Double.TryParse(Read());
            ConvertToKilometers(a);
            System.Console.WriteLine(100*1.60934);
        }

        public static double ConvertToKilometers(double miles)
        { 
           const double kmcon = 1.60934;
           double totalkm = 0;
           totalkm = (miles * kmcon);
           WriteLine("{0}",totalkm);
           
           return  totalkm;
        }
    }

}
