#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Scene.hpp"

class MainMenu : public Scene {

  MainMenu();
  ~MainMenu();

  bool init_scene() override; // Load all the main menu objects 
  void draw() override;
  void update() override;





};


#endif
