using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace _01___SocketUDP.Classi
{
    public class ClsUDPClient
    {
        private Socket socketID; // rappresenta l'identificativo client
        private EndPoint endPointServer; // identifica la destinazione (end device)
        
        public ClsUDPClient(IPAddress ipServer, int portServer)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp); // InterNetwork = IPv4
            endPointServer = new IPEndPoint(ipServer, portServer);
        }

        public void Invia(ClsMessage clsMsg)
        {
            string messaggio = clsMsg.toCsv(';');
            byte[] bufferTx;
            bufferTx = Encoding.ASCII.GetBytes(messaggio); // ottengo un vettore di byte
            // inviare pacchetto dati
            socketID.SendTo(bufferTx, bufferTx.Length, SocketFlags.None, endPointServer);
        }
    }
}
