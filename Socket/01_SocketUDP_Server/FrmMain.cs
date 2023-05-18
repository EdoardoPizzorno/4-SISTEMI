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
    public partial class FrmMain : Form
    {
        ClsUDPServer clsServer; 
        public FrmMain()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ClsAddress.cercaIP();
            cmbIP.DataSource = ClsAddress.ipList;

            dgv.ColumnCount = 3;
            dgv.Columns[0].HeaderText = "IP";
            dgv.Columns[1].HeaderText = "PORT";
            dgv.Columns[2].HeaderText = "MESSAGGIO";
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            clsServer = new ClsUDPServer((IPAddress)cmbIP.SelectedItem,
                                Convert.ToInt32(nudPort.Value));
            clsServer.datiRicevutiEvent += stampaDatiRicevuti;
            clsServer.avvia();

            btnStart.Enabled = false;
            btnStop.Enabled = true; 
        }

        private void stampaDatiRicevuti(ClsMessage msg)
        {
            BeginInvoke((MethodInvoker)delegate () 
            {
                 dgv.Rows.Insert(0, msg.toArray());
                // dgv.Rows.Add(msg.Ip, msg.Port, msg.Messaggio); 
            });
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            clsServer.chiudi();

            btnStart.Enabled = true;
            btnStop.Enabled = false;
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            dgv.Rows.Clear(); 
        }

        private void FrmMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!btnStart.Enabled)
                btnStop_Click(sender, e);
        }
    }
}
