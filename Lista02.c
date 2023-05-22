/* 

Entrada:    Professor   {
                            nome
                            funcional
                            titulacao (especialista, mestre ou doutor)
                        }
            Disciplina  {
                            nome
                            codigo
                            carga_horaria
                            professor_responsavel (escolhido dentre professores cadastrados)
                        }
            Estudante   {
                            nome
                            matricula
                            idade
                        }


 */


#include <stdio.h>
#include <string.h>
#define TAMESTU 15
#define TAMDISC 2
#define TAMPROF 3

typedef struct{
    char nome[50];
    char funcional[20];
    char titulacao[15];
}Professor;

typedef struct{
    char nome[50];
    int codigo;
    int carga_horaria;
    Professor professor;
}Disciplina;

typedef struct{
    char nome[50];
    char matricula[30];
    int idade;
    Disciplina disciplina;
}Estudante;

int le_valida_idade();
char le_valida_titulacao();
void ordem_crescente(Estudante vetor[], Estudante sub, int tamanho_vetor);
void ordem_decrescente(Estudante vetor[], Estudante sub, int tamanho_vetor);
void imprime_vetor(Estudante vetor[], int tamanho_vetor, Disciplina disciplina[], int a);

int main(){

    Professor professor[TAMPROF];
    Disciplina disciplina[TAMDISC];
    Estudante estudante[TAMESTU], sub;


    int i=0, opcao=0, qtd_alunos=0, materia1=0, materia2=0;

    printf("\t\tCadastro Professor\n");

    for(i=0;i<TAMPROF;i++){
        printf("\nNome: ");
        scanf(" %[^\n]s", &professor[i].nome);
        printf("Funcional: ");
        scanf(" %[^\n]s", &professor[i].funcional);
        
        do{
            printf("Titulacao\n");
            printf("\t[1] Especialista\n");
            printf("\t[2] Mestre\n");
            printf("\t[3] Doutor\n");
            opcao =0;
            printf("Escolha: ");
            scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        switch (opcao){
        case 1 :
            strcpy(professor[i].titulacao, "Especialista");
            break;
        
        case 2 :
            strcpy(professor[i].titulacao, "Mestre");
            break;
        case 3 :
            strcpy(professor[i].titulacao, "Doutor");
            break;
        }
        
    }

    system("cls");
    printf("\n\n\tCadastro Disciplina\n");

    for(i=0;i<TAMDISC;i++){
        printf("\nNome: ");
        scanf(" %[^\n]s", &disciplina[i].nome);
        printf("Codigo: ");
        scanf("%d", &disciplina[i].codigo);
        printf("Carga Horaria: ");
        scanf("%d", &disciplina[i].carga_horaria);
        
        do{
            printf("Professor Responsavel\n");
            printf("\t[1]%s\n", professor[0].nome);
            printf("\t[2]%s\n", professor[1].nome);
            printf("\t[3]%s\n", professor[2].nome);
            printf("Escolha: ");
            scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);
        
        switch (opcao){
        case 1 :
            disciplina[i].professor = professor[0];
            break;
        
        case 2 :
            disciplina[i].professor = professor[1];
            break;
        case 3 :
            disciplina[i].professor = professor[2];
            break;
        }
                
    }

    system("cls");
    printf("\n\n\tCadastro Estudante\n");
    i=0;
    do{

        printf("\n\nNome: ");
        scanf(" %[^\n]s", &estudante[i].nome);
        estudante[i].idade = le_valida_idade();
        
        printf("Matricula: ");
        scanf(" %[^\n]s", &estudante[i].matricula);

        do{ 
            if(materia1<10 && materia2<10){ 
                printf("Disciplina\n");
                printf("\t[1] - %s\n\t[2] - %s\n", disciplina[0].nome, disciplina[1].nome);  
                printf("Escolha: ");
                scanf("%d", &opcao);
            }else{
                if (materia1==10){
                    do{
                        printf("Disciplina\n");
                        printf("\t[2] - %s\n", disciplina[1].nome);  
                        printf("Escolha: ");
                        scanf("%d", &opcao);
                    }while(opcao != 2);
                }
                if (materia2==10){
                    do{
                        printf("Disciplina\n");
                        printf("\t[1] - %s\n", disciplina[0].nome);  
                        printf("Escolha: ");
                        scanf("%d", &opcao);
                    }while(opcao != 1);
                }
            }
        }while(opcao != 1 && opcao != 2);

        switch (opcao){
        case 1:
            estudante[i].disciplina = disciplina[0];
            materia1++;
            break;
        case 2:
            estudante[i].disciplina = disciplina[1];
            materia2++;
            break;
        }

        do{
            printf("Deseja continuar cadastrando\n");
            printf("\t[1] Sim\n\t[2] Nao\n");
            printf("Escolha: ");
            scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2);
        qtd_alunos++;
        i++;
    }while(opcao != 2 && qtd_alunos != TAMESTU);


    //Ordenamento vetor estudantes Disciplina 1
    ordem_crescente(estudante, sub, qtd_alunos);
    
    system("cls");
    // Relatorio Disciplina 1
    printf("\n-------------------------------------------------------------\n");
    printf("              Relatorio da Disciplina %s\n", disciplina[0].nome);
    imprime_vetor(estudante, qtd_alunos, disciplina, 0);
    printf("\n-------------------------------------------------------------\n");    
    
    //Ordenamento vetor estudantes Disciplina 2
    ordem_decrescente(estudante, sub, qtd_alunos);
    


    //Relatorio Disciplina 2
    printf("\n-------------------------------------------------------------\n");
    printf("              Relatorio da Disciplina %s\n", disciplina[1].nome);
    imprime_vetor(estudante, qtd_alunos, disciplina, 1);
    printf("\n-------------------------------------------------------------\n");

    return 0;
}

int le_valida_idade(){
    int idade=0, count=0;
    
    do{
        if(count>0){
            printf("----------ERRO----------\n");
            printf("Idade entre 16 e 26 anos\n");
            printf("------------------------\n");
        }
        printf("Idade: ");
        scanf("%d", &idade);
        count++;
    }while(idade <16 || idade >26);
    return idade;
}

void ordem_crescente(Estudante vetor[], Estudante sub, int tamanho_vetor){
    int i=0,j=0;
    
    for(i=0;i<tamanho_vetor;i++){
        for(j=0;j<tamanho_vetor-i-1;j++){
            if(vetor[j].idade>vetor[j+1].idade){
                sub = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = sub;
            }
        }
    }

}

void ordem_decrescente(Estudante vetor[], Estudante sub, int tamanho_vetor){
    int i=0,j=0;
    
    for(i=0;i<tamanho_vetor;i++){
        for(j=0;j<tamanho_vetor-i-1;j++){
            if(vetor[j].idade<vetor[j+1].idade){
                sub = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = sub;
            }
        }
    }

}

void imprime_vetor(Estudante vetor[], int tamanho_vetor, Disciplina disciplina[], int a){
    int i=0;

    for(i=0;i<tamanho_vetor;i++){
        if(strcmp(vetor[i].disciplina.nome, disciplina[a].nome) == 0){
            printf("Codigo Disciplina: %d\tProfessor: %s\t Estudante: %s\t Idade: %d\n", vetor[i].disciplina.codigo, vetor[i].disciplina.professor.nome, vetor[i].nome, vetor[i].idade);
        }
    }


}



/* 
Elabore um programa utilizando as estruturas Professor, Disciplina e Estudante.

Professor (nome, funcional, titulacao (especialista, mestre ou doutor)).
Disciplina (nome, codigo, carga_horaria, professor_responsavel (escolhidos dentre os professores cadastrados)).
Estudante (nome, matricula, idade).

Serão cadastrados 3 professores, 2 disciplinas e no máximo 15 estudantes distribuídos entre as duas disciplinas, uma disciplina não poderá ter mais que 10 estudantes matriculados.

Apresente um relatório dos alunos matriculados na primeira disciplina ordenados por idade.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Apresente um relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Utilize o bubble sort para ordenação utilizano um procedimento com passagem de parâmetros por referência.

Idade do estudante deverá estar validada entre 16 e 26 por meio de uma função le_valida_idade.
 */