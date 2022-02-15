
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;


/**
 *
 * @author User
 */
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
public class Euler549 {

    public static void main(String[] args) {
        FactorialDivisibility tester = new FactorialDivisibility();

        for (int i = 2; i <= 100; i++) {
            System.out.println(i + ": " + tester.sOfI(i));
        }
        //tester.runner();
    }

}
 
 


class FactorialDivisibility {

    private HashMap<Integer, BigInteger> factorials = new HashMap();
    private HashMap<Integer, Integer> intToMinFactorial = new HashMap();
    private int sum = 0;
    private HashMap<Long, Integer> primeFactors = new HashMap();
    private Long number = 0L;
    private ArrayList<Long> factors = new ArrayList();

    public FactorialDivisibility() {
        this.factorials.put(1, BigInteger.ONE);

    }

    public void runner() {
        for (int i = 2; i <= (int) Math.pow(10, 2); i++) {
            this.primeFactors.clear();
            this.sum = this.sum + this.sOfI(i);
        }
        System.out.println("total: " + this.sum);
    }

    public int sOfI(int i) {
        if (this.isPrime((long) i)) {
            return i;
        }
        else {
            this.number = (long) i;
            this.primeFactors.clear();
            this.getPrimeFactors();
            int seed = 1;
            int max = 1;
            for(long x: this.primeFactors.keySet()){
                if(Math.pow(x, this.primeFactors.get(x)) > max){
                    max = (int) Math.pow(x, this.primeFactors.get(x));
                    seed = (int) x;
                }
            }
            if(this.primeFactors.get((long) seed) == 1){
                return seed;
            }
            else if(this.intToMinFactorial.keySet().contains(max)){
                if(this.intToMinFactorial.keySet().contains(max)){
                    return this.intToMinFactorial.get(max);
                }
                else{
                    long j = this.primeFactors.get(seed);
                    this.computeMin(seed, j);
                    return this.intToMinFactorial.get((int) Math.pow(seed, max));
                }
            }

            return seed;
        }

    }

    public void computeMin(long p, long j){
        int total = 0;
        for (long i = p; i <= p*j; i = i + p) {
            this.primeFactors.clear();
            this.number = (long) i;
            this.getPrimeFactors();
            //System.out.println(i + "; " + j );
            total = total + this.primeFactors.get((long) p);
            if(total >= j){
                break;
            }
        }
        this.intToMinFactorial.put((int) Math.pow(p, j), total);
    }

    public boolean isPrime(Long n) {
        ArrayList<Long> arrayOfFactors = getFactorsOfInterest(n);

        if (arrayOfFactors.isEmpty()) { //If n has no factors less than or equal to the square root of n,
            return true;              // then n must be prime.
        }
        return false;                 // Otherwise, it is not prime.

    }

    public void getPrimeFactors() {
        if(this.isPrime(this.number)){
            this.primeFactors.put(this.number, 1);
        }
        while ((this.number != 1) && (!isPrime(this.number))) {

            this.factors = this.getFactorsOfInterest(this.number);
            for (Long x : this.factors) {
                if (isPrime(x)) {
                    if (!this.primeFactors.keySet().contains(x)) {
                        primeFactors.put(x, 1);
                    }
                    else {
                        this.primeFactors.replace(x, primeFactors.get(x) + 1);
                    }

                    if (isPrime(this.number / x)) {
                        if (!this.primeFactors.keySet().contains(this.number / x)) {
                            primeFactors.put(this.number / x, 1);
                        }
                        else {
                            this.primeFactors.replace(this.number / x, primeFactors.get(this.number / x) + 1);
                        }
                    }
                    else {
                        this.number = this.number / x;
                        break;
                    }
                    this.number = this.number / x;
                }
            }

        }
        //this.printPrimeFactors();
    }

    public ArrayList<Long> getFactorsOfInterest(Long n) {
        ArrayList<Long> factors = new ArrayList();

        for (Long i = 2L; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                factors.add(i);
            }
        }
        return factors;
    }

    public BigInteger factorialCalculator(int n) {
        BigInteger result = BigInteger.ONE;
        for (int i = 2; i <= n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }

}