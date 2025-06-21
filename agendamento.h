
/*
** Fun��o : Sistema de Agendamento de Consultas M�dicas
** Autor : Erick e Daysila
** Data : 18/06/2025
** Observa��es: Interface do sistema de agendamento: defini��o do TAD para agendamento do m�dico e enfermeiro com informa��es de nome, data e hora do paciente
*/

#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#define MAX_NOME 100
#define MAX_DATA 15
#define MAX_HORA 10
#define MAX_MEDICO 5  

typedef struct {
    char nome[MAX_NOME];
    char data[MAX_DATA];
    char hora[MAX_HORA];
} Paciente;


typedef struct {
    Paciente pacientes[MAX_MEDICO]; //FILA ET�TICA
    int inicio;
    int fim;
    int tamanho;
} FilaMedico;


typedef struct NoEnfermagem { //N�
    Paciente paciente;
    struct NoEnfermagem *proximo;
} NoEnfermagem;


typedef struct {
    NoEnfermagem *inicio;  //FILA DINAMICA
    NoEnfermagem *fim;
    int tamanho;
} FilaEnfermagem;


FilaMedico* criarFilaMedico();
int agendarMedico(FilaMedico *fila, char *nome, char *data, char *hora);
int atenderMedico(FilaMedico *fila);
void listarAgendamentosMedico(FilaMedico *fila);
int filaCheiaMedico(FilaMedico *fila);
int filaVaziaMedico(FilaMedico *fila);

void liberarFilaMedico(FilaMedico *fila);


FilaEnfermagem* criarFilaEnfermagem();
int agendarEnfermagem(FilaEnfermagem *fila, char *nome, char *data, char *hora);
int atenderEnfermagem(FilaEnfermagem *fila);
void listarAgendamentosEnfermagem(FilaEnfermagem *fila);
int filaVaziaEnfermagem(FilaEnfermagem *fila);

void liberarFilaEnfermagem(FilaEnfermagem *fila);



void mostrarStatusFilas(FilaMedico *filaMedico, FilaEnfermagem *filaEnfermagem);

#endif

