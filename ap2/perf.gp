set term postscript eps color 14
set output "perf.eps"
set title "Desempenho Operacoes com Matrizes"
set xlabel "Dimensao da Matriz"
set ylabel "Tempo de Execucao (s)
set logscale y
set key left top
plot "perf.gpdat" u 1:2 w linesp t "Interno",\
"perf.gpdat" u 1:3 w linesp t "Norma",\
"perf.gpdat" u 1:4 w linesp t "Soma"
