namespace _01___SocketUDP_Server
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
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.NUD_Port = new System.Windows.Forms.NumericUpDown();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.cmbIP = new System.Windows.Forms.ComboBox();
            this.btnTermina = new System.Windows.Forms.Button();
            this.btnAvvia = new System.Windows.Forms.Button();
            this.dgv = new System.Windows.Forms.DataGridView();
            this.btnPulisci = new System.Windows.Forms.Button();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Port)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.NUD_Port);
            this.groupBox2.Location = new System.Drawing.Point(145, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(124, 54);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "PORT";
            // 
            // NUD_Port
            // 
            this.NUD_Port.Location = new System.Drawing.Point(6, 20);
            this.NUD_Port.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.NUD_Port.Name = "NUD_Port";
            this.NUD_Port.Size = new System.Drawing.Size(112, 20);
            this.NUD_Port.TabIndex = 1;
            this.NUD_Port.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NUD_Port.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.cmbIP);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(127, 54);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "IP";
            // 
            // cmbIP
            // 
            this.cmbIP.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbIP.FormattingEnabled = true;
            this.cmbIP.Location = new System.Drawing.Point(13, 20);
            this.cmbIP.Name = "cmbIP";
            this.cmbIP.Size = new System.Drawing.Size(100, 21);
            this.cmbIP.TabIndex = 0;
            // 
            // btnTermina
            // 
            this.btnTermina.Location = new System.Drawing.Point(113, 231);
            this.btnTermina.Name = "btnTermina";
            this.btnTermina.Size = new System.Drawing.Size(75, 39);
            this.btnTermina.TabIndex = 4;
            this.btnTermina.Text = "TERMINA";
            this.btnTermina.UseVisualStyleBackColor = true;
            // 
            // btnAvvia
            // 
            this.btnAvvia.Location = new System.Drawing.Point(194, 231);
            this.btnAvvia.Name = "btnAvvia";
            this.btnAvvia.Size = new System.Drawing.Size(75, 39);
            this.btnAvvia.TabIndex = 4;
            this.btnAvvia.Text = "AVVIA";
            this.btnAvvia.UseVisualStyleBackColor = true;
            // 
            // dgv
            // 
            this.dgv.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgv.Location = new System.Drawing.Point(12, 72);
            this.dgv.Name = "dgv";
            this.dgv.Size = new System.Drawing.Size(257, 150);
            this.dgv.TabIndex = 5;
            // 
            // btnPulisci
            // 
            this.btnPulisci.Location = new System.Drawing.Point(12, 228);
            this.btnPulisci.Name = "btnPulisci";
            this.btnPulisci.Size = new System.Drawing.Size(51, 20);
            this.btnPulisci.TabIndex = 6;
            this.btnPulisci.Text = "Pulisci";
            this.btnPulisci.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 282);
            this.Controls.Add(this.btnPulisci);
            this.Controls.Add(this.dgv);
            this.Controls.Add(this.btnAvvia);
            this.Controls.Add(this.btnTermina);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Port)).EndInit();
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown NUD_Port;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox cmbIP;
        private System.Windows.Forms.Button btnTermina;
        private System.Windows.Forms.Button btnAvvia;
        private System.Windows.Forms.DataGridView dgv;
        private System.Windows.Forms.Button btnPulisci;
    }
}

