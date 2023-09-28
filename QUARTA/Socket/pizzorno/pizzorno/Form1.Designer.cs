namespace pizzorno
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
            this.NUD = new System.Windows.Forms.NumericUpDown();
            this.btnAvvia = new System.Windows.Forms.Button();
            this.btnTermina = new System.Windows.Forms.Button();
            this.lblRisposta = new System.Windows.Forms.Label();
            this.btnMandaSecondo = new System.Windows.Forms.Button();
            this.txtServerIP = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.NUD)).BeginInit();
            this.SuspendLayout();
            // 
            // NUD
            // 
            this.NUD.Location = new System.Drawing.Point(12, 12);
            this.NUD.Name = "NUD";
            this.NUD.Size = new System.Drawing.Size(120, 20);
            this.NUD.TabIndex = 0;
            this.NUD.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.NUD.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // btnAvvia
            // 
            this.btnAvvia.Location = new System.Drawing.Point(12, 54);
            this.btnAvvia.Name = "btnAvvia";
            this.btnAvvia.Size = new System.Drawing.Size(75, 23);
            this.btnAvvia.TabIndex = 1;
            this.btnAvvia.Text = "Avvia";
            this.btnAvvia.UseVisualStyleBackColor = true;
            this.btnAvvia.Click += new System.EventHandler(this.btnAvvia_Click);
            // 
            // btnTermina
            // 
            this.btnTermina.Location = new System.Drawing.Point(108, 54);
            this.btnTermina.Name = "btnTermina";
            this.btnTermina.Size = new System.Drawing.Size(75, 23);
            this.btnTermina.TabIndex = 2;
            this.btnTermina.Text = "Termina";
            this.btnTermina.UseVisualStyleBackColor = true;
            this.btnTermina.Click += new System.EventHandler(this.btnTermina_Click);
            // 
            // lblRisposta
            // 
            this.lblRisposta.AutoSize = true;
            this.lblRisposta.Location = new System.Drawing.Point(285, 59);
            this.lblRisposta.Name = "lblRisposta";
            this.lblRisposta.Size = new System.Drawing.Size(48, 13);
            this.lblRisposta.TabIndex = 3;
            this.lblRisposta.Text = "Risposta";
            // 
            // btnMandaSecondo
            // 
            this.btnMandaSecondo.Enabled = false;
            this.btnMandaSecondo.Location = new System.Drawing.Point(12, 83);
            this.btnMandaSecondo.Name = "btnMandaSecondo";
            this.btnMandaSecondo.Size = new System.Drawing.Size(97, 23);
            this.btnMandaSecondo.TabIndex = 5;
            this.btnMandaSecondo.Text = "Manda secondo";
            this.btnMandaSecondo.UseVisualStyleBackColor = true;
            this.btnMandaSecondo.Click += new System.EventHandler(this.btnMandaSecondo_Click);
            // 
            // txtServerIP
            // 
            this.txtServerIP.Location = new System.Drawing.Point(155, 10);
            this.txtServerIP.Name = "txtServerIP";
            this.txtServerIP.Size = new System.Drawing.Size(100, 20);
            this.txtServerIP.TabIndex = 7;
            this.txtServerIP.Text = "10.0.5.128";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(510, 147);
            this.Controls.Add(this.txtServerIP);
            this.Controls.Add(this.btnMandaSecondo);
            this.Controls.Add(this.lblRisposta);
            this.Controls.Add(this.btnTermina);
            this.Controls.Add(this.btnAvvia);
            this.Controls.Add(this.NUD);
            this.Name = "Form1";
            this.Text = "Pizzorno";
            ((System.ComponentModel.ISupportInitialize)(this.NUD)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown NUD;
        private System.Windows.Forms.Button btnAvvia;
        private System.Windows.Forms.Button btnTermina;
        private System.Windows.Forms.Label lblRisposta;
        private System.Windows.Forms.Button btnMandaSecondo;
        private System.Windows.Forms.TextBox txtServerIP;
    }
}

