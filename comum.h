//////////////////////////////////////////////////////////////////////////////////////////////

// PILHAS

void pushInt(int p[], int el, int *pt) {
	if(*pt == MAX-1) {
		printf("\n\tERRO -> Pilha cheia");
	}
	else {
		*pt = *pt + 1;		
		p[*pt] = el;		
	}
}

void pushChar(char s[], char el, int *ptc) {
	if(*ptc == MAX-1) {
		printf("\n\tERRO -> Pilha cheia");
	}
	else {
		*ptc = *ptc + 1;		
		s[*ptc] = el;		
	}
}

void popInt(int p[], int *pt) {
	if(*pt == -1) {
		printf("\n\tERRO -> Pilha vazia");
	}
	else {
		*pt = *pt - 1;
	}
}

void popChar(char s[], int *ptc) {
	if(*ptc == -1) {
		printf("\n\tERRO -> Pilha vazia");
	}
	else {
		*ptc = *ptc - 1;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

// LEITURA

void leExpressao(char e[]) {
	int i;
	char c, texto[] = " Entre com uma expressao na forma:\n\n\t- INFIXA (totalmente parentizada) ou \n\t- POSFIXA\n\n Entre com Q para finalizar\n\n\t";
	printf("%s", texto);	
	i = 0;
	while(c != 'q' && c != 'Q') {
		printf("\t");
		c = getchar();
		if(	(c >= '0' && c <= '9') || 
			(c == ' ' || c == '_' || c == '(' || c == ')' || 
			(c == '+' || c == '-' || c == '*' || c == '/' || c == '$'))) {
			e[i] = c;
			i++;
		}
		else {
			system("clear");
			imprimeTitulo();
			printf("%s", texto);	
			imprimeExpressao(e);	
			continue;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////

// TESTES

int eNumero(char c) {
	return (c >= '0' && c <= '9');
}

int eSinal(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}
//////////////////////////////////////////////////////////////////////////////////////////////

// IMPRESSOES	
		
void imprimeExpressao(char e[]) {
	int i;
	for(i=0; i<MAX && e[i]!=ESCAPE; i++) {
		printf("%c", e[i]);
	}
}	

void imprimeTitulo() {
	printf("\n=============================================================\n\tTrabalho de Estruturas de Dados I\n=============================================================\n\n");
}	
//////////////////////////////////////////////////////////////////////////////////////////////

// OUTRAS

void limpaChar(char e[]) {
	int i;
	for(i=0; i<MAX; i++) {
		e[i] = ESCAPE;
	}
}

void limpaInt(int e[]) {
	int i;
	for(i=0; i<MAX; i++) {
		e[i] = -1;
	}
}

int eleva(int x, int e) {
	int r = x;
	if(e == 0) {
		return 1;
	}
	while(e > 1) {
		r *= x;
		e--;
	}
	return r;		
}
