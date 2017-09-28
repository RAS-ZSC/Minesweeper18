#ifndef _POS_TRACKER_H
#define _POS_TRACKER_H

class PosTracker {
  int base, limit;
public:
  PosTracker(int, int);
  void clear();
  void savePos(float, int, int);
  float findPos(int, int);
};

#endif
