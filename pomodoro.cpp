#include "pomodoro.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

int Timer::set_time_s(std::string t){
  int s;
  std::cout << "How long would you like to set the "
  << t << " timer for? [s]";
  std::cin >> s;
  return s;
}

int Timer::count(int n){
  if (n>3){
    return (n%4);
  }else{
    return n;
  }
}

Display::Display(int s, std::string t){
  text = t;
  if((s%60)==0){
    min = s_to_min(s);
    sec = 0;
  }else if((s%60)!=0){
    min = s/60;
    sec = s%60;
  }
}
int Timer::menu(){
  int option;
  std::cout << "Welcome to my Pomodoro Timer!\n"
  << "Select an option. \n"
  << "1. Pomodoro\n"
  << "2. Customize\n"
  << "3. Quit\n";
  std::cin >> option;
  return option;
}

int Display::s_to_min(int s){
  return (s/60);
}

void Display::t_display(){
  system("clear");

  std::cout<<"\t"<<text<<"\n"
  << "Minutes\t\t\tSeconds\n"
  << min << "\t\t\t" << sec;
}

void Display::start_timer(){
  bool flag = true;
  while(flag){
    t_display();
    sleep(1);
    if ((min==0)&&(sec==0)){
      sec--;
      text = "TIMES UP! Starting next cycle.";
      {t_display();
        sleep(4);}
      flag = false;
    }
    if(sec == 0){
      if(min==0){
        sec = 60;
      }else{
        min--;
        sec = 60;
      }
    }
    sec--;
  }
}

void Menu::pomodoro(Timer t){
  int flag = 1;
  std::string text = "";
  while(flag == 1){
    text = "POMODORO";
    Display d(t.pomodoro_s,text);
    d.start_timer();
    if (t.counter < 3){
      text = "SHORT BREAK";
      Display d(t.short_s,text);
      d.start_timer();
      t.counter++;
    }else if(t.counter == 3){
      text = "LONG BREAK";
      Display d(t.long_s,text);
      d.start_timer();
      t.counter++;
    }
    t.counter = t.count(t.counter);
  }
}

Timer Menu::customize(Timer t){
  int option;
  std::string name = "";
  std::cout << "CUSTOMIZATION\n"
  << "Which timer would you like to customize?\n"
  << "1. Pomodoro\n"
  << "2. Short Break\n"
  << "3. Long Break\n";
  std::cin >> option;
  if (option == 1){
    name = "Pomodoro";
    t.pomodoro_s = t.set_time_s(name);
  }else if(option == 2){
    name = "Short Break";
    t.short_s = t.set_time_s(name);
  }else if(option == 3){
    name = "Long Break";
    t.long_s = t.set_time_s(name);
  }
  return t;
}
