#include "AGMI.h"

int main(int argc, char const *argv[]){
	
	Grafo G = leitura(argv[1]);

	Prim(G, pesoVertice);

	GRAFOdestroi(G);


	return 0;
}
