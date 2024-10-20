/* * * * * * * * * * * *  * * * * * * * * * * * * * * * 
 * This is an Interface meant to make sure that        *
 * each diffrent scene like MainMenu/MainHall/etc..    *
 * will be polymorphic to be handled correctly by the  *
 * SceneManager class                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SCENE_HPP
#define SCENE_HPP

class Scene {

public:
  virtual bool init_scene() = 0;
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual ~Scene() = default;
  
};
#endif 
