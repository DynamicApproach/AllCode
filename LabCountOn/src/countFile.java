import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
Thomas Lloyd-Jones
12/19/19
Count lines/words/copy to console
*/
public class countFile {

    public static void main(String[] args) throws FileNotFoundException {
        echoInput("fileName.txt");

        int numLines = getNumLinesInFile("fileName.txt");
        System.out.println("There are " + numLines + " in the file.");
        int numWords = getNumWordsInFile("fileName.txt");
        System.out.println("There are " + numLines + " in the file.");


    }

    private static int getNumWordsInFile(String s) {
        int numWords = 0;
        try {
            System.out.print("Enter the file name with extension : ");

            Scanner input;

            File file = new File(s);

            input = new Scanner(file);


            while (input.hasNext()) {
                String line = input.next();
                System.out.println(line);
            }
            input.close();

        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return numWords;
    }

    private static int getNumLinesInFile(String s) throws FileNotFoundException {
        File file = new File(s);
        Scanner input = new Scanner(file);
        int counter =0;

        while (input.hasNext()) {

            counter++;
        }
        return counter;
    }


    private static void echoInput(String s) {
        try {
            System.out.print("Enter the file name with extension : ");

            Scanner input;

            File file = new File(s);

            input = new Scanner(file);


            while (input.hasNextLine()) {
                String line = input.nextLine();
                System.out.println(line);
            }
            input.close();

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

}