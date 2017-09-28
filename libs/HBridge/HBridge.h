#ifndef _HBRIDGE_H
#define _HBRIDGE_H

class HBridge {
private:
  int m1, m2, m3, m4;
  void moving(boolean, boolean, boolean, boolean);

public:
  HBridge(int, int, int, int);
  
  void forward();
  void backward();
  void left();
  void right();
  void stop();
};

#endif
