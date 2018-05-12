using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int[] letters = new int[26];
            for (int i = 0; i < 26; i++)
                letters[i] = 0;
            textBox2.Text = "";
            char[] text = textBox1.Text.ToCharArray();
            foreach (char ch in text)
            {
                if (ch >= 'A' && ch <= 'Z')
                    letters[ch - 65]++;
                if (ch >= 'a' && ch <= 'z')
                    letters[ch - 97]++;
            }
            for (int i = 0; i < 26; i++)
                textBox2.Text += letters[i].ToString() + '\t';
            textBox1.Text = "";
        }
    }
}
