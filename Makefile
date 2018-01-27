default :
	g++ *.cpp src/*.cpp -I include/ -std=c++11 -o sim
	pdflatex rapport.tex
