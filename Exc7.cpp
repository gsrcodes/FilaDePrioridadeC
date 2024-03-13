#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "tadFilaP.h"

int main(void){
	int acao;
	TpElemento Reg;
	TpFilaP Fila;
	FILE *PtrArq = fopen("DadosVeiculos.txt", "r");
	inicializar(Fila);
	
	srand (time(NULL));
	
	
	do {
		system("cls");
		acao = rand() % 2;
		if(acao == 0 && FilaVazia(Fila.fim))
			acao = 1;
		if (acao == 1 && feof(PtrArq)) {
			rewind(PtrArq);
			inicializar(Fila);
		}
		
		if (acao == 1 && !FilaCheia(Fila.fim)){
			fscanf(PtrArq ,"%[^;];%[^;];%[^;];%c", &Reg.id, &Reg.cor, &Reg.montadora, &Reg.prioridade);
			inserir(Fila, Reg);
			exibeFila(Fila);
			printf("\nInseriu\n");
		}
		else if (!FilaVazia(Fila.fim)){
			retirar(Fila);
			exibeFila(Fila);
			printf("\nRemoveu\n");
		}
		Sleep(600);
	} while (!kbhit());
	fclose(PtrArq);
}
