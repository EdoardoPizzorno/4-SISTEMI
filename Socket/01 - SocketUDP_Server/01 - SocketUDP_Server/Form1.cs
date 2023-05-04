using _01___SocketUDP_Server.Classi;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _01___SocketUDP_Server
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ClsAddress.CercaIP(); // trova gli IP disponibili
            cmbIP.DataSource = ClsAddress.ipList; // carico la ComboBox
        }
    }
}
