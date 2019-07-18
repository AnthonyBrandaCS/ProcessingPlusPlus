make:
	g++ src/main.cpp src/Display.cpp src/Processing.cpp src/ProcessingManager.cpp src/sketch/Sketch.cpp -L -lopengl31 -lglfw -lGL
