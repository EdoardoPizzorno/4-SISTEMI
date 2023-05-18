using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace UPD_Tris.Classi
{
    public delegate void datiRicevutiEventHandler(clsMessage msg);
    internal class clsUDPServer
    {
        private const int MAX_BYTE = 1024;

        clsMessage clsMsg;

        private Socket socketID;
        private EndPoint endPointServer;
        private EndPoint endPointClient;

        private Thread threadAscolto;
        private volatile bool threadRun = true;

        public event datiRicevutiEventHandler datiRicevutiEvent;
        public clsUDPServer(IPAddress ip, int port)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            endPointServer = new IPEndPoint(ip, port);

            socketID.Bind(endPointServer);
        }

        public void start()
        {
            if(threadAscolto == null)
            {
                threadAscolto = new Thread(new ThreadStart(ricevi));
                threadAscolto.Start();
                while (!threadAscolto.IsAlive) ;
            }
        }
        public void stop()
        {
            threadRun = false;
            socketID.Close();
        }

        private void ricevi()
        {
            int nBytesRicevuti;
            string msg;
            byte[] bufferRx;
            bufferRx = new byte[MAX_BYTE];
            endPointClient = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 6969);

            while (threadRun)
            {
                bufferRx = new byte[MAX_BYTE];
                try
                {
                    nBytesRicevuti = socketID.ReceiveFrom(bufferRx, MAX_BYTE, SocketFlags.None, ref endPointClient);
                    msg = Encoding.ASCII.GetString(bufferRx);
                    clsMsg = new clsMessage(msg, ';');
                    clsMsg.Ip = (endPointClient as IPEndPoint).Address.ToString();
                    clsMsg.Port = (endPointClient as IPEndPoint).Port.ToString();

                    datiRicevutiEvent(clsMsg);
                }
                catch (SocketException ex)
                { 
                    
                }

            }
        }
    }
}
