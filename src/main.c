#include <gtk4-layer-shell.h>
#include <gtk/gtk.h>

static void activate(GtkApplication* app, void* _data) {
    (void)_data;

    GtkWindow* gtk_window = GTK_WINDOW(gtk_application_window_new(app));

    gtk_layer_init_for_window(gtk_window);
    gtk_layer_set_layer(gtk_window, GTK_LAYER_SHELL_LAYER_OVERLAY);
    gtk_layer_auto_exclusive_zone_enable(gtk_window);

    static const gboolean anchors[] = {FALSE, FALSE, FALSE, FALSE};
    for (int i = 0; i < GTK_LAYER_SHELL_EDGE_ENTRY_NUMBER; i++) {
        gtk_layer_set_anchor(gtk_window, i, anchors[i]);
    }

    GtkWidget* label = gtk_label_new("");
    gtk_label_set_markup(
        GTK_LABEL(label),
        "<span>"
            "+"
        "</span>"
    );
    gtk_widget_add_css_class(label, "xhair");
    gtk_widget_add_css_class(GTK_WIDGET(gtk_window), "transparent-window");

    GtkCssProvider *provider = gtk_css_provider_new();

    gtk_css_provider_load_from_string(provider,
            ".xhair {\n"
            "   font-size: 22pt;"
            "   text-shadow: \n"
            "       -1px  0px 0px #000000,"
            "       1px  0px 0px #000000,"
            "       0px -1px 0px #000000,"
            "       0px  1px 0px #000000;"
            "}\n"
            ".transparent-window {\n"
            "    background-color: rgba(0, 0, 0, 0.0);\n"
            "    background-image: none;\n"
            "    box-shadow: none;\n"
            "    border: none;\n"
            "}\n"
    );

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    g_object_unref(provider);

    gtk_window_set_child(gtk_window, label);
    gtk_window_present(gtk_window);
}

int main(int argc, char **argv) {
    GtkApplication* app = gtk_application_new("org.loldonut.xhair", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
