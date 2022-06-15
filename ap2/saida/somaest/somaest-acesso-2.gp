set term postscript eps color 14
set output "/tmp/somaest/somaest-acesso-2.eps"
set title "Grafico de acesso - ID 2"
set xlabel "Acesso"
set ylabel "Endereco"
plot "/tmp/somaest/somaest-acesso-0-2.gpdat" u 2:4 w points t "L", "/tmp/somaest/somaest-acesso-1-2.gpdat" u 2:4 w points t "E"
