static void homeScreen(){
  printTama(frog);
  back();
  potentiometer();
  OrbitOledUpdate();
//  OrbitOledClear();

}

static void homeBackground(){
  OrbitOledMoveTo(64, 0);
  OrbitOledLineTo(64, 32);
  OrbitOledMoveTo(68, 0);
}
