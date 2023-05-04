using System;
using System.Collections.Generic;
using System.Linq;
using System.Management.Instrumentation;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace _01___SocketUDP_Server.Classi
{
    public class ClsUDPServer
    {
        private Socket socketID; // socket lato server
        private EndPoint endPointServer;
        private EndPoint endPointClient;

        public ClsUDPServer(IPAddress ip, int port)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            endPointServer = new IPEndPoint(ip, port);
        }
    }
}
