set term postscript eps color 14
set output "/tmp/out/soma-hist-1-1.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 400 - Fase  1 - ID 1"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:21] "/tmp/out/soma-hist-1-1.gpdat" u 3:4 w boxes t ""
