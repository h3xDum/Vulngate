#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <string>
#include "SceneManager.hpp"
class Renderer{

public:
  Renderer();
  ~Renderer();

  bool init(); // Load & Compile & Link GLSL shaders program 
  void draw();//
  // another draw that takes an array of objects 
  unsigned int get_program_id() const;
  void set_background(const float r, const float g, const float b) const; 

private:
  std::string file_to_str(const std::string& filePath); 
  unsigned int m_programId;


};





#endif
