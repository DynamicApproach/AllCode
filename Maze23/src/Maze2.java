import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class Maze2
{
    private static char[][] maze;
    private static int startrow, startcol, finishrow, finishcol;
    private static ArrayList<String> mazeBuffer;

    public static void initializeMaze(String fileName)
    {
        startrow = startcol = finishrow = finishcol = -1;

        mazeBuffer = new ArrayList<String>();
        int numcols = 0;
        try
        {
            Scanner file = new Scanner(new File(fileName));
            while(file.hasNext())
            {
                String nextLine = file.nextLine();
                mazeBuffer.add(nextLine);
                if (nextLine.length() > numcols)
                    numcols = nextLine.length();
            }
        }
        catch(Exception e)
        {
            System.out.println(fileName + " has an issue");
        }
        int numrows = mazeBuffer.size();
        maze = new char[numrows][numcols];
        for (int r = 0; r < numrows; r ++)
        {
            String row = mazeBuffer.get(r);
            for (int c = 0; c < numcols; c++)
            {
                if(row.length() >= c)
                    maze[r][c]=row.charAt(c);
                else
                    maze[r][c]='*';

                if (maze[r][c] == 'S')
                {
                    startrow = r;
                    startcol = c;
                }
                if (maze[r][c] == 'F')
                {
                    finishrow = r;
                    finishcol = c;
                }
            }
        }
        System.out.println("Maze loaded");
    }

    public static void printMaze()
    {
        for (char[] row: maze)
        {
            for (char c: row)
                System.out.print(c);
            System.out.println();
        }
        System.out.println();

    }

    public static void main (String[] args)
    {
        initializeMaze("C:\\Users\\lloyd\\OneDrive\\School\\Intelli\\IdeaProjects\\Maze23\\src\\hardmaze.txt");
        printMaze();
        if (solveMaze(startrow, startcol))
            printMaze();
        else
            System.out.println("Unsolvable.");
    }

    private static boolean solveMaze(int r, int c) {


        if (r < 0 || c < 0 || r >= maze.length || c >= maze[0].length)
            return false;
        if (maze[r][c] == 'F'){
            maze[r][c] = '*';
            return true;}
        if (maze[r][c] != ' ' && maze[r][c] != 'S')
            return false;




        maze[r][c] = 'A';

        if(solveMaze(r-1,c)){
            maze[r][c] = '#';
            return true;
        }
        if(solveMaze(r+1,c)){
            maze[r][c] = '#';
            return true;
        }
        if(solveMaze(r,c-1)){
            maze[r][c] = '#';
            return true;
        }
        if(solveMaze(r, c+1)) {
            maze[r][c] = '#';
            return true;
        }
        return false;
    }
}