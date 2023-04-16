#define _USE_MATH_DEFINES

#include <GLFW/glfw3.h>
#include <cstdio>
#include <cmath>

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

float dx = 0.0f;
bool isDay = true;

void display() {
    isDay ? glClearColor(0.53f, 0.8f, 0.92f, 1.0f) : glClearColor(0.09f, 0.08f, 0.31f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // земля
    isDay ? glColor3f(0.44f, 0.65f, 0.2f) : glColor3f(0.24f, 0.45f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-2.0f, -1.0f);
        glVertex2f(-2.0f, 0.0f);
        glVertex2f(2.0f, 0.0f);
        glVertex2f(2.0f, -1.0f);
    glEnd();

    // параметры круга
    float xPos = -1.6f;
    float yPos = 0.7f;
    float radius = 0.2f;
    int segments = 64;
    float angleIncrement = 2.0f * (float)M_PI / segments;

    // солнце / луна
    glPushMatrix();
    glTranslatef(dx, 0.0f, 0.0f);
    
    glBegin(GL_TRIANGLE_FAN);
        isDay ? glColor3f(0.99f, 0.72f, 0.07f) : glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xPos, yPos);

        for (int i = 0; i <= segments; ++i) {
            float angle = i * angleIncrement;
            float x = xPos + radius * cosf(angle);
            float y = yPos + radius * sinf(angle);
            glVertex2f(x, y);
        }
    glEnd();
    
    // дополнительный круг для эффекта полумесяца
    if (!isDay) {
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.09f, 0.08f, 0.31f);
            glVertex2f(xPos + 0.1f, yPos + 0.05f);
            
            for (int i = 0; i <= segments; ++i) {
                float angle = i * angleIncrement;
                float x = (xPos + 0.1f) + radius * cosf(angle);
                float y = (yPos + 0.05f) + radius * sinf(angle);
                glVertex2f(x, y);
            }
        glEnd();
    }

    glPopMatrix();
    dx += 0.01f;
    
    if (xPos + dx > 1.6f) {
        isDay = !isDay;
        dx = 0.0f;
        return;
    }
    
    // фасад домика
    isDay ? glColor3f(0.93f, 0.9f, 0.88f) : glColor3f(0.73f, 0.8f, 0.68f);
    glBegin(GL_QUADS);
        glVertex2f(-0.8f, -0.5f);
        glVertex2f(-0.8f, 0.2f);
        glVertex2f(0.8f, 0.2f);
        glVertex2f(0.8f, -0.5f);
    glEnd();

    // крыша домика
    isDay ? glColor3f(0.74f, 0.5f, 0.38f) : glColor3f(0.54f, 0.3f, 0.18f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.9f, 0.2f);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.9f, 0.2f);
    glEnd();

    // дверь домика
    isDay ? glColor3f(0.8f, 0.4f, 0.1f) : glColor3f(0.6f, 0.2f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.5f);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.2f, -0.5f);
    glEnd();

    // окно домика
    isDay ? glColor3f(0.63f, 0.84f, 0.93f) : glColor3f(0.9f, 0.77f, 0.4f);
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, -0.1f);
        glVertex2f(-0.6f, 0.1f);
        glVertex2f(-0.4f, 0.1f);
        glVertex2f(-0.4f, -0.1f);
    glEnd();
}

int main(void) {
    GLFWwindow* window;
    
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    
    window = glfwCreateWindow(640, 480, "Lab 1", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    
    while (!glfwWindowShouldClose(window)) {
        int width;
        int height;
        float ratio;
        glfwGetFramebufferSize(window, &width, &height);
        
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        display();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}