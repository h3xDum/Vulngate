#include "../include/SceneManager.hpp"

SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {
  
  if (m_glfwWindow) { // Created on init_glfw function
    glfwDestroyWindow(m_glfwWindow);
  }

  glfwTerminate();
}

void SceneManager::window_resize(GLFWwindow* window, int width, int height){
  glViewport(0,0,width,height);
}

bool SceneManager::init() {
  
  bool success = init_glfw();
  
  return success;
}


bool SceneManager::init_glfw() {
  
  // OPENGL GLFW boilerplate code 
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Window Creation
  m_glfwWindow = glfwCreateWindow(800, 1024 , "Vulngate 0.0", nullptr,nullptr);
  if (!m_glfwWindow) {
    std::cerr << "[!] GLFW Window Creation Failed" << std::endl;
    return false;
  }
  glfwMakeContextCurrent(m_glfwWindow);
  glfwSetFramebufferSizeCallback(m_glfwWindow, window_resize);

  // Glad Init
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout << "[!] GLAD Initialization failed" << std::endl;
    return false;
  }      

  return true;
}

