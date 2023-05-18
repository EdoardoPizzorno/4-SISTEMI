using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http.Headers;
using System.Net.Sockets;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _01_SocketUDP_Client.Classi
{
    public class ClsUDPClient
    {
        private Socket socketID;
        private EndPoint endPointServer; 

        public ClsUDPClient(IPAddress ipServer, int portServer)
        {
            socketID = new Socket(AddressFamily.InterNetwork, 
                                        SocketType.Dgram, ProtocolType.Udp);
            endPointServer = new IPEndPoint(ipServer, portServer);
        }
        public void invia(ClsMessage clsMsg)
        {
            string messaggio = clsMsg.toCsv(';');
            byte[] bufferTx; 
            
            bufferTx = Encoding.ASCII.GetBytes(messaggio);
            // Inviare pacchetto dati 
            socketID.SendTo(bufferTx, bufferTx.Length, 
                                SocketFlags.None,
                                endPointServer);
        }
    }
}
