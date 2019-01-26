#ifndef POMO_H
#define POMO_H

#include <stdlib.h>
#include <iostream>
class Timer{
public:
  int pomodoro_s, short_s, long_s, counter;
  int menu();
  int set_time_s(std::string t);
  int count(int n);
};

class Display{
private:
  Timer t;
  int sec, min;
  std::string text;
  int s_to_min(int s);
public:
  Display(int s, std::string t);
  void t_display();
  void start_timer();
};

class Menu{
public:
  void pomodoro(Timer t);
  Timer customize(Timer t);
};

#endif
