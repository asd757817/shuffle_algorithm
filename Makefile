all: run
run: shuffle.c
	gcc -Wall -o shuffle shuffle.c &&./shuffle
	gnuplot plot_script/plot_enforce.gp
	gnuplot plot_script/plot_swap.gp
	gnuplot plot_script/plot_fisher.gp

clea:
	rm -f *.o

