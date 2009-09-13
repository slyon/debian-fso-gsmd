/* fsobasics-2.0.vapi generated by valac, do not modify. */

[CCode (cprefix = "FsoFramework", lower_case_cprefix = "fso_framework_")]
namespace FsoFramework {
	[CCode (cprefix = "FsoFrameworkAsync", lower_case_cprefix = "fso_framework_async_")]
	namespace Async {
		[Compact]
		[CCode (cheader_filename = "fsobasics.h")]
		public class EventFd {
			public GLib.IOChannel channel;
			public uint watch;
			public EventFd (uint initvalue, GLib.IOFunc callback);
			public uint read ();
			public void write (int count);
		}
	}
	[CCode (cprefix = "FsoFrameworkFileHandling", lower_case_cprefix = "fso_framework_file_handling_")]
	namespace FileHandling {
		[CCode (cheader_filename = "fsobasics.h")]
		public static bool isPresent (string filename);
		[CCode (cheader_filename = "fsobasics.h")]
		public static string read (string filename);
		[CCode (cheader_filename = "fsobasics.h")]
		public static void write (string contents, string filename);
	}
	[CCode (cprefix = "FsoFrameworkNetwork", lower_case_cprefix = "fso_framework_network_")]
	namespace Network {
		[CCode (cheader_filename = "fsobasics.h")]
		public static string ipv4AddressForInterface (string iface);
	}
	[CCode (cprefix = "FsoFrameworkStringHandling", lower_case_cprefix = "fso_framework_string_handling_")]
	namespace StringHandling {
		[CCode (cheader_filename = "fsobasics.h")]
		public static string enumToString (GLib.Type enum_type, int value);
		[CCode (cheader_filename = "fsobasics.h")]
		public static string stringListToString (string[] list);
	}
	[CCode (cprefix = "FsoFrameworkUserGroupHandling", lower_case_cprefix = "fso_framework_user_group_handling_")]
	namespace UserGroupHandling {
		[CCode (cheader_filename = "fsobasics.h")]
		public static Posix.gid_t gidForGroup (string group);
		[CCode (cheader_filename = "fsobasics.h")]
		public static bool switchToUserAndGroup (string user, string group);
		[CCode (cheader_filename = "fsobasics.h")]
		public static Posix.uid_t uidForUser (string user);
	}
	[CCode (cprefix = "FsoFrameworkUtility", lower_case_cprefix = "fso_framework_utility_")]
	namespace Utility {
		[CCode (cheader_filename = "fsobasics.h")]
		public static string prefixForExecutable ();
		[CCode (cheader_filename = "fsobasics.h")]
		public static string programName ();
	}
	[CCode (cheader_filename = "fsobasics.h")]
	public abstract class AbstractLogger : FsoFramework.Logger, GLib.Object {
		protected string destination;
		protected string domain;
		protected uint level;
		protected ReprDelegate reprdelegate;
		public AbstractLogger (string domain);
		protected virtual string format (string message, string level);
		public static string levelToString (GLib.LogLevelFlags level);
		public static GLib.LogLevelFlags stringToLevel (string level);
		protected virtual void write (string message);
	}
	[CCode (cheader_filename = "fsobasics.h")]
	public class FileLogger : FsoFramework.AbstractLogger {
		public FileLogger (string domain);
		public void setFile (string filename, bool append = true);
		protected override void write (string message);
	}
	[CCode (cheader_filename = "fsobasics.h")]
	public class NullLogger : FsoFramework.AbstractLogger {
		public NullLogger (string domain);
		protected override void write (string message);
	}
	[CCode (cheader_filename = "fsobasics.h")]
	public class SmartKeyFile : GLib.Object {
		public SmartKeyFile ();
		public bool boolValue (string section, string key, bool defaultvalue = false);
		public bool hasKey (string section, string key);
		public bool hasSection (string section);
		public int intValue (string section, string key, int defaultvalue = 0);
		public GLib.List<string> keysWithPrefix (string section, string? prefix = null);
		public bool loadFromFile (string filename);
		public GLib.List<string> sectionsWithPrefix (string? prefix = null);
		public string[]? stringListValue (string section, string key, string[]? defaultvalue = null);
		public string stringValue (string section, string key, string defaultvalue = "");
	}
	[CCode (cheader_filename = "fsobasics.h")]
	public class SmartKeyFileSection : GLib.Object {
		public static FsoFramework.SmartKeyFileSection? openSection (FsoFramework.SmartKeyFile kf, string section);
	}
	[CCode (cheader_filename = "fsobasics.h")]
	public class SyslogLogger : FsoFramework.AbstractLogger {
		public SyslogLogger (string domain);
		protected override string format (string message, string level);
		protected override void write (string message);
	}
	[CCode (cheader_filename = "fsobasics.h")]
	public interface Logger : GLib.Object {
		public static FsoFramework.Logger createFromKeyFile (FsoFramework.SmartKeyFile smk, string group, string domain);
		public static FsoFramework.Logger createFromKeyFileName (string filename, string group, string domain);
		public abstract void critical (string message);
		public abstract void debug (string message);
		public static FsoFramework.Logger defaultLogger ();
		public abstract void error (string message);
		public abstract string getDestination ();
		public abstract GLib.LogLevelFlags getLevel ();
		public abstract void info (string message);
		public abstract void setDestination (string destination);
		public abstract void setLevel (GLib.LogLevelFlags level);
		public abstract void setReprDelegate (ReprDelegate repr);
		public abstract void warning (string message);
	}
}
[CCode (cheader_filename = "fsobasics.h")]
public delegate string ReprDelegate ();
