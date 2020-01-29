using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using System.IO;
using System.Net;

namespace AutoUpdater
{
    internal partial class AutoUpdaterDownloadForm : Form
    {
        private readonly WebClient webClient;
        private readonly string md5;

        internal string TempFilePath { get; }

        internal AutoUpdaterDownloadForm(Uri location, string md5, Icon programIcon)
        {
            InitializeComponent();

            if (programIcon != null)
                Icon = programIcon;

            TempFilePath = Path.GetTempFileName();
            this.md5 = md5;

            webClient = new WebClient();
            webClient.DownloadProgressChanged += new DownloadProgressChangedEventHandler(WebClient_DownloadProgressChanged);
            webClient.DownloadFileCompleted += new AsyncCompletedEventHandler(WebClient_DownloadFileCompleted);

            try { webClient.DownloadFileAsync(location, TempFilePath); }
            catch { DialogResult = DialogResult.No; Close(); }
        }

        private void WebClient_DownloadProgressChanged(object sender, DownloadProgressChangedEventArgs e)
        {
            downloadProgress.Value = e.ProgressPercentage;
            downloadInfo.Text = String.Format("{0} B / {1} B", e.BytesReceived, e.TotalBytesToReceive);
        }

        private void WebClient_DownloadFileCompleted(object sender, AsyncCompletedEventArgs e)
        {
            if (e.Error != null)
            {
                DialogResult = DialogResult.No;
                Close();
            }
            else if (e.Cancelled)
            {
                DialogResult = DialogResult.Abort;
                Close();
            }
            else
            {
                downloadInfo.Text = "Verifying Download...";
                downloadProgress.Style = ProgressBarStyle.Marquee;

                bgWorker.RunWorkerAsync(new string[] { TempFilePath, md5 });
            }
        }

        private void BgWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            string file = ((string[])e.Argument)[0];
            string md5 = ((string[])e.Argument)[1];
            
            if (Hasher.HashFile(file, HashType.MD5) != md5)
                e.Result = DialogResult.No;
            else
                e.Result = DialogResult.OK;
        }

        private void BgWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            DialogResult = (DialogResult)e.Result;
            Close();
        }

        private void AutoUpdaterDownloadForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (webClient.IsBusy)
            {
                webClient.CancelAsync();
                DialogResult = DialogResult.Abort;
            }

            if (bgWorker.IsBusy)
            {
                bgWorker.CancelAsync();
                DialogResult = DialogResult.Abort;
            }
        }
    }
}
