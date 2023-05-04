namespace _01___SocketUDP
{
    partial class Form1
    {
        /// <summary>
        /// Variabile di progettazione necessaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Pulire le risorse in uso.
        /// </summary>
        /// <param name="disposing">ha valore true se le risorse gestite devono essere eliminate, false in caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Codice generato da Progettazione Windows Form

        /// <summary>
        /// Metodo necessario per il supporto della finestra di progettazione. Non modificare
        /// il contenuto del metodo con l'editor di codice.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtServerIP = new System.Windows.Forms.TextBox();
            this.NUD_ServerPort = new System.Windows.Forms.NumericUpDown();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.txtMessaggio = new System.Windows.Forms.RichTextBox();
            this.btnInvia = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_ServerPort)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txtServerIP);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(127, 54);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "SERVER IP";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.NUD_ServerPort);
            this.groupBox2.Location = new System.Drawing.Point(145, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(124, 54);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "SERVER PORT";
            // 
            // txtServerIP
            // 
            this.txtServerIP.Location = new System.Drawing.Point(6, 19);
            this.txtServerIP.Name = "txtServerIP";
            this.txtServerIP.Size = new System.Drawing.Size(112, 20);
            this.txtServerIP.TabIndex = 1;
            this.txtServerIP.Text = "127.0.0.1";
            this.txtServerIP.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // NUD_ServerPort
            // 
            this.NUD_ServerPort.Location = new System.Drawing.Point(6, 20);
            this.NUD_ServerPort.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.NUD_ServerPort.Name = "NUD_ServerPort";
            this.NUD_ServerPort.Size = new System.Drawing.Size(112, 20);
            this.NUD_ServerPort.TabIndex = 1;
            this.NUD_ServerPort.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NUD_ServerPort.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txtMessaggio);
            this.groupBox3.Location = new System.Drawing.Point(12, 72);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(257, 93);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "MESSAGGIO";
            // 
            // txtMessaggio
            // 
            this.txtMessaggio.Location = new System.Drawing.Point(6, 19);
            this.txtMessaggio.Name = "txtMessaggio";
            this.txtMessaggio.Size = new System.Drawing.Size(234, 64);
            this.txtMessaggio.TabIndex = 2;
            this.txtMessaggio.Text = "";
            // 
            // btnInvia
            // 
            this.btnInvia.Location = new System.Drawing.Point(98, 171);
            this.btnInvia.Name = "btnInvia";
            this.btnInvia.Size = new System.Drawing.Size(75, 39);
            this.btnInvia.TabIndex = 3;
            this.btnInvia.Text = "INVIA";
            this.btnInvia.UseVisualStyleBackColor = true;
            this.btnInvia.Click += new System.EventHandler(this.btnInvia_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(282, 222);
            this.Controls.Add(this.btnInvia);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.NUD_ServerPort)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtServerIP;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown NUD_ServerPort;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.RichTextBox txtMessaggio;
        private System.Windows.Forms.Button btnInvia;
    }
}

