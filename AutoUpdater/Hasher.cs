using System.IO;
using System.Text;
using System.Security.Cryptography;

namespace AutoUpdater
{
    internal enum HashType
    {
        MD5,
        SHA1,
        SHA256,
        SHA512
    }

    internal static class Hasher
    {
        internal static string HashFile(string filePath, HashType hashType)
        {
            string hash;
            using (FileStream fs = new FileStream(filePath, FileMode.Open))
            {
                switch (hashType)
                {
                    case HashType.MD5:
                        hash = MakeHashString(MD5.Create().ComputeHash(fs));
                        break;
                    case HashType.SHA1:
                        hash = MakeHashString(SHA1.Create().ComputeHash(fs));
                        break;
                    case HashType.SHA256:
                        hash = MakeHashString(SHA256.Create().ComputeHash(fs));
                        break;
                    case HashType.SHA512:
                        hash = MakeHashString(SHA512.Create().ComputeHash(fs));
                        break;
                    default:
                        hash = "";
                        break;
                }
            }
            return hash;
        }

        private static string MakeHashString(byte[] hash)
        {
            StringBuilder s = new StringBuilder(hash.Length * 2);

            foreach (byte b in hash)
                s.Append(b.ToString("X2").ToLower());

            return s.ToString();
        }
    }
}
