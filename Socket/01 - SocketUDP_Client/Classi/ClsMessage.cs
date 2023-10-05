using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_SocketUDP_Client.Classi
{
    public class ClsMessage
    {
        private string ip, port, messaggio;

        public string Ip { get => ip; set => ip = value; }
        public string Port { get => port; set => port = value; }
        public string Messaggio { get => messaggio; set => messaggio = value; }

        public ClsMessage(string _ip = "", string _port = "", string _msg = "")
        {
            this.ip = _ip;
            this.port = _port;
            this.messaggio = _msg; 
        }
        public ClsMessage(string csv, char separatore)
        { // ip;port;msg
            this.ip = csv.Split(separatore)[0];
            this.port = csv.Split(separatore)[1]; 
            this.messaggio = csv.Split(separatore)[2];
        }
        
        public string toCsv(char separatore = ';')
        {
            return ip + separatore + port + separatore + messaggio; 
        }
        public string[] toArray()
        {
            return new string[] { ip, port, messaggio };
        }
    }
}
