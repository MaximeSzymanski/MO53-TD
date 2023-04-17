ALL=mo53
CXX=g++
CXXFLAGS=-std=c++14

mo53: main.cpp text_loader.o bin_loader.o screen_writer.o
	$(CXX) $(CXXFLAGS) -o mo53 main.cpp text_loader.o bin_loader.o screen_writer.o

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o
	rm -f mo53
