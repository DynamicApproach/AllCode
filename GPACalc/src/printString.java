import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ReverseLines{
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(new File("reverselines_file.txt"));
        reverseLines(input);
    }

    public static void reverseLines(Scanner input){
        while (input.hasNextLine()){
            String eachLine = input.nextLine();

            for(int i = eachLine.length() - 1; i > -1; i--){
                System.out.print(eachLine.charAt(i));
            }
            System.out.println();
        }
    }
}
