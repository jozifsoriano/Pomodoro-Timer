#include "pomodoro.h"

int main(){
  int flag = 1;
  int option;

  Timer t1;
  t1.pomodoro_s = 25;
  t1.short_s = 5;
  t1.long_s = 15;
  t1.counter = 0;

  Menu m;
  while(flag == 1){
    option = t1.menu();
    if (option == 1){
      m.pomodoro(t1);
    }else if(option == 2){
      t1 = m.customize(t1);
    }else if(option == 3){
      flag = -1;
      break;
    }
  }

  return 0;
}
