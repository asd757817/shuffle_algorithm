reset
set autoscale fix
#set palette defined (0 'white', 1 'green')
set palette rgbformulae 22,13,10
set terminal png
set output "heatmap_fisher.png"
set tics scale 0
unset cbtics
set cblabel 'Score'
unset key
plot 'fisher_shuffle.txt' matrix with image,\
