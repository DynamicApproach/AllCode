import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
/*
Thomas Lloyd-Jones
2/13/20
Solve the maze =D
*/

public class Maze {
    static int rows;
    static int columns;
    static char[][] mazeArr;
    static int startPoint;
    static int startPoint1;
    static char[][] maze;
    public static void main(String[] args) throws FileNotFoundException {
        /*char[][] maze = Maze();
        for (int i = 0; i < rows+2; i++) {
            for (int j = 0; j < columns+2; j++) {

                System.out.print(maze[i][j]);
            }

            System.out.println();
        }*/  //- testing code
        maze = Maze();
        //printMaze(); testing code

        if (solveMaze(startPoint, startPoint1))
            printMaze();
        else
            System.out.println("error");
    }
    public static void printMaze()  {
        for (int i = 0; i < rows+2; i++) {
            for (int j = 0; j < columns+2; j++) {

                System.out.print(maze[i][j]);
            }
            System.out.println();
        }
    }


    public static char[][] Maze() throws FileNotFoundException {


        Scanner sc = null;
        try {
            File maze = new File("src\\maze.txt");
            sc = new Scanner(maze);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int[] totalSizeOfMaze = new int[2];  // rows x columns
        totalSizeOfMaze[0] = sc.nextInt();
        rows = totalSizeOfMaze[0];
        totalSizeOfMaze[1] = sc.nextInt();
        columns = totalSizeOfMaze[1];

        startPoint = sc.nextInt();   // start points
        startPoint1 = sc.nextInt();   // start points
        startPoint += 1;
        startPoint1+=1;
        char[][] mazeArr = new char[rows + 2][columns + 2]; // arr for maze to sit in w/ sizes
        String fullMaze = "";


        while (sc.hasNext()) {
            fullMaze += sc.next();
        }

        int count = 0;

        for (int k = 0; k < columns + 2; k++) {
            mazeArr[k][0] = '#';
            mazeArr[0][k] = '#';
        }

        for (int l = 0; l < rows + 2; l++) {
            mazeArr[columns + 1][l] = '#';
            mazeArr[l][columns + 1] = '#';
        }

        for (int i = 0; i <= rows - 1; i++) {         // loop for rows
            for (int j = 0; j <= columns - 1; j++) {  // loop for columns
                mazeArr[i + 1][j + 1] = fullMaze.charAt(count);
                count++;
            }

        }
        return mazeArr;
    }

    public static boolean solveMaze(int startPoint,int startPoint1){ // StarLoc == [rows][columns]

        if (startPoint < 0 || startPoint1 < 0 || startPoint >= maze.length || startPoint1 >= maze[0].length)
            return false;
        if (maze[startPoint][startPoint1] == 'E'){  // if at final block
            maze[startPoint][startPoint1] = '*';
            return true;}
        if (maze[startPoint][startPoint1] != 'O' && maze[startPoint][startPoint1] != 'S') // on path
            return false;
        maze[startPoint][startPoint1] = '='; // path didnt work
        if(solveMaze(startPoint-1,startPoint1)){
            maze[startPoint][startPoint1] = '%';
            return true;
        }
        if(solveMaze(startPoint+1,startPoint1)){
            maze[startPoint][startPoint1] = '%';
            return true;
        }
        if(solveMaze(startPoint,startPoint1-1)){
            maze[startPoint][startPoint1] = '%';
            return true;
        }
        if(solveMaze(startPoint, startPoint1+1)) {
            maze[startPoint][startPoint1] = '%';
            return true;
        }
        return false;
    }



}

