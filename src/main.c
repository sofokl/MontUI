/* main.c generated by valac 0.30.0, the Vala compiler
 * generated from main.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_MONT_UI (mont_ui_get_type ())
#define MONT_UI(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MONT_UI, MontUI))
#define MONT_UI_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MONT_UI, MontUIClass))
#define IS_MONT_UI(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MONT_UI))
#define IS_MONT_UI_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MONT_UI))
#define MONT_UI_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MONT_UI, MontUIClass))

typedef struct _MontUI MontUI;
typedef struct _MontUIClass MontUIClass;
typedef struct _MontUIPrivate MontUIPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _MontUI {
	GtkApplication parent_instance;
	MontUIPrivate * priv;
};

struct _MontUIClass {
	GtkApplicationClass parent_class;
};

struct _MontUIPrivate {
	GtkWindow* window;
};


static gpointer mont_ui_parent_class = NULL;

GType mont_ui_get_type (void) G_GNUC_CONST;
#define MONT_UI_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_MONT_UI, MontUIPrivate))
enum  {
	MONT_UI_DUMMY_PROPERTY
};
MontUI* mont_ui_new (void);
MontUI* mont_ui_construct (GType object_type);
static void mont_ui_real_startup (GApplication* base);
static void mont_ui_real_shutdown (GApplication* base);
static void mont_ui_real_activate (GApplication* base);
gint mont_ui_main (gchar** args, int args_length1);
static void mont_ui_finalize (GObject* obj);


MontUI* mont_ui_construct (GType object_type) {
	MontUI * self = NULL;
	self = (MontUI*) g_object_new (object_type, "flags", G_APPLICATION_FLAGS_NONE, NULL);
	return self;
}


MontUI* mont_ui_new (void) {
	return mont_ui_construct (TYPE_MONT_UI);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void mont_ui_real_startup (GApplication* base) {
	MontUI * self;
	GtkBuilder* ui_builder = NULL;
	GtkBuilder* _tmp0_ = NULL;
	GObject* _tmp5_ = NULL;
	GtkWindow* _tmp6_ = NULL;
	GtkWindow* _tmp7_ = NULL;
	GError * _inner_error_ = NULL;
	self = (MontUI*) base;
	G_APPLICATION_CLASS (mont_ui_parent_class)->startup ((GApplication*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_application_get_type (), GtkApplication));
	g_set_application_name ("MontUI");
	_tmp0_ = gtk_builder_new ();
	ui_builder = _tmp0_;
	{
		gchar* _tmp1_ = NULL;
		gchar* _tmp2_ = NULL;
		_tmp1_ = g_build_filename (DATA_DIRECTORY, "interface.ui", NULL, NULL);
		_tmp2_ = _tmp1_;
		gtk_builder_add_from_file (ui_builder, _tmp2_, &_inner_error_);
		_g_free0 (_tmp2_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		GError* _tmp3_ = NULL;
		const gchar* _tmp4_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp3_ = e;
		_tmp4_ = _tmp3_->message;
		g_warning ("main.vala:24: Could not load game UI: %s", _tmp4_);
		_g_error_free0 (e);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		_g_object_unref0 (ui_builder);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp5_ = gtk_builder_get_object (ui_builder, "firstWindow");
	_tmp6_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp5_, gtk_window_get_type (), GtkWindow));
	_g_object_unref0 (self->priv->window);
	self->priv->window = _tmp6_;
	_tmp7_ = self->priv->window;
	gtk_application_add_window ((GtkApplication*) self, _tmp7_);
	_g_object_unref0 (ui_builder);
}


static void mont_ui_real_shutdown (GApplication* base) {
	MontUI * self;
	self = (MontUI*) base;
	G_APPLICATION_CLASS (mont_ui_parent_class)->shutdown ((GApplication*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_application_get_type (), GtkApplication));
}


static void mont_ui_real_activate (GApplication* base) {
	MontUI * self;
	GtkWindow* _tmp0_ = NULL;
	self = (MontUI*) base;
	_tmp0_ = self->priv->window;
	gtk_window_present (_tmp0_);
}


gint mont_ui_main (gchar** args, int args_length1) {
	gint result = 0;
	MontUI* app = NULL;
	MontUI* _tmp0_ = NULL;
	gchar** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	gint _tmp2_ = 0;
	_tmp0_ = mont_ui_new ();
	app = _tmp0_;
	_tmp1_ = args;
	_tmp1__length1 = args_length1;
	_tmp2_ = g_application_run ((GApplication*) app, _tmp1__length1, _tmp1_);
	result = _tmp2_;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	return mont_ui_main (argv, argc);
}


static void mont_ui_class_init (MontUIClass * klass) {
	mont_ui_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MontUIPrivate));
	((GApplicationClass *) klass)->startup = mont_ui_real_startup;
	((GApplicationClass *) klass)->shutdown = mont_ui_real_shutdown;
	((GApplicationClass *) klass)->activate = mont_ui_real_activate;
	G_OBJECT_CLASS (klass)->finalize = mont_ui_finalize;
}


static void mont_ui_instance_init (MontUI * self) {
	self->priv = MONT_UI_GET_PRIVATE (self);
}


static void mont_ui_finalize (GObject* obj) {
	MontUI * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_MONT_UI, MontUI);
	_g_object_unref0 (self->priv->window);
	G_OBJECT_CLASS (mont_ui_parent_class)->finalize (obj);
}


GType mont_ui_get_type (void) {
	static volatile gsize mont_ui_type_id__volatile = 0;
	if (g_once_init_enter (&mont_ui_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MontUIClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) mont_ui_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MontUI), 0, (GInstanceInitFunc) mont_ui_instance_init, NULL };
		GType mont_ui_type_id;
		mont_ui_type_id = g_type_register_static (gtk_application_get_type (), "MontUI", &g_define_type_info, 0);
		g_once_init_leave (&mont_ui_type_id__volatile, mont_ui_type_id);
	}
	return mont_ui_type_id__volatile;
}



