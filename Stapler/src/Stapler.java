/*
 * Name: Thomas Lloyd-Jones
 * Date: 2/1/20
 * Description: Stapler class
 */

public class Stapler
{

    //********Instance Variables********


    private int staples;		//how many staples in stapler
    private int capacity;		//how many staples it can hold
    private boolean closed;	//is stapler closed?


    //********Constructors********


    //Default constructor.
    //Set to: zero staples, capacity 250, closed.
    //Hint:  Write the default constructor here
    public Stapler() {
        staples = 0;
        capacity = 250;
        closed = true;
    }



    //Regular constructor.  Initialize instance variables with
    //provided values.  Assume user will use valid values for all.
    public Stapler(int staples, int capacity, boolean closed)
    {
        this.staples = staples;
        this.capacity = capacity;
        this.closed = closed;
    }

    //Copy constructor.  Initializes stapler with values provided
    //from another stapler.  Assume "temp" stapler has valid values.
    public Stapler(Stapler temp)
    {
        staples = temp.staples;
        capacity = temp.capacity;
        closed = temp.closed;
    }



    //********Mutator Methods (change values) ********

    //Close the stapler
    public void closeStapler()
    {
        this.closed = true;

    }

    //Open the stapler
    public void openStapler()
    {
        this.closed = false;
    }

    //Subtract a single staple.  The stapler can
    //staple only when already closed AND when it HAS STAPLES.
    //**Both** conditions **must** be true to staple.
    //HINT:  Requires one or more IF statements.
    public void staple()
    {
        if(this.closed && this.staples > 0){
            this.staples = this.staples - 1;
        }
        else { System.out.println("No Staples.");}
    }

    //Increase staples up to the maximum capacity.
    //The stapler must already be OPEN to add staples.
    //HINT: Requires IF statement(s) to make sure stapler is already open
    //and to make sure you fill it up to, BUT NOT BEYOND capacity.
    public void addStaples(int moreStaples)
    {
        if(!closed){
            if(moreStaples>capacity)
            this.staples = this.capacity;
        }
        else { this.staples = moreStaples;}
    }


    //********Accessor Methods (return values) ********

    //returns number of staples
    public int numStaples()
    {
        return this.staples;
    }

    //returns capacity of stapler
    public int getCapacity()
    {
        return this.capacity;
    }

    //returns open/closed status of stapler
    public boolean isClosed()
    {
        return this.closed;
    }

    //*********Other Methods*********************
    //returns a string representing this stapler -
    // The string says "This stapler has room for x staples"
    // where x is the capcity minus the current number of staples
    // Hint:  Override the toString() method here
    public String toString(){
        return (""+"This stapler has room for "+((this.capacity)-(this.staples))+" staples");
    }
}