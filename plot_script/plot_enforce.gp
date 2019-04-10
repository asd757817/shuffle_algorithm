reset
set autoscale fix
#set palette defined (0 'white', 1 'green')
set palette rgbformulae 22,13,10
set terminal png
set output "heatmap_enforce.png"
set tics scale 0
unset cbtics
set cblabel 'Score'
unset key
plot 'enforce_shuffle.txt' matrix with image,\
