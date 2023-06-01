using pizzorno.Classi;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace pizzorno
{
    public partial class Form1 : Form
    {
        const string cognome = "Pizzorno";
        const string mio_Ip = "10.0.101.19";

        ClsServerUDP clsServerUDP;
        ClsClientUDP clsUDPClient;

        public Form1()
        {
            //ClsAddress.findIP();
            //txtServerIP.DataSource = ClsAddress.ipList;
            InitializeComponent();
        }

        private void btnAvvia_Click(object sender, EventArgs e)
        {
            btnAvvia.Enabled = false;
            btnTermina.Enabled = true;
            btnMandaSecondo.Enabled = true;

            clsUDPClient = new ClsClientUDP(IPAddress.Parse(txtServerIP.Text), 1234);
            ClsMessage clsMsg = new ClsMessage();
            clsMsg.Messaggio = $"A|{cognome}|EOT";

            clsUDPClient.invia(clsMsg);

            clsServerUDP = new ClsServerUDP(IPAddress.Parse(mio_Ip), 4321); // ho messo staticamente l'IP della mia macchina
            clsServerUDP.avvia();
            clsServerUDP.datiRicevutiEvent += riceviDati;
        }

        private void btnTermina_Click(object sender, EventArgs e)
        {
            btnAvvia.Enabled = true;
            btnMandaSecondo.Enabled = true;
            btnTermina.Enabled = false;

            clsServerUDP.chiudi();
        }

        private void btnMandaSecondo_Click(object sender, EventArgs e)
        {
            btnAvvia.Enabled = false;
            btnTermina.Enabled = true;
            btnMandaSecondo.Enabled = true;

            ClsMessage clsMsg = new ClsMessage();
            clsMsg.Messaggio = $"Z|{cognome}|{NUD.Value}|EOT";
            clsUDPClient.invia(clsMsg);
            
            clsServerUDP.datiRicevutiEvent += riceviDati2;
        }
        private void riceviDati(ClsMessage clsMsg)
        {
            BeginInvoke((MethodInvoker)delegate ()
            {
                lblRisposta.Text = clsMsg.Messaggio;
            });
        }

        private void riceviDati2(ClsMessage clsMsg)
        {
            BeginInvoke((MethodInvoker)delegate ()
            {
                lblRisposta.Text = clsMsg.Messaggio;
                MessageBox.Show(clsMsg.Messaggio);
                Random rnd = new Random();

                string strValori = clsMsg.Messaggio.Split('|')[1];
                int[] valoriServer = new int[Convert.ToInt32(NUD.Value)];
                int[] valoriClient = new int[Convert.ToInt32(NUD.Value)];
                int sommaServer = 0;
                int sommaClient = 0;

                string output = "";
                //MessageBox.Show($"LEnght: {strValori.Split(',').Length}");
                if(strValori.Split(',').Length > 2)
                {
                    for (int i = 0; i < strValori.Split(',').Length; i++)
                    {
                        valoriServer[i] = Convert.ToInt32(strValori.Split(',')[i]);
                        valoriClient[i] = rnd.Next(0, 10);
                    }
                } else
                {
                    valoriServer[0] = Convert.ToInt32(strValori[0]);
                    valoriClient[0] = rnd.Next(0, 10);
                }
                for (int i = 0; i < valoriServer.Length; i++)
                {
                    sommaServer += valoriServer[i];
                    sommaClient += valoriClient[i];
                }

                if (sommaServer > sommaClient) 
                    output = $"C|{cognome}|V|EOT";
                 else if (sommaServer == sommaClient)
                    output = $"C|{cognome}|P|EOT";
                 else output = $"C|{cognome}|S|EOT";
                
                clsMsg.Messaggio = output;
                clsUDPClient.invia(clsMsg);
            });
        }
    }
}
