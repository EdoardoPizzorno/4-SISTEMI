using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace _01_SocketUDP_Server.Classi
{
    public class clsAddress
    {
        public static List<IPAddress> ipList = new List<IPAddress>();

        public clsAddress() { }
        public static void cercaIP()
        {
            IPHostEntry hostInfo = new IPHostEntry();
            ipList.Add(IPAddress.Loopback);
            
            hostInfo = Dns.GetHostEntry(Dns.GetHostName());
            foreach(IPAddress ip in hostInfo.AddressList)
                if(ip.AddressFamily == System.Net.Sockets.AddressFamily.InterNetwork)
                    ipList.Add(ip);
        

        }
    }
}
