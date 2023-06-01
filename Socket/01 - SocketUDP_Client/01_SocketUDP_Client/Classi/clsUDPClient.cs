using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace _01_SocketUDP_Client.Classi
{
    internal class clsUDPClient
    {
        private Socket socketID;
        private EndPoint endPointServer;

        public clsUDPClient(IPAddress idServer, int portServer)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            endPointServer = new IPEndPoint(idServer, portServer);
        }

        public void Invia(clsMessage clsMsg)
        {
            string msgs = clsMsg.toCsv(';');
            byte[] bufferTx;
            
            bufferTx = Encoding.ASCII.GetBytes(msgs);

            socketID.SendTo(bufferTx, bufferTx.Length, SocketFlags.None, endPointServer);        
        }
    }
}
