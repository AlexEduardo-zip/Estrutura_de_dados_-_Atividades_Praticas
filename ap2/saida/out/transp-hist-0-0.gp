set term postscript eps color 14
set output "/tmp/out/transp-hist-0-0.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 460 - Fase  0 - ID 0"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:26] "/tmp/out/transp-hist-0-0.gpdat" u 3:4 w boxes t ""
