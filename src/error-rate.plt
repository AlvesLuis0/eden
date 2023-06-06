set terminal svg
set output ARG2

set xlabel 'Epochs'
set ylabel 'Rate'

set title 'Error Rate'

plot ARG1 with lines