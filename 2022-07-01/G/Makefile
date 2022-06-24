CPP=g++
CARGS=-std=c++11 -lm -lcrypt -O2 -std=c++11 -pipe

clean:
	rm -rf G G.out

G: G.cpp
	$(CPP) $(CARGS) G.cpp -o G
	./G < G.in > G.out
	diff G.out G.res
