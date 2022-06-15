set term postscript eps color 14
set output "/tmp/out/mult-hist-1-2.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 1350 - Fase  1 - ID 2"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:26] "/tmp/out/mult-hist-1-2.gpdat" u 3:4 w boxes t ""
