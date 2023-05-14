#define _USE_MATH_DEFINES

#include <GLFW/glfw3.h>
#include <cstdio>
#include <cmath>
#include <vector>

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

struct Point {
    float x;
    float y;
};

struct Object {
    Object(const std::vector<GLfloat>& coord, const std::vector<GLfloat>& color, const std::vector<GLubyte>& idx) 
        : coord(coord), color(color), idx(idx)
    {}

    std::vector<GLfloat> coord;
    std::vector<GLfloat> color;
    std::vector<GLubyte> idx;
};

int main(void) {
    float dx = 0.0f;
    bool isDay = true;
    
    // параметры круга
    float xPos = -1.6f;
    float yPos = 0.7f;
    float radius = 0.2f;
    int segments = 64;
    float angleIncrement = 2.0f * (float)M_PI / segments;
    
    GLFWwindow* window;
    
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    
    window = glfwCreateWindow(640, 480, "Lab 2", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // солнце / луна
    std::vector<GLfloat> lightObjCoord;
    std::vector<GLfloat> lightObjSunColor;
    std::vector<GLfloat> lightObjMoonColor;
    std::vector<GLubyte> lightObjIdx {0};

    lightObjCoord.insert(lightObjCoord.end(), {xPos, yPos});
    lightObjSunColor.insert(lightObjSunColor.end(), {0.99f, 0.72f, 0.07f});
    lightObjMoonColor.insert(lightObjMoonColor.end(), {1.0f, 1.0f, 1.0f});

    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleIncrement;
        float x = xPos + radius * cosf(angle);
        float y = yPos + radius * sinf(angle);
        lightObjCoord.insert(lightObjCoord.end(), {x, y});
        lightObjSunColor.insert(lightObjSunColor.end(), {0.99f, 0.72f, 0.07f});
        lightObjMoonColor.insert(lightObjMoonColor.end(), {1.0f, 1.0f, 1.0f});
        lightObjIdx.push_back(i + 1);
    }

    Object lightObj(lightObjCoord, lightObjSunColor, lightObjIdx);

    // земля
    std::vector<GLfloat> fieldCoord {
        -2.0f,    -1.0f,
        -2.0f,    0.0f,
        2.0f,    0.0f,
        2.0f,    -1.0f
    };

    std::vector<GLfloat> fieldColor {
        0.44f, 0.65f, 0.2f,
        0.44f, 0.65f, 0.2f,
        0.44f, 0.65f, 0.2f,
        0.44f, 0.65f, 0.2f
    };

    std::vector<GLubyte> fieldIdx{0, 1, 2, 3};
    
    Object field(fieldCoord, fieldColor, fieldIdx);

    // фасад домика
    std::vector<GLfloat> facadeCoord {
        -0.8f,    -0.5f,
        -0.8f,    0.2f,
        0.8f,    0.2f,
        0.8f,    -0.5f
    };

    std::vector<GLfloat> facadeColor {
        0.73f, 0.8f, 0.68f,
        0.73f, 0.8f, 0.68f,
        0.73f, 0.8f, 0.68f,
        0.73f, 0.8f, 0.68f
    };

    std::vector<GLubyte> facadeIdx{0, 1, 2, 3};
    
    Object facade(facadeCoord, facadeColor, facadeIdx);

    // крыша домика
    std::vector<GLfloat> rooftopCoord {
        -0.9f,    0.2f,
        0.0f,    0.9f,
        0.9f,    0.2f
    };

    std::vector<GLfloat> rooftopColor {
        0.74f, 0.5f, 0.38f,
        0.74f, 0.5f, 0.38f,
        0.74f, 0.5f, 0.38f
    };

    std::vector<GLubyte> rooftopIdx{0, 1, 2};
    
    Object rooftop(rooftopCoord, rooftopColor, rooftopIdx);
    
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

        if (xPos + dx > 1.6f) {
            isDay = !isDay;
            dx = 0.0f;
        }
        
        isDay ? glClearColor(0.53f, 0.8f, 0.92f, 1.0f) : glClearColor(0.09f, 0.08f, 0.31f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);


        glPushMatrix();
        glTranslatef(dx, 0.0f, 0.0f);
        glVertexPointer(2, GL_FLOAT, 0, lightObj.coord.data());
        if (isDay) {
            glColorPointer(3, GL_FLOAT, 0, lightObjSunColor.data());
        }
        else {
            glColorPointer(3, GL_FLOAT, 0, lightObjMoonColor.data());
        }
        glDrawElements(GL_TRIANGLE_FAN, lightObj.idx.size(), GL_UNSIGNED_BYTE, lightObj.idx.data());
        glPopMatrix();
        dx += 0.01f;
        
        glVertexPointer(2, GL_FLOAT, 0, field.coord.data());
        glColorPointer(3, GL_FLOAT, 0, field.color.data());
        glDrawElements(GL_QUADS, field.idx.size(), GL_UNSIGNED_BYTE, field.idx.data());

        glVertexPointer(2, GL_FLOAT, 0, facade.coord.data());
        glColorPointer(3, GL_FLOAT, 0, facade.color.data());
        glDrawElements(GL_QUADS, facade.idx.size(), GL_UNSIGNED_BYTE, facade.idx.data());

        glVertexPointer(2, GL_FLOAT, 0, rooftop.coord.data());
        glColorPointer(3, GL_FLOAT, 0, rooftop.color.data());
        glDrawElements(GL_TRIANGLES, rooftop.idx.size(), GL_UNSIGNED_BYTE, rooftop.idx.data());
        
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}