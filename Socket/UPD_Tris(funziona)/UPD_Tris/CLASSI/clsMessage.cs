using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UPD_Tris.Classi
{
    public class clsMessage
    {
        private string ip, port, messaggio;

        public string Ip { get => ip; set => ip = value; }
        public string Port { get => port; set => port = value; }
        public string Messaggio { get => messaggio; set => messaggio = value; }

        public clsMessage(string ip = "", string port = "", string messaggio = "")
        {
            this.ip = ip;
            this.port = port;
            this.messaggio = messaggio;
        }

        public clsMessage(string csv, char separatore)
        {
            this.ip = (string)csv.Split(separatore)[0];
            this.port = (string)csv.Split(separatore)[1];
            this.messaggio = (string)csv.Split(separatore)[2];
        }

        public string toCsv(char separatore = ';')
        {
            return $"{this.ip}{separatore}{this.port}{separatore}{this.messaggio}";
        }
        public string[] toArray()
        {
            return new string[] { ip, port, messaggio };
        }


    }
}
