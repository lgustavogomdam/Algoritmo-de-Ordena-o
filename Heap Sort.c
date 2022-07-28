#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*  Trabalho de Heap Sort
    Nome: Luiz Gustavo Gomes Damasceno
    Turma:V01 - Sistemas de Informação - IFES Campus Colatina
    Disciplina de Programação 2
*/

typedef struct Fabricante {

    char nome[100];
    char nacionalidade[100];
    int anoFundacao;

}Fabricante;

int ultimoFab(Fabricante x, Fabricante y) {

	//Nome do Fabricante / Nacionalidade do Fabricante / Ano do Fabricante

	if(strcmp(x.nome,y.nome)<0){
		return 1;

    }else if(strcmp(x.nome,y.nome)==0){
		if(strcmp(x.nacionalidade,y.nacionalidade)<0)
			return 1;

		else if(strcmp(x.nacionalidade,y.nacionalidade)==0){
			if(x.anoFundacao < y.anoFundacao)
				return 1;
			else
				return 0;
			
        }else
			return 0;

	}else
		return 0;

}

void troca(Fabricante *x, Fabricante *y){
	Fabricante aux;
	aux = *x;
	*x = *y;
	*y = aux;
}

int FilhoEsquerda(int raiz){
	return 2*raiz+1;
}

int FilhoDireita(int raiz){
	return 2*raiz+2;
}

void heapify(Fabricante *x, int qt_x, int indice_raiz){
	int esquerda = FilhoEsquerda(indice_raiz);
	int direita = FilhoDireita(indice_raiz);
	int max;

	if (esquerda > qt_x-1)
		return;
	else if (direita>qt_x-1)
		max=esquerda;
	else{
		if (ultimoFab(x[direita],x[esquerda]))
			max=esquerda;
		else
			max=direita;
	}
    
	if(ultimoFab(x[indice_raiz], x[max])){
		troca(&x[max], &x[indice_raiz]);
		heapify(x, qt_x, max);
	}
}

void construirHeap(Fabricante *x, int qt_x){
	int i;
	for(i=qt_x/2-1;i>=0; i--){
		heapify(x, qt_x, i);
	}
}

void HeapSort(Fabricante *x, int qt_x){
	int i;
	construirHeap(x, qt_x);
	for (i=qt_x-1; i>0; i--){
		troca(&x[i], &x[0]);
		heapify(x, i, 0);
	}
}

void imprimirDados(Fabricante *x, int cont) {
    int i;

    for (i=0; i < cont; i++){
        printf ("\nNome: %s  -  Nacionalidade: %s  -  Fundação: %d", x[i].nome, x[i].nacionalidade, x[i].anoFundacao);
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    int contFab = 6;
    Fabricante fab[contFab];
     
	//Nomes dos Fabricantes

    strcpy(fab[0].nome, "Dell");
    strcpy(fab[1].nome, "Acer");
    strcpy(fab[2].nome, "Samsung");
    strcpy(fab[3].nome, "Sony");
    strcpy(fab[4].nome, "Apple");
    strcpy(fab[5].nome, "HP");

    //Nacionalidades dos Fabricantes

    strcpy(fab[0].nacionalidade, "Estados Unidos");
    strcpy(fab[1].nacionalidade, "Taiwan");
    strcpy(fab[2].nacionalidade, "Coreia do Sul");
    strcpy(fab[3].nacionalidade, "Japão");
    strcpy(fab[4].nacionalidade, "Estados Unidos");
    strcpy(fab[5].nacionalidade, "Estados Unidos");

    //Ano de Fundação dos Fabricantes

    fab[0].anoFundacao = 1984;
    fab[1].anoFundacao = 1976;
    fab[2].anoFundacao = 1969;
    fab[3].anoFundacao = 1946;
    fab[4].anoFundacao = 1976;
    fab[5].anoFundacao = 1998;

    //Impressão dos Fabricantes

    printf ("\nDados dos Fabricantes:\n");
    imprimirDados(fab, contFab);

    //Chamada de ordenação dos Fabricantes

    HeapSort(fab, contFab);
    
    //Impressão dos Fabricantes em ordem alfabética

    printf ("\n\nDados dos Fabricantes por ordem alfabética:\n");
    imprimirDados(fab, contFab);
}