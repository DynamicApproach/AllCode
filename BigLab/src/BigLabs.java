import java.math.BigInteger;

public class BigLab {

	public static void main(String[] args) {

		divisibleByTwoOrThree();
		bigSquaredValues();
		largePrimeValues();
		BonusMersennePrimes();
	}

	//	(Divisible by 2 or 3) Find the first ten numbers with 50 decimal digits that are
	//	divisible by 2 or 3.
	// Included in Sample
	private static void divisibleByTwoOrThree() {


	}

	//	(Square numbers) Find the first ten square numbers that are greater than
	//	Long.MAX_VALUE. A square number is a number in the form of n^2. For example,
	//	4, 9, and 16 are square numbers. Find an efficient approach to run your
	//	program fast.
	private static void bigSquaredValues() {

		BigInteger temp = BigInteger.valueOf(Long.MAX_VALUE);
		int counter = 0;
		// squareroot the value then check for decimal - if it has decimal it isn't perfect square
		//  loop this 10 times
		BigInteger square = Math.sqrt(long.MAX_VALUE); //  bigint square is long.max div 2
		//
		while(counter < 10) { // loop 10 times
			square += 1;
			if (square*square>temp){
				counter++;
				System.out.println(square);
			}

		}

	}



	//	(Large prime numbers) Write a program that finds five prime numbers larger
	//	than Long.MAX_VALUE.
	private static void largePrimeValues() {
		BigInteger val1 = BigInteger.valueOf(Long.MAX_VALUE); // gets long val
		BigInteger result = val1.nextProbablePrime(); // gets next prime
		for(int i = 0; i < 10; ++i) { // loops 10 times
			if(result.isProbablePrime(10)) { // check if prime

				System.out.println(result); // print if prime
			}
			result = result.nextProbablePrime(); // next attempt for prime

		} // restart loop

	}




	//	*BONUS
	//	(Mersenne prime) A prime number is called a Mersenne prime if it can be written
	//	in the form 2^p - 1 for some positive integer p. Write a program that finds
	//	all Mersenne primes with p � 100 and displays the output as shown below.
	//	(Hint: You have to use BigInteger to store the number, because it is too big to
	//	be stored in long. Your program may take several hours to run.)
	//	p 2^p � 1
	//	2 3
	//	3 7
	//	5 31
	//	...
	private static void BonusMersennePrimes() {


	}


}