namespace _02___Tris
{
    partial class frmTris
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
            this.cmbIp = new System.Windows.Forms.ComboBox();
            this.NUD_LocPort = new System.Windows.Forms.NumericUpDown();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtAvvIp = new System.Windows.Forms.TextBox();
            this.NUD_AvvPort = new System.Windows.Forms.NumericUpDown();
            this.btn00 = new System.Windows.Forms.Button();
            this.btn01 = new System.Windows.Forms.Button();
            this.btn02 = new System.Windows.Forms.Button();
            this.btn12 = new System.Windows.Forms.Button();
            this.btn11 = new System.Windows.Forms.Button();
            this.btn10 = new System.Windows.Forms.Button();
            this.btn22 = new System.Windows.Forms.Button();
            this.btn21 = new System.Windows.Forms.Button();
            this.btn20 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_LocPort)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_AvvPort)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnStop);
            this.groupBox1.Controls.Add(this.btnStart);
            this.groupBox1.Controls.Add(this.NUD_LocPort);
            this.groupBox1.Controls.Add(this.cmbIp);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(252, 78);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Giocatore locale";
            // 
            // cmbIp
            // 
            this.cmbIp.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbIp.FormattingEnabled = true;
            this.cmbIp.Location = new System.Drawing.Point(6, 19);
            this.cmbIp.Name = "cmbIp";
            this.cmbIp.Size = new System.Drawing.Size(103, 21);
            this.cmbIp.TabIndex = 0;
            // 
            // NUD_LocPort
            // 
            this.NUD_LocPort.Location = new System.Drawing.Point(7, 46);
            this.NUD_LocPort.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.NUD_LocPort.Name = "NUD_LocPort";
            this.NUD_LocPort.Size = new System.Drawing.Size(102, 20);
            this.NUD_LocPort.TabIndex = 1;
            this.NUD_LocPort.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NUD_LocPort.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(115, 18);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(61, 48);
            this.btnStart.TabIndex = 2;
            this.btnStart.Text = "START";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(182, 18);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(61, 48);
            this.btnStop.TabIndex = 3;
            this.btnStop.Text = "STOP";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btn22);
            this.groupBox2.Controls.Add(this.btn21);
            this.groupBox2.Controls.Add(this.btn20);
            this.groupBox2.Controls.Add(this.btn12);
            this.groupBox2.Controls.Add(this.btn11);
            this.groupBox2.Controls.Add(this.btn10);
            this.groupBox2.Controls.Add(this.btn02);
            this.groupBox2.Controls.Add(this.btn01);
            this.groupBox2.Controls.Add(this.btn00);
            this.groupBox2.Controls.Add(this.NUD_AvvPort);
            this.groupBox2.Controls.Add(this.txtAvvIp);
            this.groupBox2.Location = new System.Drawing.Point(12, 96);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(252, 342);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Avversario";
            // 
            // txtAvvIp
            // 
            this.txtAvvIp.Location = new System.Drawing.Point(51, 19);
            this.txtAvvIp.Name = "txtAvvIp";
            this.txtAvvIp.Size = new System.Drawing.Size(155, 20);
            this.txtAvvIp.TabIndex = 0;
            this.txtAvvIp.Text = "127.0.0.1";
            this.txtAvvIp.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // NUD_AvvPort
            // 
            this.NUD_AvvPort.Location = new System.Drawing.Point(51, 45);
            this.NUD_AvvPort.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.NUD_AvvPort.Name = "NUD_AvvPort";
            this.NUD_AvvPort.Size = new System.Drawing.Size(155, 20);
            this.NUD_AvvPort.TabIndex = 4;
            this.NUD_AvvPort.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NUD_AvvPort.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // btn00
            // 
            this.btn00.Location = new System.Drawing.Point(7, 71);
            this.btn00.Name = "btn00";
            this.btn00.Size = new System.Drawing.Size(75, 75);
            this.btn00.TabIndex = 4;
            this.btn00.UseVisualStyleBackColor = true;
            this.btn00.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // btn01
            // 
            this.btn01.Location = new System.Drawing.Point(88, 71);
            this.btn01.Name = "btn01";
            this.btn01.Size = new System.Drawing.Size(75, 75);
            this.btn01.TabIndex = 5;
            this.btn01.UseVisualStyleBackColor = true;
            this.btn01.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // btn02
            // 
            this.btn02.Location = new System.Drawing.Point(169, 71);
            this.btn02.Name = "btn02";
            this.btn02.Size = new System.Drawing.Size(75, 75);
            this.btn02.TabIndex = 6;
            this.btn02.UseVisualStyleBackColor = true;
            this.btn02.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // btn12
            // 
            this.btn12.Location = new System.Drawing.Point(169, 152);
            this.btn12.Name = "btn12";
            this.btn12.Size = new System.Drawing.Size(75, 75);
            this.btn12.TabIndex = 9;
            this.btn12.UseVisualStyleBackColor = true;
            this.btn12.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // btn11
            // 
            this.btn11.Location = new System.Drawing.Point(88, 152);
            this.btn11.Name = "btn11";
            this.btn11.Size = new System.Drawing.Size(75, 75);
            this.btn11.TabIndex = 8;
            this.btn11.UseVisualStyleBackColor = true;
            this.btn11.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // btn10
            // 
            this.btn10.Location = new System.Drawing.Point(7, 152);
            this.btn10.Name = "btn10";
            this.btn10.Size = new System.Drawing.Size(75, 75);
            this.btn10.TabIndex = 7;
            this.btn10.UseVisualStyleBackColor = true;
            this.btn10.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // btn22
            // 
            this.btn22.Location = new System.Drawing.Point(169, 233);
            this.btn22.Name = "btn22";
            this.btn22.Size = new System.Drawing.Size(75, 75);
            this.btn22.TabIndex = 12;
            this.btn22.UseVisualStyleBackColor = true;
            this.btn22.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // btn21
            // 
            this.btn21.Location = new System.Drawing.Point(88, 233);
            this.btn21.Name = "btn21";
            this.btn21.Size = new System.Drawing.Size(75, 75);
            this.btn21.TabIndex = 11;
            this.btn21.UseVisualStyleBackColor = true;
            this.btn21.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // btn20
            // 
            this.btn20.Location = new System.Drawing.Point(7, 233);
            this.btn20.Name = "btn20";
            this.btn20.Size = new System.Drawing.Size(75, 75);
            this.btn20.TabIndex = 10;
            this.btn20.UseVisualStyleBackColor = true;
            this.btn20.Click += new System.EventHandler(this.btnTrasmettiMossa_Click);
            // 
            // frmTris
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "frmTris";
            this.Text = "Tris";
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.NUD_LocPort)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_AvvPort)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.NumericUpDown NUD_LocPort;
        private System.Windows.Forms.ComboBox cmbIp;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown NUD_AvvPort;
        private System.Windows.Forms.TextBox txtAvvIp;
        private System.Windows.Forms.Button btn22;
        private System.Windows.Forms.Button btn21;
        private System.Windows.Forms.Button btn20;
        private System.Windows.Forms.Button btn12;
        private System.Windows.Forms.Button btn11;
        private System.Windows.Forms.Button btn10;
        private System.Windows.Forms.Button btn02;
        private System.Windows.Forms.Button btn01;
        private System.Windows.Forms.Button btn00;
    }
}

