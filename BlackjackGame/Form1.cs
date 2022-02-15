using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using BlackjackGame.Properties;

namespace BlackjackGame
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            
            //WindowsFormApplication1 should be replaced by the name of your project

            var rm = Resources.ResourceManager;

            var rnd = new Random();

            var card = rnd.Next(1, 53);

            var cardName = "" + card;

            var myImage = (Bitmap) rm.GetObject(cardName);

            pictureBox1.Image = myImage;

            card = rnd.Next(1, 53);

            cardName = "" + card;

            var myImage2 = (Bitmap) rm.GetObject(cardName);

            pictureBox3.Image = myImage2;

            card = rnd.Next(1, 53);

            cardName = "" + card;

            var myImage3 = (Bitmap) rm.GetObject(cardName);

            pictureBox3.Image = myImage3;

            card = rnd.Next(1, 53);

            cardName = "" + card;

            var myImage4 = (Bitmap) rm.GetObject(cardName);

            pictureBox4.Image = myImage4;

            card = rnd.Next(1, 53);

            cardName = "" + card;

            var myImage5 = (Bitmap) rm.GetObject(cardName);

            pictureBox5.Image = myImage5;

            
        }
        }
    }