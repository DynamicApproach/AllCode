import java.math.*;
import java.util.Scanner;
//
/*+Rational()
        +Rational(num: long, denom: long)
        +getNumerator(): long
        +getDenominator(): long
        +add(secondRational: Rational): Rational
        +subtract(secondRational: Rational): Rational
        +multiply(secondRational: Rational): Rational
        +divide(secondRational: Rational): Rational
        +toString(): String
        -gcd(n: long, d: long): long
        *//* You have to use the following template to submit to Revel.
   Note: To test the code using the CheciExerciseTool, you will submit entire code.
   To submit your code to Revel, you must only submit the code enclosed between
 /* You have to use the following template to submit to Revel.
   Note: To test the code using the CheciExerciseTool, you will submit entire code.
   To submit your code to Revel, you must only submit the code enclosed between
     // BEGIN REVEL SUBMISSION

     // END REVEL SUBMISSION
*/
public class Exercise13_15 {
    public static void main(String[] args) {
        // Prompt the user to enter two Rational numbers
        Scanner input = new Scanner(System.in);
        System.out.print("Enter rational number1 with num and denom seperated by a space: ");
        String n1 = input.next();
        String d1 = input.next();

        System.out.print("Enter rational number2 with num and denom seperated by a space: ");
        String n2 = input.next();
        String d2 = input.next();

        Rational r1 = new Rational(new BigInteger(n1), new BigInteger(d1));
        Rational r2 = new Rational(new BigInteger(n2), new BigInteger(d2));

        // Display results
        System.out.println(r1 + " + " + r2 + " = " + r1.add(r2));
        System.out.println(r1 + " - " + r2 + " = " + r1.subtract(r2));
        System.out.println(r1 + " * " + r2 + " = " + r1.multiply(r2));
        System.out.println(r1 + " / " + r2 + " = " + r1.divide(r2));
        System.out.println(r2 + " is " + r2.doubleValue());
    }
}

class Rational extends Number implements Comparable<Rational> {
    private BigInteger num = BigInteger.ZERO;
    private BigInteger denom = BigInteger.ONE;

    // Write your code
    private BigInteger[] r = new BigInteger[2];


    public Rational() {
        this(new BigInteger("0"), new BigInteger("1"));
    }


    public Rational(BigInteger num, BigInteger denom) {
        BigInteger gcd = gcd(num, denom);
        r[0] = (denom.compareTo(BigInteger.ZERO) > 0
                ? BigInteger.ONE :
                new BigInteger("-1")).multiply(num.divide(gcd));
        r[1] = denom.divide(gcd);
    }


    private static BigInteger gcd(BigInteger n, BigInteger d) {
        BigInteger n1 = n;
        BigInteger n2 = d;
        BigInteger gcd = BigInteger.ONE;

        for (BigInteger i = BigInteger.ONE;
             i.compareTo(n1) <= 0 && i.compareTo(n2) <= 0;
             i = i.add(BigInteger.ONE)) {
            if (n1.remainder(i).compareTo(BigInteger.ZERO) == 0 &&
                    n2.remainder(i).compareTo(BigInteger.ZERO) == 0)
                gcd = i;
        }

        return gcd;
    }


    public BigInteger getNumerator() {
        return r[0];
    }


    public BigInteger getDenominator() {
        return r[1];
    }


    public Rational add(Rational secondRational) {
        BigInteger n = (r[0].multiply(secondRational.getDenominator())).add(
                r[1].multiply(secondRational.getNumerator()));
        BigInteger d = r[1].multiply(secondRational.getDenominator());
        return new Rational(n, d);
    }

    public Rational subtract(Rational secondRational) {
        BigInteger n = (r[0].multiply(secondRational.getDenominator())).subtract(
                r[1].multiply(secondRational.getNumerator()));
        BigInteger d = r[1].multiply(secondRational.getDenominator());
        return new Rational(n, d);
    }

    public Rational multiply(Rational secondRational) {
        BigInteger n = r[0].multiply(secondRational.getNumerator());
        BigInteger d = r[1].multiply(secondRational.getDenominator());
        return new Rational(n, d);
    }
    public Rational divide(Rational secondRational) {
        BigInteger n = r[0].multiply(secondRational.getDenominator());
        BigInteger d = r[1].multiply(secondRational.getNumerator());
        return new Rational(n, d);
    }
    @Override
    public String toString() {
        if (r[1].compareTo(BigInteger.ONE) == 0)
            return r[0] + "";
        else
            return r[0] + "/" + r[1];
    }

    @Override // Override the equals method in the Object class
    public boolean equals(Object other) {
        if (((this.subtract((Rational)other).getNumerator()).compareTo(
                BigInteger.ZERO) == 0))
            return true;
        else
            return false;
    }

    @Override // Implement the abstract intValue method in Number
    public int intValue() {
        return (int)doubleValue();
    }

    @Override // Implement the abstract floatValue method in Number
    public float floatValue() {
        return (float)doubleValue();
    }
    @Override // Implement the doubleValue method in Number
    public double doubleValue() {
        return this.getNumerator().doubleValue() /
                this.getDenominator().doubleValue();
    }
    @Override // Implement the abstract longValue method in Number
    public long longValue() {
        return (long)doubleValue();
    }
    @Override
    public int compareTo(Rational o) {
        BigInteger zero = BigInteger.ZERO;
        BigInteger n = this.subtract((Rational)o).getNumerator();
        if (n.compareTo(zero) > 0)
            return 1;
        else if (n.compareTo(zero) < 0)
            return -1;
        else
            return 0;
    }
}