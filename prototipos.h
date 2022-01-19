//////////////////////////////////////////////////////////////////////////////////////////////

// PROTOTIPOS
void avaliaExpressao(char[], int[], char[], int*, int*);

void pushInt(int[], int, int*);
void pushChar(char[], char, int*);
void popInt(int[], int*);
void popChar(char[], int*);

void leExpressao(); // Entrada

int eNumero(char);
int eSinal(char);
int descobreTipoExpressao(char[], int[]); // Descobrir se e INFIXA ou POSFIXA

void desempilha(int[], char[], int*, int*, char);

void imprimeTitulo();
void imprimeExpressao(char[]);

void limpaChar(char[]); // Limpam o lixo de
void limpaInt(int[]);   // Vetores caracteres e inteiros
int eleva(int, int);
