#include <iostream>
#include <gtkmm.h>

// In this example I try to bring up gui system through GTKMM
// (GTKMM) : This is a Cpp interface for GTK
// Website : https://gtkmm.gnome.org



class HelloWorldWindow : public Gtk::Window
{
    public:
        HelloWorldWindow();
};

HelloWorldWindow::HelloWorldWindow()
{
  set_title("Hello World");
  set_default_size(650, 450);
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.helloworld.base");

  return app->make_window_and_run<HelloWorldWindow>(argc, argv);
}
