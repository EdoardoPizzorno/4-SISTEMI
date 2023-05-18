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
using UPD_Tris.Classi;
using UPD_Tris.CLASSI;

namespace UPD_Tris
{
    public partial class Form1 : Form
    {
        clsUDPServer server;
        clsUDPClient client;
        clsMessage clsMsg;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            clsAddress.cercaIP();
            cmbIP.DataSource = clsAddress.ipList;
            btnStop.Enabled = !btnStart.Enabled;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            server = new clsUDPServer( (IPAddress)cmbIP.SelectedItem, Convert.ToInt32(nudPort.Value));
            server.datiRicevutiEvent += posizionaMossaAvversario;
            server.start();

            btnStart.Enabled = !btnStop.Enabled;
            btnStop.Enabled = !btnStart.Enabled;

        }

        private void posizionaMossaAvversario(clsMessage infoAvversario)
        {
            BeginInvoke((MethodInvoker)delegate ()
            {
                int i, j;

                i = Convert.ToInt32(infoAvversario.Messaggio.Substring(0, 1));
                j = Convert.ToInt32(infoAvversario.Messaggio.Substring(1, 1));

                Controls[$"btn{i}{j}"].Text = "O";
                Controls[$"btn{i}{j}"].ForeColor = Color.Red;
            });
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            server.stop();

            btnStart.Enabled = btnStop.Enabled;
            btnStop.Enabled = !btnStart.Enabled;
        }

        private void btnTrasmettiMossa(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            int i = Convert.ToInt32(btn.Name.Substring(3, 1));
            int j = Convert.ToInt32(btn.Name.Substring(4));

            clsMsg = new clsMessage();
            clsMsg.Messaggio = Convert.ToString(i) + Convert.ToString(j);

            client = new clsUDPClient(IPAddress.Parse(txtAvversarioIP.Text), Convert.ToInt32(nudAvversario.Value));
            btn.Text = "X";
            btn.ForeColor = Color.Blue;

            client.Invia(clsMsg);
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            foreach (Control btn in Controls)
            {
                if (btn is Button)
                {
                    if (btn.Text == "X" || btn.Text == "O")
                        btn.Text = "";
                }
            }
        }
    }
}
