using static System.Console;
class IntegerFacts
{
    static void Main()
    {
        int high = 0, low = 0, sum = 0;
        double average = 0.0;
        int[] arr = new int[10];
        int count = FillArray(arr);
        Statistics(arr, count, out high, out low, out sum, out average);
        WriteLine("The array has {0} values", count);
        WriteLine("The highest value is {0}", high);
        WriteLine("The lowest value is {0}", low);
        WriteLine("The sum of the values is {0}", sum);
        WriteLine("The average is {0}", average);
    }

    public static int FillArray(int[] array)
    {
        int num, count = 0;
        while(count < 10){
            WriteLine("enter a num");
            if(int.TryParse(ReadLine(), out num) && num != 999){
                array[count] = num;
                count++;
            }
            else if(num == 999){
                break;
            }
        }
        return count;
     
    }
    public static void Statistics(int[] array, int els, out int high, out int low, out int sum, out double avg)
    {
        sum = 0;
        avg = 0;
        high = array[0];
        low = array[0];
        for(int i = 0; i < els; i++){
            if(array[i] > high){
                high = array[i];
                WriteLine("Setting High");
            }
            if(array[i] < low){
                low = array[i];
                WriteLine("Setting Low");
            }
            avg += array[i];
            sum += array[i];
        }
        avg /= els;

    }   

}