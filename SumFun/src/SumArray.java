import java.io.File;
import java.util.Arrays;
import java.util.Scanner;
/*

Thomas Lloyd-Jones
        12/19/2019
        Sum numbers of file by 13 and print highest
*/

public class SumArray {
    public int count = 0;
    private static int outNum = 0;
    static int finalNum = 0;
    public static void main(String[] args) {

        try {
            System.out.print("Enter the file name with extension : ");
            Scanner input = new Scanner(System.in);

            File file = new File(input.nextLine());

             input = new Scanner(file);


            while (input.hasNextLine()) {
                String line = input.nextLine();
                // System.out.println(line);
                outNum = checkLine(line);
                if(outNum>finalNum){
                    finalNum = outNum;
                }

            }
            input.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println(finalNum);
    }

    private static int checkLine(String line) {
        String[] lineArray = new String[line.length()];
        int highestNum = 0;
        int currentNum = 0;
        for (int i = 0; i < line.length(); i++) {
            lineArray[i] = String.valueOf(line.charAt(i));
        }
        System.out.println(line);
        System.out.println(Arrays.toString(lineArray));
        for (int a = 0; a < lineArray.length-12; a++) {

            for (int c = 0; c < 13; c++) {
                currentNum += Integer.parseInt(lineArray[a+c]);
            }

//                currentNum = Integer.parseInt(lineArray[a]) + Integer.parseInt(lineArray[a+1]) + Integer.parseInt(lineArray[a+2]) + Integer.parseInt(lineArray[a+3]);

             if(currentNum > highestNum){
                 highestNum = currentNum;
             }
             currentNum = 0;
        }
    return highestNum;
    }
}


