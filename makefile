CXXFLAGS += -std=c++11

ex: pomodoro_main.o pomodoro.o
	$(CXX) $(CXXFLAGS) -o pomodoro pomodoro_main.o pomodoro.o
pomodoro_main.o: pomodoro.h pomodoro_main.cpp
	$(CXX) $(CXXFLAGS) -c pomodoro_main.cpp
pomodoro.o: pomodoro.h pomodoro.cpp 
	$(CXX) $(CXXFLAGS) -c pomodoro.cpp
