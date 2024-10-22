#include "../include/Engine.hpp"

#include <stdexcept>

Engine::Engine(){}

Engine::~Engine(){

}

void Engine::init(){

  if (!m_sceneManager.init()) {throw std::runtime_error("[!] Engine::init() Failed to Initialize SceneManager");}
  if (!m_renderer.init()) {throw std::runtime_error(("[!] Engine::init() Failed to Initialize Renderer"));}

}

