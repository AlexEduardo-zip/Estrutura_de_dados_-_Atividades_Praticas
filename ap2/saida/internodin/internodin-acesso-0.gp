set term postscript eps color 14
set output "/tmp/internodin/internodin-acesso-0.eps"
set title "Grafico de acesso - ID 0"
set xlabel "Acesso"
set ylabel "Endereco"
plot "/tmp/internodin/internodin-acesso-0-0.gpdat" u 2:4 w points t "L", "/tmp/internodin/internodin-acesso-1-0.gpdat" u 2:4 w points t "E"
