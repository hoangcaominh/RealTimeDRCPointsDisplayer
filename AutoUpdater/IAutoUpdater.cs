using System;
using System.Reflection;
using System.Drawing;
using System.Windows.Forms;

namespace AutoUpdater
{
    public interface IAutoUpdater
    {
        Version ApplicationVersion { get; }
        Assembly ApplicationAssembly { get; }
        Icon ApplicationIcon { get; }
        Uri UpdateInfoLocation { get; }
        Form Context { get; }
    }
}
