#ifndef ENGINE_HPP

#define ENGINE_HPP

// Include all the working parts 
#include "SceneManager.hpp"
#include "Renderer.hpp"
class Engine{


public:
  Engine();
  ~Engine();

  void init(); // Initialize entire engine working parts
  
private:
  SceneManager m_sceneManager;
  Renderer m_renderer;
};


#endif 
