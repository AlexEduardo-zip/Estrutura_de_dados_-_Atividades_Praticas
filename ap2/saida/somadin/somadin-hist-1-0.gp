set term postscript eps color 14
set output "/tmp/somadin/somadin-hist-1-0.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 400 - Fase  1 - ID 0"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:21] "/tmp/somadin/somadin-hist-1-0.gpdat" u 3:4 w boxes t ""
