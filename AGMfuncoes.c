#include "AGM.h"


/* Cria um grafo */
Grafo GRAFOcria(int n){
    Grafo G = (Grafo) malloc(sizeof(Grafo));
    G->n = n;
    G->m = 0;
    G->adj = MATRIZint(n,n);

    return G;
}


/* Cria matriz [ l ] [ c ] vazia */
int **MATRIZint(int l, int c){
    int i, j;
    int ** m = (int **) malloc(l * sizeof(int *));
    for (i = 0; i < l; i++)
        m[i] = (int *) malloc(c * sizeof(int));
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            m[i][j] = 0;
    return m;
}
/* Insere uma aresta e no grafo G */
void GRAFOinsereE(Grafo G, Aresta e, int peso){
    int v = e.v;
    int w = e.w;
    if (G->adj[v][w] == 0) {
        G->m++;
        G->adj[v][w] = peso;
        G->adj[w][v] = peso;
    }
}

/* Funcao para destruir um grafo */
void GRAFOdestroi(Grafo G){
    int i;
    for (i = 0; i < G->n; i++) {
        free(G->adj[i]);
    }
    free(G->adj);
    free(G);
}

/* Execução do algoritmo prim com peso nos vertices internos */

void Prim(Grafo G, int *pesoVertice){
    int min, k = -1, l = -1;
    int *pai = malloc(G->n * sizeof(int));
    int custo = 0;
    int v,j;
    Aresta e;
    Grafo AGM = GRAFOcria(G->n);
    AGM->m = G->m;
    for(int i = 0 ; i < G->n ; i++){
    	for(int j = 0 ; j < G->n ; j++){
    		if( G->adj[i][j] == 0 ){
    			AGM->adj[i][j] = INF;
    		}else{
    			AGM->adj[i][j] = G->adj[i][j];
    		}
    	}
    }
    for(int v = 0; v < G->n ; v++){
    	pai[v] = -1;
    }
    pai[0] = 0;

    while(1){

        min = INF;

      	for (j = 0; j< G->n; j++) {
	        if(pai[j] != -1){
	    		for (v = 0; v < G->n; v++) {

		            if(pai[v] == -1 && min > AGM->adj[j][v]){
		            	min = AGM->adj[j][v];
				  		    k = j;
		            	l = v;
		            }
		        }
	      	}
	    }
	    if(min == INF){
	    	break;
	  	}

	  	printf("Aresta %d %d\n", k, l);
    	custo = custo + G->adj[k][l];

		pai[l] = k;

	}


    //GRAFOimprime(AGM);
    printf("** Custo AGM: %d\n", custo);
}

/*Leitura do arquivo*/

Grafo leitura(const char *nomeDoArquivo){

	FILE *arq;

	arq = fopen(nomeDoArquivo, "r");
	if(arq == NULL){
		perror("Não leu o arquivo!");
	}


	char buffer[1024];

	Aresta e;
	char *token;

	fgets(buffer, 1024, arq);

	int n, m;

	token = strtok(buffer, " ");
	n = atoi(token);
	token = strtok( NULL, " " );
	m = atoi(token);

	fgets(buffer, 1024, arq);

	pesoVertice = (int*)malloc(n*sizeof(int));

	Grafo G = GRAFOcria(n);

	int flagAresta = 0;
	int i = 0;

	int verticeA, verticeB;

	while(!feof(arq)){
		fgets(buffer, 1024, arq);

		if ( strcmp("-1\n", buffer) == 0){
			flagAresta = 1;
			continue;
		}
		if( flagAresta == 0 ){
			token = strtok(buffer, " ");
			token = strtok( NULL, " " );
			token = strtok( NULL, " " );
			pesoVertice[i] = atoi(token);
		}

		if( flagAresta == 1 ){
			if( strlen(buffer) < 5 ){
				break;
			}
			token = strtok(buffer, " ");
			e.v = atoi(token);
			token = strtok( NULL, " " );
			e.w = atoi(token);
			token = strtok( NULL, " " );

			GRAFOinsereE(G, e, atoi(token));
		}
		i++;
	}
	return G;
}


/*imprime um grafo G*/
void GRAFOimprime(Grafo G) {
    int v, w;

    if (G != NULL){
    	printf("%d vertices, %d arestas\n", G->n, G->m);
    	for (v = 0; v < G->n; v++) {
            for (w = 0; w < G->n; w++){
            	printf( " %2d", G->adj[v][w]);
            }
            printf( "\n");
    	}
    }
    else{
      getchar();
	//printf("%p\n", G);
    }
}
