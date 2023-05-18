namespace UPD_Tris
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
            this.btnStop = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.nudPort = new System.Windows.Forms.NumericUpDown();
            this.cmbIP = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.nudAvversario = new System.Windows.Forms.NumericUpDown();
            this.txtAvversarioIP = new System.Windows.Forms.TextBox();
            this.btn00 = new System.Windows.Forms.Button();
            this.btn22 = new System.Windows.Forms.Button();
            this.btn21 = new System.Windows.Forms.Button();
            this.btn20 = new System.Windows.Forms.Button();
            this.btn12 = new System.Windows.Forms.Button();
            this.btn11 = new System.Windows.Forms.Button();
            this.btn10 = new System.Windows.Forms.Button();
            this.btn02 = new System.Windows.Forms.Button();
            this.bnt01 = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPort)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudAvversario)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnClear);
            this.groupBox1.Controls.Add(this.btnStop);
            this.groupBox1.Controls.Add(this.btnStart);
            this.groupBox1.Controls.Add(this.nudPort);
            this.groupBox1.Controls.Add(this.cmbIP);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(373, 116);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Giocatore Locale";
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(231, 45);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(127, 27);
            this.btnStop.TabIndex = 3;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(0, 46);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(183, 27);
            this.btnStart.TabIndex = 2;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // nudPort
            // 
            this.nudPort.Location = new System.Drawing.Point(231, 19);
            this.nudPort.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudPort.Minimum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudPort.Name = "nudPort";
            this.nudPort.Size = new System.Drawing.Size(127, 20);
            this.nudPort.TabIndex = 1;
            this.nudPort.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // cmbIP
            // 
            this.cmbIP.FormattingEnabled = true;
            this.cmbIP.Location = new System.Drawing.Point(6, 19);
            this.cmbIP.Name = "cmbIP";
            this.cmbIP.Size = new System.Drawing.Size(177, 21);
            this.cmbIP.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.nudAvversario);
            this.groupBox2.Controls.Add(this.txtAvversarioIP);
            this.groupBox2.Location = new System.Drawing.Point(12, 134);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(373, 70);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Avversario";
            // 
            // nudAvversario
            // 
            this.nudAvversario.Location = new System.Drawing.Point(231, 20);
            this.nudAvversario.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudAvversario.Minimum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudAvversario.Name = "nudAvversario";
            this.nudAvversario.Size = new System.Drawing.Size(127, 20);
            this.nudAvversario.TabIndex = 4;
            this.nudAvversario.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // txtAvversarioIP
            // 
            this.txtAvversarioIP.Location = new System.Drawing.Point(6, 19);
            this.txtAvversarioIP.Name = "txtAvversarioIP";
            this.txtAvversarioIP.Size = new System.Drawing.Size(177, 20);
            this.txtAvversarioIP.TabIndex = 0;
            this.txtAvversarioIP.Text = "127.0.0.1";
            // 
            // btn00
            // 
            this.btn00.Location = new System.Drawing.Point(420, 12);
            this.btn00.Name = "btn00";
            this.btn00.Size = new System.Drawing.Size(60, 60);
            this.btn00.TabIndex = 4;
            this.btn00.UseVisualStyleBackColor = true;
            this.btn00.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // btn22
            // 
            this.btn22.Location = new System.Drawing.Point(552, 144);
            this.btn22.Name = "btn22";
            this.btn22.Size = new System.Drawing.Size(60, 60);
            this.btn22.TabIndex = 5;
            this.btn22.UseVisualStyleBackColor = true;
            this.btn22.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // btn21
            // 
            this.btn21.Location = new System.Drawing.Point(486, 144);
            this.btn21.Name = "btn21";
            this.btn21.Size = new System.Drawing.Size(60, 60);
            this.btn21.TabIndex = 6;
            this.btn21.UseVisualStyleBackColor = true;
            this.btn21.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // btn20
            // 
            this.btn20.Location = new System.Drawing.Point(420, 144);
            this.btn20.Name = "btn20";
            this.btn20.Size = new System.Drawing.Size(60, 60);
            this.btn20.TabIndex = 7;
            this.btn20.UseVisualStyleBackColor = true;
            this.btn20.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // btn12
            // 
            this.btn12.Location = new System.Drawing.Point(552, 78);
            this.btn12.Name = "btn12";
            this.btn12.Size = new System.Drawing.Size(60, 60);
            this.btn12.TabIndex = 8;
            this.btn12.UseVisualStyleBackColor = true;
            this.btn12.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // btn11
            // 
            this.btn11.Location = new System.Drawing.Point(486, 78);
            this.btn11.Name = "btn11";
            this.btn11.Size = new System.Drawing.Size(60, 60);
            this.btn11.TabIndex = 9;
            this.btn11.UseVisualStyleBackColor = true;
            this.btn11.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // btn10
            // 
            this.btn10.Location = new System.Drawing.Point(420, 78);
            this.btn10.Name = "btn10";
            this.btn10.Size = new System.Drawing.Size(60, 60);
            this.btn10.TabIndex = 10;
            this.btn10.UseVisualStyleBackColor = true;
            this.btn10.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // btn02
            // 
            this.btn02.Location = new System.Drawing.Point(552, 12);
            this.btn02.Name = "btn02";
            this.btn02.Size = new System.Drawing.Size(60, 60);
            this.btn02.TabIndex = 11;
            this.btn02.UseVisualStyleBackColor = true;
            this.btn02.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // bnt01
            // 
            this.bnt01.Location = new System.Drawing.Point(486, 12);
            this.bnt01.Name = "bnt01";
            this.bnt01.Size = new System.Drawing.Size(60, 60);
            this.bnt01.TabIndex = 12;
            this.bnt01.UseVisualStyleBackColor = true;
            this.bnt01.Click += new System.EventHandler(this.btnTrasmettiMossa);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(98, 83);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(183, 27);
            this.btnClear.TabIndex = 4;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(650, 253);
            this.Controls.Add(this.bnt01);
            this.Controls.Add(this.btn02);
            this.Controls.Add(this.btn10);
            this.Controls.Add(this.btn11);
            this.Controls.Add(this.btn12);
            this.Controls.Add(this.btn20);
            this.Controls.Add(this.btn21);
            this.Controls.Add(this.btn22);
            this.Controls.Add(this.btn00);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.nudPort)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudAvversario)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.NumericUpDown nudPort;
        private System.Windows.Forms.ComboBox cmbIP;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown nudAvversario;
        private System.Windows.Forms.TextBox txtAvversarioIP;
        private System.Windows.Forms.Button btn00;
        private System.Windows.Forms.Button btn22;
        private System.Windows.Forms.Button btn21;
        private System.Windows.Forms.Button btn20;
        private System.Windows.Forms.Button btn12;
        private System.Windows.Forms.Button btn11;
        private System.Windows.Forms.Button btn10;
        private System.Windows.Forms.Button btn02;
        private System.Windows.Forms.Button bnt01;
        private System.Windows.Forms.Button btnClear;
    }
}

