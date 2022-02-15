/*
 * Name: Thomas Lloyd-Jones
 * Date: 2/1/20
 * Description: Stapler tester
 */

//***************************************
//DRIVER PROGRAM CODE MAY NOT BE MODIFIED
//HOWEVER, DO PASTE RUN OUTPUT AT BOTTOM.
//***************************************

public class StaplerTester
{
    public static void main(String args[])
    {
        //create stapler objects
        Stapler test1 = new Stapler();
        Stapler test2 = new Stapler(25, 100, true);
        Stapler test3 = new Stapler(test2);

        //initial status
        System.out.println("BEFORE CHANGES");
        printStatus(test1, "test1");
        printStatus(test2, "test2");
        printStatus(test3, "test3");
        System.out.println();

        //first set of actions
        test1.staple();
        test1.staple();
        test2.staple();
        test2.staple();
        test3.openStapler();
        test3.staple();
        test3.staple();

        //middle status
        System.out.println("FIRST CHANGES");
        printStatus(test1, "test1");
        printStatus(test2, "test2");
        printStatus(test3, "test3");
        System.out.println();
        System.out.println();

        //second set of actions
        test1.openStapler();
        test1.addStaples(5000);
        test1.staple();
        test1.staple();
        test2.addStaples(10);
        test2.openStapler();
        test2.staple();
        test2.staple();
        test3.addStaples(10);
        test3.closeStapler();
        test3.staple();
        test3.staple();

        //final status
        System.out.println("SECOND CHANGES");
        printStatus(test1, "test1");
        printStatus(test2, "test2");
        printStatus(test3, "test3");
        System.out.println();
        System.out.println();

        System.out.println(test1);
        System.out.println(test2);
        System.out.println(test3);
        System.out.println();
        System.out.println();

        //done
        System.out.println("Done...");
    }

    //Prints Stapler Status.
    private static void printStatus(Stapler temp, String name)
    {
        System.out.print(name + " status:\t");
        System.out.print("staples = " + temp.numStaples() + "\t");
        System.out.print("capacity = " + temp.getCapacity() + "\t");
        System.out.print("closed = " + temp.isClosed());
        System.out.println();
    }

}

/*
PASTE RUN OUTPUT HERE:

"C:\Program Files\Java\jdk-13.0.1\bin\java.exe" "-javaagent:C:\Program Files\JetBrains\IntelliJ IDEA 2019.2.4\lib\idea_rt.jar=64281:C:\Program Files\JetBrains\IntelliJ IDEA 2019.2.4\bin" -Dfile.encoding=UTF-8 -classpath C:\Users\lloyd\IdeaProjects\Stapler\out\production\Stapler StaplerTester
BEFORE CHANGES
test1 status:	staples = 0	capacity = 250	closed = true
test2 status:	staples = 25	capacity = 100	closed = true
test3 status:	staples = 25	capacity = 100	closed = true

No Staples.
No Staples.
No Staples.
No Staples.
FIRST CHANGES
test1 status:	staples = 0	capacity = 250	closed = true
test2 status:	staples = 23	capacity = 100	closed = true
test3 status:	staples = 25	capacity = 100	closed = false


No Staples.
No Staples.
No Staples.
No Staples.
SECOND CHANGES
test1 status:	staples = 250	capacity = 250	closed = false
test2 status:	staples = 23	capacity = 100	closed = false
test3 status:	staples = 98	capacity = 100	closed = true


This stapler has room for 0 staples
This stapler has room for 77 staples
This stapler has room for 2 staples


Done...

Process finished with exit code 0
*/