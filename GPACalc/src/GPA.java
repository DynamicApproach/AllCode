import java.util.Scanner;

public class GPA {
    /*
        1.)    Ask user for how many courses they are taking.
                2.)    Create 3 arrays:
        a.       1 to hold course name
        b.       1 to hold number of credits for the course
        c.       1 to hold course grade (2.67)
    3.)    Write a loop to read in all the information for each course
    4.)    Calculate the GPA
    */
    private static double gpaTotal = 0;
    private static Scanner sc = new Scanner(System.in);
    private static int totalCredits =0;

    public static void main(String[] args) {
        System.out.println("How many courses are you taking?");
        int courseAmount = sc.nextInt();
        double finalGPA = GPACalc(courseAmount);
        System.out.println("Your current GPA stands at "+ finalGPA);
        if(finalGPA < 2){
            System.out.println("Ya messing up! Do your damn work!");
        }
    }
    private static double GPACalc(int courseAmount){

        gpaTotal =createGPA(inputs(courseAmount));
        gpaTotal = (gpaTotal/totalCredits);
        return gpaTotal;
    }

    private static double[] inputs(int courseAmount) {
        String[] courseNames = new String[courseAmount];
        int[] creditHours = new int[courseAmount];
        double[] courseGrades = new double[courseAmount];
        double[] arrGpa = new double[courseAmount];
        // get all info via sys input
        for (int i = 0; i < courseAmount; i++) {
            System.out.println("Enter course name for course " + (i+1));
            courseNames[i] = sc.next();
            System.out.println("Enter credits for course " + (i+1));
            try{creditHours[i] = sc.nextInt();} catch (Exception e) {
                System.out.println("You need to enter an integer. No decimals in credits! >:(");
            }
            System.out.println("Enter grade for course " + (i+1));
            courseGrades[i] = sc.nextDouble();
        }
        for (int k = 0; k < courseGrades.length; k++) {
            arrGpa[k] = (creditHours[k]) * (courseGrades[k]);
            totalCredits += (creditHours[k]);
        }
        return arrGpa;
    }
    public static double createGPA(double[] arrGpa){
        for (int j = 0; j < arrGpa.length; j++) {
        gpaTotal += (arrGpa[j]);
     }
    return gpaTotal;
    }
}
