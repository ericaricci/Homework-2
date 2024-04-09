#include <GLFW/glfw3.h>
#include <cmath>
//plotting the temperature as a function of altitude
//sourced from chatgpt
void plotGraph() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the window
    glBegin(GL_LINE_STRIP);       // Start drawing a line strip

    // Constants for the standard atmosphere model
    const double T0 = 288.15;   // Sea level temperature in Kelvin
    const double L = 0.0065;     // Temperature lapse rate in K/m

    for (int h = 0; h <= 20000; h += 100) {
        double T = T0 - L * h / 1000.0;  // Calculate temperature at altitude h (in km)
        glVertex2d(h / 1000.0, T);       // Plot the point (altitude, temperature)
    }

    glEnd(); // End drawing the line strip
    glFlush(); // Flush the drawing commands
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Standard Atmosphere Model", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        plotGraph();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}
