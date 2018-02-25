all:

%: %.cpp
	g++ -D LOCAL_TEST -std=c++11 -g -Wall $< -o $@

%: %.c
	gcc $< -o $@
