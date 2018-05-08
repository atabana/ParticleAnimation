

# All Target
all: 
	g++ -Iincludes/SDL2  -c  -o "src/main.o" "src/main.cpp"
	g++ -Iincludes/SDL2  -c  -MT"src/Particle.o" -o "src/Particle.o" "src/Particle.cpp"
	g++ -Iincludes/SDL2  -c  -MT"src/Screen.o" -o "src/Screen.o" "src/Screen.cpp"
	g++ -Iincludes/SDL2  -c  -MT"src/Swarm.o" -o "src/Swarm.o" "src/Swarm.cpp"
	g++ -Llibraries -o "Particle Animation"  ./src/main.o ./src/Particle.o ./src/Screen.o ./src/Swarm.o   -lSDL2
