set term png
set output "/tmp/out/soma-acesso-0.png"
set title "Grafico de acesso - ID 0"
set xlabel "Acesso"
set ylabel "Endereco"
plot "/tmp/out/soma-acesso-0-0.gpdat" u 2:4 w points t "L", "/tmp/out/soma-acesso-1-0.gpdat" u 2:4 w points t "E"
