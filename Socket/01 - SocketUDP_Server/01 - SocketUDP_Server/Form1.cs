using _01___SocketUDP_Server.Classi;
using System;
using System.Net;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using _01___SocketUDP.Classi;

namespace _01___SocketUDP_Server
{
    public partial class Form1 : Form
    {
        ClsUDPServer clsServer;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ClsAddress.CercaIP(); // trova gli IP disponibili
            cmbIP.DataSource = ClsAddress.ipList; // carico la ComboBox

            dgv.ColumnCount = 3;
            dgv.Columns[0].HeaderText = "IP";
            dgv.Columns[1].HeaderText = "PORT";
            dgv.Columns[2].HeaderText = "MESSAGGIO";
            dgv.RowHeadersVisible = false;
        }

        private void btnAvvia_Click(object sender, EventArgs e)
        {
            clsServer = new ClsUDPServer(IPAddress.Parse(cmbIP.Text), Convert.ToInt32(NUD_Port.Value));
            clsServer.datiRicevutiEvent += stampaDatiRicevuti;
            clsServer.Avvia();

            btnTermina.Enabled = true;
            btnAvvia.Enabled = false;
        }

        private void stampaDatiRicevuti(ClsMessage clsMsg)
        {
            BeginInvoke((MethodInvoker)delegate ()
            {
                dgv.Rows.Add(clsMsg.Ip, clsMsg.Port, clsMsg.Messaggio);
            });
        }

        private void btnTermina_Click(object sender, EventArgs e)
        {
            clsServer.Termina(); // non c'è bisogno di istanziare la classe

            btnTermina.Enabled = false;
            btnAvvia.Enabled = true;
        }

        private void btnPulisci_Click(object sender, EventArgs e)
        {
            dgv.Rows.Clear();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (btnAvvia.Enabled)
                btnTermina_Click(sender, e);
        }
    }
}
