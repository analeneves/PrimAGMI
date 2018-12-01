AGMI:	mainAGMI.c	AGMIfuncoes.c
	gcc mainAGMI.c AGMIfuncoes.c -o mainAGMI

AGM:	mainAGM.c	AGMfuncoes.c
	gcc mainAGM.c AGMfuncoes.c -o mainAGM

cleanAGMI: mainAGMI
	rm -rf mainAGMI

cleanAGM: mainAGM
	rm -rf mainAGM
