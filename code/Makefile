ALL=mo53
CXX=g++
CXXFLAGS=-std=c++14

mo53: main.cpp text_loader.o bin_loader.o screen_writer.o text_writer.o bin_writer.o process.o vector_storage.o list_storage.o moving_average.o storage_sum.o storage_average.o storage_count.o resource_manager.o
	$(CXX) $(CXXFLAGS) -o mo53 main.cpp text_loader.o bin_loader.o screen_writer.o text_writer.o bin_writer.o process.o vector_storage.o list_storage.o moving_average.o storage_sum.o storage_average.o storage_count.o resource_manager.o

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f *.o
	rm -f mo53
