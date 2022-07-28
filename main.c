#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*  Trabalho de Shell Sort
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

void InsertionSortAdaptado(Fabricante *x, int n, int f, int h){

    //Criação e chamada de Variáveis

	int i, j, k;
	Fabricante v;

	for (i=f+h;i < n;i=i+h){
		v = x[i];
		k = f;
		j = i - h;
		
		while((j>=f) && (k==f)){

			if(ultimoFab(v,x[j])){
				x[j + h] = x[j];
				j = j-h;	
			}else
				k = j + h;
		}
		x[k] = v;
	}
}

void ShellSort(Fabricante *x,int n,int np){
    int h,j,p;

    for(p=np; p > 0; p--){
        h = (int)pow(2.0,(int)p-1);
        for(j=0;j<h;j++)
            InsertionSortAdaptado(x, n, j, h);
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

    ShellSort(fab, contFab,2);
    
    //Impressão dos Fabricantes em ordem alfabética

    printf ("\n\nDados dos Fabricantes por ordem alfabética:\n");
    imprimirDados(fab, contFab);
}