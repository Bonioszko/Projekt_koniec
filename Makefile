all: compile link

compile:
	g++ -Isrc/include -c gradowrzuceniakopi.cpp
	g++ -Isrc/include -c funkcje.cpp

link:
	g++ gradowrzuceniakopi.o funkcje.o -o gradowrzuceniakopi  -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
	gradowrzuceniakopi.exe