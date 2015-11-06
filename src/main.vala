using Gtk;

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
      //ui_builder.add_from_file (Path.build_filename (DATA_DIRECTORY, "interface.ui", null));

      ui_builder.add_from_file (Path.build_filename ("./data", "interface.ui", null));
    }
    catch (Error e)
    {
      warning ("Could not load game UI: %s", e.message);
    }
    window = (Gtk.Window) ui_builder.get_object ("window");
    var header = (Gtk.HeaderBar) ui_builder.get_object("headerbar");
    header.set_show_close_button(false);
	header.spacing = 10;
	header.height_request = 50;

	window.set_titlebar(header);
	//header.set_vexpand(true);

    add_window (window);

    this.create_widgets();

    //window.show_all();
  }

  private void create_widgets() {

  /*	Gtk.HeaderBar headerbar = new Gtk.HeaderBar();
	headerbar.set_title("Monts UI");
	headerbar.set_subtitle ("Belgorod");
	headerbar.set_show_close_button(false);
	headerbar.spacing = 10;
	headerbar.height_request = 50;
	headerbar.set_vexpand(true);


	window.set_titlebar(headerbar);

	var image = new Gtk.Image.from_icon_name ("applications-system-symbolic", Gtk.IconSize.LARGE_TOOLBAR);
	var bt_menu = new Gtk.Button();
	bt_menu.set_valign(Gtk.Align.CENTER);
	bt_menu.set_image(image);
	bt_menu.set_size_request(70,50);
	//var pmenu = new Gtk.Menu();
	//pmenu.append(new Gtk.MenuItem())

	//bt_settings.set_pop

	//button_settings.set_valign (Gtk.Align.CENTER);
	//button_settings.set_image (new Gtk.Image.from_icon_name ("applications-system-symbolic", Gtk.IconSize.LARGE_TOOLBAR));

	headerbar.pack_start (bt_menu);

	var button_quit = new Gtk.Button();
	button_quit.set_valign (Gtk.Align.CENTER);
	button_quit.set_image (new Gtk.Image.from_icon_name ("application-exit-symbolic", Gtk.IconSize.LARGE_TOOLBAR));
	button_quit.set_size_request(70,50);
	headerbar.pack_end (button_quit);

	button_quit.clicked.connect ( () => {
		quit();
	});*/

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
