#define MAXFILA 2000

struct TpElemento{
	char id[100], cor[100], montadora[100], prioridade; 
};

struct TpFilaP{
	int fim;
	TpElemento fila[MAXFILA];
};

void inicializar(TpFilaP &Fila){
	Fila.fim = -1;
}

char FilaVazia(int fim){
	return fim == -1;
}

char FilaCheia(int fim){
	return fim == MAXFILA - 1;
}

void inserir(TpFilaP &Fila, TpElemento Elem){
	TpElemento aux;
	Fila.fila[++Fila.fim] = Elem;
	
	if(!FilaVazia(Fila.fim))
		for(int i = Fila.fim; i > 0 && Fila.fila[i].prioridade < Fila.fila[i - 1].prioridade; i--){
			aux = Fila.fila[i];
			Fila.fila[i] = Fila.fila[i - 1];
			Fila.fila[i - 1] = aux;
		}
}

TpElemento retirar(TpFilaP &Fila){
	TpElemento Elem = Fila.fila[0];
	for(int i = 0; i < Fila.fim; i++)
		Fila.fila[i] = Fila.fila[i + 1];
	
	Fila.fim--;
	
	return Elem;
}

TpElemento ElemInicio(TpFilaP Fila){
	return Fila.fila[0];
}

TpElemento ElemFim(TpFilaP Fila){
	return Fila.fila[Fila.fim];
}

void exibeFila(TpFilaP Fila){
	TpElemento Reg;
	while(!FilaVazia(Fila.fim)){
		Reg = retirar(Fila);
		printf("Id: %s\tCor: %s\nMontadora: %s\tPrioridade: %c\n\n", Reg.id, Reg.cor, Reg.montadora, Reg.prioridade);
	}
}
