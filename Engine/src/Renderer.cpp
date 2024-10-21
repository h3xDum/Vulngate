#include "../include/Renderer.hpp"

#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>


Renderer::Renderer(){}

Renderer::~Renderer(){}


bool Renderer::init() {
  
  const char* vShaderSource;
  const char* fShaderSource;
  char infoLog[512];
  int success;

  // Read shaders from disk
  try {
    std::string vShaderSourceString = file_to_str("../Engine/resources/glsl/vertex_shader.glsl");
    std::string fShaderSourceString = file_to_str("../Engine/resources/glsl/fragment_shader.glsl");
    vShaderSource = vShaderSourceString.c_str();
    fShaderSource = fShaderSourceString.c_str();
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  // Creating a vertex shader opengl object 
  unsigned int vShader;
  vShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vShader,1, &vShaderSource, nullptr);
  glCompileShader(vShader);
  glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vShader, sizeof(infoLog), nullptr, infoLog);
    std::cerr << "ERROR::Failed to compile Vertex Shader:" << infoLog << std::endl;
  }
  
  // Creating a fragment shader opengl object 
  unsigned int fShader;
  vShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(fShader,1, &fShaderSource, nullptr);
  glCompileShader(fShader);
  glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vShader, sizeof(infoLog), nullptr, infoLog);
    std::cerr << "ERROR::Failed to compile Vertex Shader:" << infoLog << std::endl;
  }
  
  // Linking all the shader programs
  m_programId = glCreateProgram();
  glAttachShader(m_programId, vShader);
  glAttachShader(m_programId, fShader);
  glLinkProgram(m_programId);
  glGetProgramiv(m_programId, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(m_programId, sizeof(infoLog), nullptr, infoLog);
    std::cerr << "ERROR::Failed to limk shader program" << infoLog << std::endl;
    return false;
  }

  glUseProgram(m_programId);
  glDeleteShader(vShader);
  glDeleteShader(fShader);

  return true;
}

void Renderer::set_background(const float r, const float g, const float b) const {
  glClearColor(r,g,b,1.0f); 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

std::string Renderer::file_to_str(const std::string& path) {
  std::ifstream ifstream;
  ifstream.exceptions(std::fstream::failbit  | std::ifstream::badbit);

  std::stringstream sstream;
  try {
    ifstream.open(path); // Open the file using ifstream
    sstream << ifstream.rdbuf(); // pipe content into string stream
    ifstream.close();
  } catch (std::ifstream::failure& e) {
    std::cerr << "[!] in File: " << path << std::endl;
    throw std::runtime_error("ERROR::Failed to read the file");
  }
  return sstream.str();
}
