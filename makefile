make:
	g++ src/main.cpp src/Display.cpp src/Processing.cpp src/ProcessingManager.cpp src/sketch/Sketch.cpp src/sketch/Drop.cpp -L -lopengl31 -lglfw -lGL
