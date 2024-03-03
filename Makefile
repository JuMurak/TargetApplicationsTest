
ex2:
	gcc pergunta2.c -o pergunta2

ex3:
	gcc pergunta3.c -I/usr/local/include -I/usr/local/include/cjson -L/usr/local/lib -lcjson -lm -o pergunta3

ex4:
	gcc pergunta4.c -o pergunta4

ex5:
	gcc pergunta5.c -o pergunta5

all: ex2 ex3 ex4 ex5

