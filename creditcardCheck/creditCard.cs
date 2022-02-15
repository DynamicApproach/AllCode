using System;
using System.Drawing;
using System.Windows.Forms;
using System.Drawing;


namespace creditcardCheck
{
    
    public partial class CreditForm : Form
    {
        public CreditForm()
        {
            InitializeComponent();
            checkBtn.BackColor = Color.Black;
            checkBtn.FlatStyle = FlatStyle.Flat;
            checkBtn.FlatAppearance.BorderSize = 1;
            checkBtn.FlatAppearance.BorderColor = Color.DarkSlateGray;
            


        }
        
        private void BtnClick(object sender, EventArgs e)
        {
            
            try
            { 
               long a= Convert.ToInt64(inputTxt.Text);
            
            
                int c = 0; 
                int b = 0;
                for (int i = 0; i < a.ToString().Length; i++)
                {
                
                    if((i %2) == 0)
                    {
                        //even
                        // dbl = current num *2
                    
                        int dbl = Convert.ToInt32(a.ToString().Substring(i,  1)) * 2;
                        // if more than two digits after doubling, add them instead
                        if (dbl.ToString().Length > 1)
                        {
                            string part = dbl.ToString();
                            int part1 = Convert.ToInt32(part.Substring(0, 1));
                            int part2 = Convert.ToInt32(part.Substring(1, 1));
                            int final = part1 + part2;
                            b += final;
                        
                        }
                        else
                        { 
                            // not two digit num, just add it
                            b += dbl;
                        }
                    }
                    else
                    {
                        // odd
                        // step 3
                    
                        c+= Convert.ToInt32(a.ToString().Substring(i,  1));
                    }
                }
                // add even and odd
                b += c;
            
                // check if divisible by 10
                ouputlbl.Text = (b % 10) == 0 ? "VALID" : "INVALID";
            }
            catch (Exception exception)
            {
                inputTxt.Text = inputTxt.Text == "" ? "No input" : "Too long, try again";
                if (inputTxt.Text.Length <= 12)
                {
                    ouputlbl.Text = "Too short";
                }
            }
        }

        private void CreditForm_Load(object sender, EventArgs e)
        {
            throw new System.NotImplementedException();
        }
    }
}