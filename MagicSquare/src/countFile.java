import java.io.File;
import java.util.Scanner;

/*
Thomas Lloyd-Jones
12/19/19
he user what size square matrix they would like to create and prompt for all the values to put into the matrix.
The program will then tell the user if the board is a “Magic Square” or not. (All the rows, columns, and diagonals
 have the same sum.  For this assignment, it does not need to be normal, or even contain distinct numbers.
 However, if yours check for these, you will get bonus points :) )
You are to create a SquareMatrix class that will have an instance variable named board that will refer to a 2-D array of integers.
Required methods:
1.         Constructors (x2)
a.        With an integer parameter, specifying the size of the array.
b.        With a 2-D array parameter, the initial board.
2.        toString() method
a.        This method should return the values of the square matrix (as a single String object).
3.        isMagic()
a.        This method returns true if it is a magic square, false otherwise.

The above listed methods are the minimum required methods for your SquareMatrix class. Other helper methods are recommended.  I realize that you may only use one of the two constructors in your tester program, but I would like to see both.

*/
class SquareMatrix{
    int[][] board;
    public int size = 0;
    Scanner sc = new Scanner( System.in );
    public static void main(String[] args) {

    }
    public void SquareMatrix(){
        System.out.println("Enter size: ");

        size = sc.nextInt();

    }
    public void SquareMatrix(int size){
        int b = 0;
        int board[][] = new int[size][size];
        for(int a = 0; a < size; a++){
            for ( b = 0; b < size; b++) {
                System.out.println("Input Column: " + ""+a+" in row" + b);
                board[a][b] = sc.nextInt();


            }
            System.out.println("Input Column: " + ""+a+" in row" + b);
            board[a][b] = sc.nextInt();
        }
        isMagic(board);

    }
    public boolean isMagic(int[][] board) {
        int l =0;
        int size = board.length;

        // For sums of Rows and column and diag - add up then compare
        for (int i = 0; i < size; i++) {
            int colSum = 0;
            int diagSum=0;
            int rowSum = 0;
            int diagSum1 =0;
            for (int j = 0; j < size; j++){
                rowSum += board[i][j];
            }
            for (int j = 0; j < size; j++){
                colSum += board[j][i];
            }
            for(int k = 0; k < size; k++, l++){
                diagSum = board[k][l];
            }

            for(int k = size; 0 < k; k--, l++){
                 diagSum1 = board[k][l];
            }
            if(colSum!= rowSum){ // check row vs col sum
                return false;
            }
            if(diagSum != rowSum || diagSum != colSum){ // compare diag, row and col sum
                return false;
            }
            if (diagSum1 != diagSum){ // opposite diag
                return false;
            }

        }
        return true;

    }
    @Override
    public String toString() {
        return super.toString();
    }
}