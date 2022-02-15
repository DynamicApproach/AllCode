using System;
using System.Drawing;
using System.Windows.Forms;

namespace LetsMakeADeal
{
    public partial class Form1 : Form
    {

        /*   Create a project named LetsMakeADeal.In this game, three prizes of varying value are assigned randomly to be hidden behind three “doors” that you
         *   can implement as Buttons.
         *   For example, the prizes might be a new car, a big-screen TV, and a live goat.
         *   The player chooses a Button, and then one of the two other prizes is revealed; the one revealed is never the most desirable prize.
         *   The user then has the option of changing the original selection to the remaining unseen choice.
         *   For example, consider these two game scenarios:
   Suppose that the most valuable prize is randomly assigned to the first button. If the user chooses the first button, reveal either of the other two prizes,
        and ask the user if he wants to change his selection.
   Suppose that the most valuable prize is assigned to the first button, but the user chooses the second button.Reveal the third prize so that the most 
        valuable prize’s location is still hidden, and then ask the user whether he wants to change his selection.
   After the user has chosen to retain his original selection or make a change, reveal what he has won.

   */
        Random a = new Random();
        int clickdoor = 0;
        public int b = 0;
        public int c;
        public int d;
        public bool click1 = false;
        public bool click2 = false;
        Point door1 = new Point(62, 227);
        Point door2 = new Point(313, 227);
        Point door3 = new Point(598, 220);
        public Form1()
        {
            
            InitializeComponent();
            b= a.Next(1, 4);
            c = a.Next(1, 4);
            while (c == b)
            {
                c = a.Next(1, 4);
            }
            if( b == 1 || c == 1)
            {
                if(b == 2 || c== 2)
                {
                    d = 3;
                }
                else
                {
                    d = 2;
                }
            }
            else { d = 1; }
            setLocations();
            // Give c a random num, but not the same as b -- top two prize slots now set
            // b, c and d now are equal to 1 2 or 3 in a random order

        }
        public void setLocations()
        {
            if (GetRank(b) == "Best")
            {
                picBest.Location = door1;
            }
            else if (GetRank(c) == "Best")
            {
                picBest.Location = door2;
            }
            else if (GetRank(d) == "Best")
            {
                picBest.Location = door3;
            }
            if (GetRank(b) == "Middle")
            {
                picMiddle.Location = door1;
            }
            else if (GetRank(c) == "Middle")
            {
                picMiddle.Location = door2;
            }
            else if (GetRank(d) == "Middle")
            {
                picMiddle.Location = door3;
            }
            if (GetRank(b) == "Worst")
            {
                picWorst.Location = door1;
            }
            else if (GetRank(c) == "Worst")
            {
                picWorst.Location = door2;
            }
            else if (GetRank(d) == "Worst")
            {
                picWorst.Location = door3;
            }

        }
        private void btnDoor1_Click(object sender, EventArgs e)
        {
            // uses b
            if (click1 == false)
            {
                clickdoor = 1;
                if (GetRank(b) == "Best")
                {
                    btnDoor2.Visible = false;
                    picBest.Location = door1;
                }
                else if (GetRank(b) == "Middle")
                {
                    btnDoor3.Visible = false;
                    picMiddle.Location = door1;
                }
                else if (GetRank(b) == "Worst")
                {
                    btnDoor1.Visible = false;
                    picWorst.Location = door2;
                }
                click1 = true;
                
                MessageBox.Show("You chose door 1, would you like to swap to the other door? If so hit change, if not, click again.");
            }
            if (click2 == true)
            { finalPrizeDecider(); }
            click2 = true;
        }

        private string GetRank(int e)
        {
            if(e == 1) { return "Best"; }
            if (e == 2) { return "Middle"; }
            if (e == 3) { return "Worst"; }
            return " WRONG";
        }

        private void btnDoor2_Click(object sender, EventArgs e)
        {
            // uses c
            if (click1 == false)
            {
                clickdoor = 2;
                if (GetRank(c) == "Best")
                {
                    btnDoor3.Visible = false;
                    picBest.Location = door2;
                }
                else if (GetRank(c) == "Middle")
                {
                    btnDoor1.Visible = false;
                    picMiddle.Location = door2;
                }
                else if (GetRank(c) == "Worst")
                {
                    btnDoor3.Visible = false;
                    picWorst.Location = door3;
                }
                click1 = true;
                
                MessageBox.Show("You chose door 2, would you like to swap to the other door? If so hit change, if not, click again.");
            }
            if (click2 == true)
            { finalPrizeDecider(); }
            click2 = true;
        }

        private void btnDoor3_Click(object sender, EventArgs e)
        {
            // uses d
            if (click1 == false)
            {
                clickdoor = 3;
                if (GetRank(d) == "Best")
                {
                    btnDoor2.Visible = false;
                    picBest.Location = door3;
                }
                else if (GetRank(d) == "Middle")
                {
                    btnDoor2.Visible = false;
                    picMiddle.Location = door3;
                }
                else if (GetRank(d) == "Worst")
                {
                    btnDoor1.Visible = false;
                    picWorst.Location = door1;
                }
                click1 = true;
                
                MessageBox.Show("You chose door 3, would you like to swap to the other door? If so hit change, if not, click again.");
            }
            if(click2 == true)
            { finalPrizeDecider(); }
            click2 = true;
        }
        public string finalPrize(int g)
        {
            if(GetRank(g) == "Best")
            {
                return "a car!";
            }else if(GetRank(g) == "Middle")
            {
                return "ten thousand dollars!";
            }
            return "a sheep";
        }

        private void btnChange_Click(object sender, EventArgs e)
        {
            if (click1 == true)
            {
                if (clickdoor == 1 && btnDoor2.Visible == true)
                {
                    clickdoor = 3;
                }
                else if (clickdoor == 2 && btnDoor1.Visible == true)
                {
                    clickdoor = 1;
                }
                else if (clickdoor == 2 && btnDoor3.Visible == true)
                {
                    clickdoor = 3;
                }
                else if (clickdoor == 3 && btnDoor2.Visible == true)
                {
                    clickdoor = 2;
                }
                else if (clickdoor == 3 && btnDoor1.Visible == true)
                {
                    clickdoor = 1;
                }
                else if (clickdoor == 1 && btnDoor3.Visible == true)
                {
                    clickdoor = 3;
                }
                finalPrizeDecider();
            }
            else
            {
                MessageBox.Show("Why try to break things? -.-; It's for people like you I have to add this! :)");
            }
        }

        private void finalPrizeDecider()
        {
            if (btnDoor1.Visible == true && btnDoor2.Visible == true)
            {
                if (clickdoor == 1)
                {
                    
                    btnDoor1.Visible = false;
                    MessageBox.Show("You won " + finalPrize(b));
                }
                else
                {
                    btnDoor2.Visible = false;
                    MessageBox.Show("You won " + finalPrize(c));
                }
            }
            if (btnDoor2.Visible == true && btnDoor3.Visible == true)
            {
                if (clickdoor == 2)
                {
                    btnDoor2.Visible = false;
                    
                    MessageBox.Show("You won " + finalPrize(c));
                }
                else
                {
                    btnDoor3.Visible = false;
                    MessageBox.Show("You won " + finalPrize(d));
                }
            }
            if (btnDoor1.Visible == true && btnDoor3.Visible == true)
            {
                if (clickdoor == 3)
                {
                    
                    btnDoor3.Visible = false;
                    MessageBox.Show("You won " + finalPrize(d));
                }
                else { btnDoor1.Visible = false;
                    MessageBox.Show("You won " + finalPrize(b)); }

            }
        }

    }
}
