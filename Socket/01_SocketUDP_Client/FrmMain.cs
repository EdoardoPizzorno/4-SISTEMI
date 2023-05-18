using _01_SocketUDP_Client.Classi;
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

namespace _01_SocketUDP_Client
{
    public partial class FrmMain : Form
    {
        public FrmMain()
        {
            InitializeComponent();
        }

        private void btnInvia_Click(object sender, EventArgs e)
        {
            ClsUDPClient clsUDPClient;
            ClsMessage clsMsg;

            clsUDPClient = new ClsUDPClient(IPAddress.Parse(txtServerIP.Text),
                                            Convert.ToInt32(nudServerPort.Value)); 
            clsMsg = new ClsMessage();

            clsMsg.Messaggio = txtMsg.Text;

            clsUDPClient.invia(clsMsg); 
        }
    }
}
