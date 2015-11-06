public class MontUI : Gtk.Application
{
  private Gtk.Window window;

  public MontUI ()
  {
    Object (flags: ApplicationFlags.FLAGS_NONE);
  }

  protected override void startup ()
  {
    base.startup ();

    Environment.set_application_name ("MontUI");

    var ui_builder = new Gtk.Builder ();
    try
    {
      ui_builder.add_from_file (Path.build_filename (
          DATA_DIRECTORY, "interface.ui", null));
    }
    catch (Error e)
    {
      warning ("Could not load game UI: %s", e.message);
    }
    window = (Gtk.Window) ui_builder.get_object ("firstWindow");
    add_window (window);
  }

  protected override void shutdown ()
  {
    base.shutdown ();
  }

  protected override void activate ()
  {
    window.present ();
  }

  public static int main (string[] args)
  {
    var app = new MontUI ();
    return app.run (args);
  }
}
