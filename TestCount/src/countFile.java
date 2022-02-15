import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

/*
Thomas Lloyd-Jones
12/19/19
CountArrays
*/
public class countFile {

    private static int lineCount;

    public static void main(String[] args) {

        try {
            System.out.print("Enter the file name with extension : ");

            Scanner input = new Scanner(System.in);

            File file = new File(input.nextLine());

            input = new Scanner(file);


            while (input.hasNextLine()) {
                String line = input.nextLine();
                checkLine(line);
            }
            input.close();

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    private static boolean checkLine(String line) {
        String[] lineArray = new String[line.length()];
        int currentNum = 0;
        for (int i = 0; i < line.length(); i++) {
            lineArray[i] = String.valueOf(line.charAt(i));
        }
        lineCount++;
        if (!line.contains("1")) {
            System.out.println("There is no: 1 " + " in line " + lineCount);
        }
        if (!line.contains("2")) {
            System.out.println("There is no: 2 " + " in line "+ lineCount);
        }
        if (!line.contains("3")) {
            System.out.println("There is no: 3 " + "in line "+ lineCount);
        }
        if (!line.contains("4")) {
            System.out.println("There is no:  4 " + " in line "+ lineCount);
        }
        if (!line.contains("5")) {
            System.out.println("There is no: 5 " + " in line "+ lineCount);
        }
        if (!line.contains("6")) {
            System.out.println("There is no: 6 " + " in line "+ lineCount);
        }if (!line.contains("7")) {
            System.out.println("There is no: 7 " + " in line "+ lineCount);
        }if (!line.contains("8")) {
            System.out.println("There is no: 8" + " in line "+ lineCount);
        }if (!line.contains("9")) {
            System.out.println("There is no: 9" + " in line "+ lineCount);
        }





        return true;
    }
}