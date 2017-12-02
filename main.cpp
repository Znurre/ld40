#include <QGuiApplication>

#include "Window.h"

int main(int argc, char **argv)
{
	QGuiApplication application(argc, argv);

	Window window;
	window.resize(1280, 700);
	window.show();

	return application.exec();
}
