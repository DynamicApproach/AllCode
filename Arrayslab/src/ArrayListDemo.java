import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class ArrayListDemo {
	
	//
	static ArrayList<String> listy = new ArrayList<String>();
	public static String word = "";
	private int value = 0;
	static Scanner sc = new Scanner( System.in );
	static Scanner nw = new Scanner( System.in );
	
	public static void main(String[] args) {

        menuOptions();
		int switchValue = getInput();
		
		while(switchValue != 6) {
		switch(switchValue) {
            case 1:
					System.out.println("What word would you like to add?");
					listy.add(nw.next());
					nextItem();
					switchValue = getInput();
					
					break;
				case 2:
                    System.out.println("What word would you like to remove?");
					listy.remove((nw.nextInt()-1));
					
					nextItem();
					switchValue = getInput();
					break;
				case 3:
					System.out.println(listy);
			
					
					nextItem();
					switchValue = sc.nextInt();
					break;
				case 4:
					System.out.println("Which item would you like to change?");
				int value = nw.nextInt();
				System.out.println("What would you like to change it to?");
					listy.set((value-1), nw.next());
					nextItem();
					switchValue = getInput();
					
					break;
				case 5:
				    // search for a word via nw input
					System.out.println("What would you like to find?");
					word = nw.next();
					if (listy.contains(word));{
					    for(int i = 0; i < listy.size(); i++)
                        {
                            if(listy.get(i).equals(word))
                                System.out.println(word+ " is at position " + (i+1));
                            }
                        }
					nextItem();
					switchValue = getInput();
					
					break;
				case 6:
					System.out.println("GAME OVER MAN!");
					System.exit(0);
					}	}
	}

		public static void menuOptions() {
            System.out.println("1. Add a word to the ArrayList");
            System.out.println("2. Remove a word from the ArrayList");
            System.out.println("3. Output the ArrayList");
            System.out.println("4. Change the value of an item in the ArrayList");
            System.out.println("5. Search for a value in the ArrayList");
            System.out.println("6. Quit");
            System.out.println("");
            System.out.println("What would you like to do?");
        }
	public static void nextItem(){
        System.out.println("What would you like to do?");
        

	}
	 public static int getInput()
	 {
	  while (true)
	  {
	   try
	   {
	    return sc.nextInt();
	   }
	   catch (InputMismatchException e)
	   {
	    sc.next();
	    System.out.print("That’s not "
	     + "an integer. Try again: ");
	   }
	  }
	 }

}
