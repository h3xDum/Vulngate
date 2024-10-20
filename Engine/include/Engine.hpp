#ifndef ENGINE_HPP
#define ENGINE_HPP

// Include all the working parts 
#include "../include/SceneManager.hpp"

class Engine{


public:
  Engine();
  ~Engine();

  void init(); // Initialize entire engine working parts
  
private:
  SceneManager m_sceneManager;

};


#endif 
