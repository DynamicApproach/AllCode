namespace creditcardCheck
{
    partial class CreditForm
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
            this.titleLbl = new System.Windows.Forms.Label();
            this.inputTxt = new System.Windows.Forms.TextBox();
            this.ouputlbl = new System.Windows.Forms.Label();
            this.checkBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // titleLbl
            // 
            this.titleLbl.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.titleLbl.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.titleLbl.Location = new System.Drawing.Point(47, 106);
            this.titleLbl.Name = "titleLbl";
            this.titleLbl.Size = new System.Drawing.Size(306, 61);
            this.titleLbl.TabIndex = 0;
            this.titleLbl.Text = "Title:";
            // 
            // inputTxt
            // 
            this.inputTxt.BackColor = System.Drawing.SystemColors.InactiveCaptionText;
            this.inputTxt.ForeColor = System.Drawing.SystemColors.Info;
            this.inputTxt.Location = new System.Drawing.Point(47, 181);
            this.inputTxt.Name = "inputTxt";
            this.inputTxt.Size = new System.Drawing.Size(312, 20);
            this.inputTxt.TabIndex = 1;
            // 
            // ouputlbl
            // 
            this.ouputlbl.ForeColor = System.Drawing.SystemColors.Control;
            this.ouputlbl.Location = new System.Drawing.Point(42, 324);
            this.ouputlbl.Name = "ouputlbl";
            this.ouputlbl.Size = new System.Drawing.Size(317, 70);
            this.ouputlbl.TabIndex = 2;
            // 
            // checkBtn
            // 
            this.checkBtn.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.checkBtn.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.checkBtn.Location = new System.Drawing.Point(537, 289);
            this.checkBtn.Name = "checkBtn";
            this.checkBtn.Size = new System.Drawing.Size(247, 104);
            this.checkBtn.TabIndex = 3;
            this.checkBtn.Text = "Check This Credit Card";
            this.checkBtn.UseVisualStyleBackColor = false;
            this.checkBtn.Click += new System.EventHandler(this.BtnClick);
            // 
            // CreditForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Desktop;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.checkBtn);
            this.Controls.Add(this.ouputlbl);
            this.Controls.Add(this.inputTxt);
            this.Controls.Add(this.titleLbl);
            this.Name = "CreditForm";
            this.Text = "Check Credit Card";
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        private System.Windows.Forms.Button checkBtn;

        private System.Windows.Forms.TextBox inputTxt;

        private System.Windows.Forms.Label ouputlbl;
        private System.Windows.Forms.Label titleLbl;

        #endregion
    }
}