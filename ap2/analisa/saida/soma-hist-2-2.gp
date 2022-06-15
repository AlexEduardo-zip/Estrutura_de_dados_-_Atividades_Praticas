set term png
set output "/tmp/out/soma-hist-2-2.png"
set style fill solid 1.0
set title "Distancia de Pilha (Total 400 # 40 Media 10.00) - Fase  2 - ID 2"
set xlabel "Distancia"
set ylabel "Frequencia"
plot [-1:21] "/tmp/out/soma-hist-2-2.gpdat" u 3:4 w boxes t ""
