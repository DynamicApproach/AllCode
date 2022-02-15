
namespace LetsMakeADeal
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnDoor1 = new System.Windows.Forms.Button();
            this.btnDoor2 = new System.Windows.Forms.Button();
            this.btnChange = new System.Windows.Forms.Button();
            this.btnDoor3 = new System.Windows.Forms.Button();
            this.picMiddle = new System.Windows.Forms.PictureBox();
            this.picBest = new System.Windows.Forms.PictureBox();
            this.picWorst = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.picMiddle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBest)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picWorst)).BeginInit();
            this.SuspendLayout();
            // 
            // btnDoor1
            // 
            this.btnDoor1.BackgroundImage = global::LetsMakeADeal.Properties.Resources.th__1_;
            this.btnDoor1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnDoor1.Location = new System.Drawing.Point(35, 62);
            this.btnDoor1.Name = "btnDoor1";
            this.btnDoor1.Size = new System.Drawing.Size(154, 331);
            this.btnDoor1.TabIndex = 0;
            this.btnDoor1.UseVisualStyleBackColor = true;
            this.btnDoor1.Click += new System.EventHandler(this.btnDoor1_Click);
            // 
            // btnDoor2
            // 
            this.btnDoor2.BackgroundImage = global::LetsMakeADeal.Properties.Resources.th__1_;
            this.btnDoor2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnDoor2.Location = new System.Drawing.Point(290, 62);
            this.btnDoor2.Name = "btnDoor2";
            this.btnDoor2.Size = new System.Drawing.Size(154, 331);
            this.btnDoor2.TabIndex = 1;
            this.btnDoor2.UseVisualStyleBackColor = true;
            this.btnDoor2.Click += new System.EventHandler(this.btnDoor2_Click);
            // 
            // btnChange
            // 
            this.btnChange.Location = new System.Drawing.Point(200, 415);
            this.btnChange.Name = "btnChange";
            this.btnChange.Size = new System.Drawing.Size(351, 23);
            this.btnChange.TabIndex = 3;
            this.btnChange.Text = "Change?";
            this.btnChange.UseVisualStyleBackColor = true;
            this.btnChange.Click += new System.EventHandler(this.btnChange_Click);
            // 
            // btnDoor3
            // 
            this.btnDoor3.BackgroundImage = global::LetsMakeADeal.Properties.Resources.th__1_;
            this.btnDoor3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnDoor3.Location = new System.Drawing.Point(575, 62);
            this.btnDoor3.Name = "btnDoor3";
            this.btnDoor3.Size = new System.Drawing.Size(154, 331);
            this.btnDoor3.TabIndex = 2;
            this.btnDoor3.UseVisualStyleBackColor = true;
            this.btnDoor3.Click += new System.EventHandler(this.btnDoor3_Click);
            // 
            // picMiddle
            // 
            this.picMiddle.Image = global::LetsMakeADeal.Properties.Resources.setup;
            this.picMiddle.Location = new System.Drawing.Point(598, 220);
            this.picMiddle.Name = "picMiddle";
            this.picMiddle.Size = new System.Drawing.Size(103, 57);
            this.picMiddle.TabIndex = 6;
            this.picMiddle.TabStop = false;
            // 
            // picBest
            // 
            this.picBest.Location = new System.Drawing.Point(62, 227);
            this.picBest.Name = "picBest";
            this.picBest.Size = new System.Drawing.Size(95, 58);
            this.picBest.TabIndex = 5;
            this.picBest.TabStop = false;
            // 
            // picWorst
            // 
            this.picWorst.Image = global::LetsMakeADeal.Properties.Resources._3d;
            this.picWorst.Location = new System.Drawing.Point(313, 227);
            this.picWorst.Name = "picWorst";
            this.picWorst.Size = new System.Drawing.Size(100, 50);
            this.picWorst.TabIndex = 4;
            this.picWorst.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnDoor1);
            this.Controls.Add(this.btnDoor2);
            this.Controls.Add(this.btnDoor3);
            this.Controls.Add(this.picMiddle);
            this.Controls.Add(this.picBest);
            this.Controls.Add(this.picWorst);
            this.Controls.Add(this.btnChange);
            this.Name = "Form1";
            this.Text = "LETSMAKEADEAL";
            ((System.ComponentModel.ISupportInitialize)(this.picMiddle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picBest)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picWorst)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnDoor1;
        private System.Windows.Forms.Button btnDoor2;
        private System.Windows.Forms.Button btnDoor3;
        private System.Windows.Forms.Button btnChange;
        private System.Windows.Forms.PictureBox picWorst;
        private System.Windows.Forms.PictureBox picBest;
        private System.Windows.Forms.PictureBox picMiddle;
    }
}

