using _01___SocketUDP.Classi;
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

namespace _01___SocketUDP
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnInvia_Click(object sender, EventArgs e)
        {
            ClsUDPClient clsUDPClient = new ClsUDPClient(IPAddress.Parse(txtServerIP.Text), Convert.ToInt32(NUD_ServerPort.Value));

            ClsMessage clsMsg = new ClsMessage();
            clsMsg.Messaggio = txtMessaggio.Text;

            clsUDPClient.Invia(clsMsg);
        }
    }
}
