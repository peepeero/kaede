CXX = g++
all: release

release: 
	$(CXX)  leroi.cpp -o a.out

out_release: before_release $(OBJ_RELEASE)
	$(CXX) -o $(OUT_RELEASE) $(OBJ_RELEASE) -s

$(OBJDIR_RELEASE)/grid.o: src/grid.cpp
	$(CXX) -c src/grid.cpp -o $(OBJDIR_RELEASE)/grid.o

$(OBJDIR_RELEASE)/rand.o: src/rand.cpp
	$(CXX) -c src/rand.cpp -o $(OBJDIR_RELEASE)/rand.o

$(OBJDIR_RELEASE)/main.o: src/main.cpp
	$(CXX) -c src/main.cpp -o $(OBJDIR_RELEASE)/main.o

clean_release:
