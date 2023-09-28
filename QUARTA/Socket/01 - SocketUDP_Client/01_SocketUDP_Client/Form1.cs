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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnInvia_Click(object sender, EventArgs e)
        {
            clsUDPClient clsUDPClient;
            clsMessage clsMsg;

            clsUDPClient = new clsUDPClient(IPAddress.Parse(txtServerIP.Text), Convert.ToInt32(nudServerPort.Value));
            clsMsg = new clsMessage();

            clsMsg.Messaggio = txtMsg.Text;

            clsUDPClient.Invia(clsMsg);

        }
    }
}
