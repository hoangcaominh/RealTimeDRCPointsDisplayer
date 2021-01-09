using System;
using System.Net;
using System.Windows.Forms;
using Newtonsoft.Json.Linq;

namespace AutoUpdater
{
    internal class AutoUpdaterConfig
    {
        internal Version Version { get; }

        internal Uri Uri { get; }

        internal string Executable { get; }

        internal string MD5 { get; }

        internal string LaunchArgs { get; }

        internal AutoUpdaterConfig(Version version, Uri uri, string executable, string md5, string launchArgs)
        {
            Version = version as Version;
            Uri = uri as Uri;
            Executable = executable as string;
            MD5 = md5 as string;
            LaunchArgs = launchArgs as string;
        }

        internal bool IsNewerVersion(Version version)
        {
            return Version > version;
        }

        internal static bool ExistsOnServer(Uri location)
        {
            if (location.ToString().StartsWith("file"))
            {
                return System.IO.File.Exists(location.LocalPath);
            }
            else
            {
                try
                {
                    HttpWebRequest req = (HttpWebRequest)WebRequest.Create(location.AbsoluteUri);
                    HttpWebResponse res = (HttpWebResponse)req.GetResponse();
                    res.Close();

                    return res.StatusCode == HttpStatusCode.OK;
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return false;
                }
            }
        }

        internal static AutoUpdaterConfig Parse(Uri location)
        {
            try
            {
                JObject json = new JObject();
                using (WebClient wc = new WebClient())
                {
                    json = JObject.Parse(wc.DownloadString(location.AbsoluteUri));
                }

                Version version = Version.Parse(json["version"].ToObject<string>());
                Uri uri = new Uri(String.Format("https://github.com/hoangcaominh/RealTimeDRCPointsDisplayer/releases/download/{0}/Live.DRC.Points.Calculator.{0}.zip", version.ToString()));
                string executable = json["executable"].ToObject<string>();
                string md5 = json["md5"].ToObject<string>();
                string launchArgs = json["launchArgs"].ToObject<string>();

                AutoUpdaterConfig ret = new AutoUpdaterConfig(version, uri, executable, md5, launchArgs);
                return ret;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return null;
            }
        }
    }
}
