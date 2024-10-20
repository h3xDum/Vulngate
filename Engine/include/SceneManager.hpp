#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "../../Dependencies/glad/include/glad/glad.h"  // | -------------------------
#include "../../Dependencies/glfw/include/GLFW/glfw3.h" // | Both for init_glfw func |

#include <iostream>

class SceneManager{

public:
  SceneManager();
  ~SceneManager();

  bool init(); // will call init_glfw() 

  GLFWwindow* get_glfw_window() const;
  static void window_resize(GLFWwindow* window, int width, int height);

private:
  GLFWwindow* m_glfwWindow = nullptr;

  bool init_glfw();
};


#endif
