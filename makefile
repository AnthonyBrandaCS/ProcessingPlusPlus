make:
	g++ *.cpp -lSDL2 -lGL -lGLEW

make_run:
	g++ *.cpp -lSDL2 -lGL -lGLEW && ./a.out

run:
	./a.out

rm:
	rm ./a.out