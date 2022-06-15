set term postscript eps color 14
set output "/tmp/out/mult-acesso-1.eps"
set title "Grafico de acesso - ID 1"
set xlabel "Acesso"
set ylabel "Endereco"
plot "/tmp/out/mult-acesso-0-1.gpdat" u 2:4 w points t "L", "/tmp/out/mult-acesso-1-1.gpdat" u 2:4 w points t "E"
