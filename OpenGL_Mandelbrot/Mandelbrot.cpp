#include "Include.hpp"
#include "createMandelbrot.hpp"

#include <glm/common.hpp>
#include <stdlib.h>

int main()
{
	const char* title = "Mandelbrot Fractal.";
    app::App firstApp(title, 1200, 800, false);

    createMandelbrot(firstApp, 1200, 800);

    firstApp.run();

    return 0;
}