import java.util.Scanner;

public class TriangleAreaApp {

	int area = 0;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner( System.in );

		
		System.out.println("Enter 3 sides of a triangle: ");
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		double c = sc.nextDouble();
		
		double s = (a+b+c)/2;
		double area = Math.sqrt(s*(s-a)*(s-b)*(s-c) );
		
		System.out.println("The area of a traingle with side lengths of "+ 
				a + ", " + b + ", and " + c + " is " + area + " square units.");

		
	}
}
