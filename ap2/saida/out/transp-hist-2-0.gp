set term postscript eps color 14
set output "/tmp/out/transp-hist-2-0.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 400 - Fase  2 - ID 0"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:21] "/tmp/out/transp-hist-2-0.gpdat" u 3:4 w boxes t ""
