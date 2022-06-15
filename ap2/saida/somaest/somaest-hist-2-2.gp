set term postscript eps color 14
set output "/tmp/somaest/somaest-hist-2-2.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 400 - Fase  2 - ID 2"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:21] "/tmp/somaest/somaest-hist-2-2.gpdat" u 3:4 w boxes t ""