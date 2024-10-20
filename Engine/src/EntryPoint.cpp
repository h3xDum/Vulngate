// General use
#include <iostream>
//#include <stdexcept>


// Including all project specific file 
#include "../include/Engine.hpp"

int main () {

  Engine eng;
  try {
    eng.init();
  }
  catch (const std::exception& e) {
    std::cerr << "[!] Could'nt Initialize Engine -> " << e.what() << std::endl;
  }
  return 0;
}
