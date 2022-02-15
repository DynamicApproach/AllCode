namespace InputMethodDemo2
{
    using static System.Console;
    using System;
    class InputMethodDemo2
    {
       static int first, second;
        static void Main()
        {
            InputMethod(out first, out second);
            WriteLine("After InputMethod first is {0}", first); 
            WriteLine("and second is {0}", second);
        } 
        private static void InputMethod(out int one, out int two)
        {
            string s1, s2;
            Write("Enter first integer ");
            s1 = ReadLine();
            Write("Enter second integer ");
            s2 = ReadLine();
            one = Convert.ToInt32(s1);
            two = Convert.ToInt32(s2);
        }
    
        public static int DataEntry(string whichOne)
        {
            Write("Enter integer {0}", whichOne);
            return  Convert.ToInt32(ReadLine());
        }

    }
}