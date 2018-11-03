%: %.cpp
	g++ -D LOCAL_TEST -std=c++11 -Wall $< -o $@

%: %.c
	gcc $< -o $@

template.cpp:
	
%.cpp: template.cpp
	cp template.cpp $@
