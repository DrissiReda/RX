default :
	g++ *.cpp src/*.cpp -I include/ -std=c++11 -g -o sim
	pdflatex rapport.tex > /dev/null
report :
	pdflatex rapport.tex
sim :
	g++ *.cpp src/*.cpp -I include/ -std=c++11 -g -o sim
