CXX = g++

EXEC = bin/release/automaton

SRC = $(addprefix src/, $(addsuffix .cpp, Main Shader ResourceManager Window))
DEPS = $(addprefix dependencies/, glad/glad.c stb/stb_image.cpp)
LIBS = -lglfw3 -lGL -lX11 -pthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor

$(EXEC): $(SRC) 
	$(CXX) $^ $(DEPS) -o $@ $(LIBS)

.PHONY:
run:
	make
	./$(EXEC)

clean:
	rm -rf bin/release/automaton