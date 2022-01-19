// Gustavo Henrique Mello Dauer
//
// Trabalho de Estruturas de Dados I
// Avaliar uma expressao INFIXA (totalmente parentizada)
// ou POSFIXA dada pelo usuario
// Deve funcionar para qualquer entrada de numeros

#define MAX 2500
#define MAX_DIGITOS 2500
#define INFIXA 1
#define POSFIXA 0
#define ESCAPE '\t' // SO FUNCIONA COM '\n' '\t'
					// COM ' ' ou qualquer outro caractere da bug em INFIXA e/ou POSFIXA
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"
#include "comum.h"

int tipoExp;

int main(void) {
	int pilha[MAX], topoPilhaI = -1, topoPilhaC = -1, *ptc = &topoPilhaC, *pt = &topoPilhaI;
	char exp[MAX], sinais[MAX];	
	imprimeTitulo();
	limpaChar(exp);
	leExpressao(exp);
	tipoExp = descobreTipoExpressao(exp, pilha);	
	avaliaExpressao(exp, pilha, sinais, pt, ptc);
	return 0;
}

int descobreTipoExpressao(char e[], int p[]) {
	int i;
	printf("\n\n O tipo da expressao eh: ");
	for(i=0; i<MAX && e[i]!=' '; i++) {
		if(e[i] == '(' || e[i] == ')') {
			printf("INFIXA\n\n");						
			return INFIXA;
		}
	}
	printf("POSFIXA\n\n");
	return POSFIXA;
}	

void avaliaExpressao(char e[], int p[], char s[], int *pt, int *ptc) {
	int i, k, m;
	char operando[MAX_DIGITOS]; // Armazena os algarismos dos numeros
	char prox;	
	limpaInt(p);
	limpaChar(s);
	k=0, m=0;
	for(i=0; i<MAX && e[i]!=ESCAPE; i++) {
		if((i+1) < MAX) {
			prox = e[i+1];
		}
		else {
			printf("\n ERRO -> ESTOURO!");
			return;
		}
		if(eNumero(e[i])) { // Descobre se é um numero
			limpaChar(operando);			
			k = i;
			while(eNumero(e[k])) { // Enquanto nao encontrar espaco ou sinais, trata-se de um numero
				operando[m] = e[k];
				k++;
				m++;
			}
			k--; // NECESSARIO! Do contrario i sera incrementado 2 vezes e pulara 1 sinal ou 1 fecha parenteses
			operando[m] = '\0';			
			pushInt(p, atoi(operando), pt); // Número salvo na pilha de inteiros		
			printf("\n -> %d Salvo na pilha de inteiros", atoi(operando));
			i += k - i; // Se e[k] não for número isso é igual a i+0
			if(tipoExp == INFIXA && prox == ESCAPE) {
				desempilha(p, s, pt, ptc, prox);
			}										
		}
		else {
			if(tipoExp == INFIXA) {
				if(eSinal(e[i])) {
					pushChar(s, e[i], ptc);
					printf("\n -> %c Salvo na pilha de sinais", e[i]);			
				}		
				else if (e[i] == ')') {
						//printf("\nCalcular o primeiro parenteses");		
						desempilha(p, s, pt, ptc, prox);													
				}
			}
			else if(tipoExp == POSFIXA) {
				if(eSinal(e[i])) {
					pushChar(s, e[i], ptc);
					printf("\n -> %c Salvo na pilha de sinais", e[i]);
					desempilha(p, s, pt, ptc, prox);				
				}		
				else if (e[i] == ESCAPE) {					
						desempilha(p, s, pt, ptc, prox);													
				}	
			}				
		}				
	}
}	

void desempilha(int p[], char s[], int *pt, int *ptc, char prox) {
	printf("\n -> Desempilhando");
	switch(s[*ptc]) {
		case '+': p[*pt-1] = p[*pt-1] + p[*pt]; break;
		case '-': p[*pt-1] = p[*pt-1] - p[*pt]; break;
		case '*': p[*pt-1] = p[*pt-1] * p[*pt]; break;
		case '/': p[*pt-1] = p[*pt-1] / p[*pt]; break;
		case '$': p[*pt-1] = eleva(p[*pt-1], p[*pt]); break;	
	}
	popInt(p, pt);
	popChar(s, ptc);	
	if(*ptc == -1 && prox == ESCAPE) {
		printf("\n----------------------------------------------------------------------------\n\tResultado: %d", p[*pt]);
	}
	else if(prox == ESCAPE) {
		printf("\n----------------------------------------------------------------------------\n\tOps! Erros na digitacao da expressao!\n\tEla esta na forma INFIXA (totalmente parentizada)?\n\tEla foi escrita corretamente na forma POSFIXA?\n\n\tResultado: %d (Provavelmente errado)", p[*pt]);
	}
}			
