#ifndef _POS_TRACKER_H
#define _POS_TRACKER_H

class PosTracker {
public:
  void clear();
  void savePos(int, float);
  float findPos(int);
};

#endif
