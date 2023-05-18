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

namespace _02___Tris
{
    public partial class frmTris : Form
    {
        ClsUDPServer server;
        ClsUDPClient client;
        ClsMessage clsMsg;
        public frmTris()
        {
            InitializeComponent();
            ClsAddress.cercaIP();
            cmbIp.DataSource = ClsAddress.ipList;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            server = new ClsUDPServer((IPAddress)cmbIp.SelectedItem, Convert.ToInt32(NUD_LocPort.Value));
            // gestione pulsanti
            btnStart.Enabled = false;
            btnStop.Enabled = true;
            // prima di avviare server bisogna elaborare i dati ricevuti
            server.datiRicevutiEvent += mossaAvversario;
            // avvia server
            server.avvia();
        }
        private void btnStop_Click(object sender, EventArgs e)
        {
            server.chiudi();
            // gestione pulsanti
            btnStart.Enabled = true;
            btnStop.Enabled = false;
        }
        private void mossaAvversario(ClsMessage infoAvv)
        {
            BeginInvoke((MethodInvoker)delegate () // AVVIO UN ALTRO THREAD
            {
                // prendo coordinate (per farle visualizzare al giocatore)
                // Messaggio = ij
                int i, j;
                i = Convert.ToInt32(infoAvv.Messaggio.Substring(0, 1));
                j = Convert.ToInt32(infoAvv.Messaggio.Substring(1, 1));

                Controls["btn" + i.ToString() + j.ToString()].Text = "O";
                Controls["btn" + i.ToString() + j.ToString()].ForeColor = Color.Red;
            });
        }

        private void btnTrasmettiMossa_Click(object sender, EventArgs e)
        {
            // essendo la procedura comune per tutti i buttons, prendo il button corretto
            Button btn = (Button)sender;
            // prendo le coordinate del button (btnij)
            int i, j;
            i = Convert.ToInt32(btn.Name.Substring(3, 1));
            j = Convert.ToInt32(btn.Name.Substring(4));
            
            clsMsg = new ClsMessage();
            clsMsg.Messaggio = i.ToString() + j.ToString();

            client = new ClsUDPClient(IPAddress.Parse(txtAvvIp.Text), Convert.ToInt32(NUD_AvvPort.Value));
            client.invia(clsMsg);

            btn.Text = "X";
            btn.ForeColor = Color.Blue;
        }
    }
}
