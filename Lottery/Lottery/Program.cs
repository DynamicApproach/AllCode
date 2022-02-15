 using System;
 using static System.Console;
 namespace Lottery
{
    internal static class Lottery
    {
        private static void Main()
        {
            var ranNumberGenerator = new Random();
            var a = ranNumberGenerator.Next(0, 9);
            var b = ranNumberGenerator.Next(0, 9);
            var c = ranNumberGenerator.Next(0, 9);
            var user1 = Convert.ToInt32(ReadLine());
            var user2 = Convert.ToInt32(ReadLine());
            var user3 = Convert.ToInt32(ReadLine());
            var match = 0;
            double reward = 0;
            if (user1 == a || user1 == b || user1 == c) match++;
            if (user2 == a || user2 == b || user2 == c) match++;
            if (user3 == a || user3 == b || user3 == c) match++;
            if (match != 0) reward = Math.Pow(10, match);
            var ab = Convert.ToInt32(user1 + "" + user2 + "" + user3 + "");
            if (ab == Convert.ToInt32(a + "" + b + "" + c + "")) reward = 10000;
            WriteLine("You got " + match + " matches" + " awarding " + reward);
        }
    }

}