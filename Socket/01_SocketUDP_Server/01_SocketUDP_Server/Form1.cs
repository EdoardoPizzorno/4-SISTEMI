using _01_SocketUDP_Server.Classi;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _01_SocketUDP_Server
{
    public partial class Form1 : Form
    {
        clsUDPServer clsServer;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            clsAddress.cercaIP();
            cmdIP.DataSource = clsAddress.ipList;
            btnStop.Enabled = false;

            dgv.ColumnCount = 3;
            dgv.Columns[0].HeaderText = "IP";
            dgv.Columns[1].HeaderText = "PORT";
            dgv.Columns[2].HeaderText = "MESSAGGIO";
            dgv.RowHeadersVisible = false;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            clsServer = new clsUDPServer((IPAddress)cmdIP.SelectedItem, Convert.ToInt32(nudServerPort.Value));
            clsServer.datiRicevutiEvent += stampaDatiRicevuti;
            clsServer.start();
            btnStart.Enabled = false;
            btnStop.Enabled = true;
        }



        private void stampaDatiRicevuti(clsMessage msg)
        {
            BeginInvoke((MethodInvoker)delegate () {
                dgv.Rows.Add(msg.toArray());
            });
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            clsServer.stop();
            btnStart.Enabled = true;
            btnStop.Enabled = false;
        }

        private void btnPulisci_Click(object sender, EventArgs e)
        {
            dgv.Rows.Clear();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if(!btnStart.Enabled)
                btnStop_Click(sender, e);            
        }
    }
}
