using _01___SocketUDP.Classi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Management.Instrumentation;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Remoting.Channels;
using System.Security.Policy;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _01___SocketUDP_Server.Classi
{
    public delegate void datiRicevutiEventHandler(ClsMessage msg);
    public class ClsUDPServer
    {
        private const int MAX_BYTE = 1024;
        private Socket socketID; // socket lato server
        private EndPoint endPointServer;
        private EndPoint endPointClient;

        public Thread threadAscolto;
        public volatile bool threadRun = true; // per gestire Avvio/Stop

        public event datiRicevutiEventHandler datiRicevutiEvent;

        public ClsUDPServer(IPAddress ip, int port)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            endPointServer = new IPEndPoint(ip, port);
            // Bind
            socketID.Bind(endPointServer); // apertura canale di comunicazione
        }

        public void Ricevi()
        {
            int nBytesRicevuti = 0;
            string msg = "";
            byte[] bufferRx = new byte[MAX_BYTE];
            ClsMessage clsMsg;

            endPointClient = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 5555);

            while (threadRun) // fino a quando non clicco btnTermina (in cui c'è threadRun=false)
            {
                try
                {
                    nBytesRicevuti = socketID.ReceiveFrom(bufferRx, MAX_BYTE, SocketFlags.None, ref endPointClient); // !!! endPointClient PER REFERENZA
                    msg = Encoding.ASCII.GetString(bufferRx); // converto da binario a stringa
                    clsMsg = new ClsMessage(msg, ';');

                    clsMsg.Ip = (endPointClient as IPEndPoint).Address.ToString();
                    clsMsg.Port = (endPointClient as IPEndPoint).Port.ToString();
                    
                    datiRicevutiEvent(clsMsg);
                }
                catch (SocketException ex)
                {
                    throw ex;
                }
            }
        }

        public void Avvia()
        {
            if (threadAscolto == null) // se non è ancora istanziato lo istanzio
            {
                threadAscolto = new Thread(new ThreadStart(Ricevi));
                threadAscolto.Start();

                while (!threadAscolto.IsAlive) ;
            }
        }

        public void Termina()
        {
            threadRun = false;
            socketID.Close(); // disattivo il canale di comunicazione [IMPORTANTE]
        }
    }
}
