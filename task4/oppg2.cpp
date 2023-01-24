#include <string>
#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label first_name_label;
  Gtk::Label last_name_label;
  Gtk::Label result;
  Gtk::Entry first_name;
  Gtk::Entry last_name;
  Gtk::Button button;

  Window() {
    first_name_label.set_text("Fornavn");
    last_name_label.set_text("Etternavn");
    button.set_label("Slå sammen");
    button.set_sensitive(false);

    vbox.pack_start(first_name_label);
    vbox.pack_start(first_name);  //Add the widget entry to vbox
    vbox.pack_start(last_name_label);
    vbox.pack_start(last_name);  //Add the widget entry to vbox
    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(result);  //Add the widget label to vbox

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets

    first_name.signal_changed().connect([this]() {
      if(first_name.get_text() != "" && last_name.get_text() != ""){
         if(!button.get_sensitive()) button.set_sensitive(true);
      } else if(button.get_sensitive()){
        button.set_sensitive(false);
      }
    });

    last_name.signal_changed().connect([this]() {
      if(first_name.get_text() != "" && last_name.get_text() != ""){
         if(!button.get_sensitive()) button.set_sensitive(true);
      } else if(button.get_sensitive()){
        button.set_sensitive(false);
      }
    });

    button.signal_clicked().connect([this]() {
      result.set_text(first_name.get_text() + " " + last_name.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  window.set_title("Øving 4");
  gtk_main.run(window);
}
