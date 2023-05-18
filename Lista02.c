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


int main(){

    struct Professor{
        char nome[50];
        char funcional[15];
        char titulacao[12];
    };

/*     struct Disciplina{
        char nome[50];
        int codigo;
        int carga_horaria;
        char professor_responsavel[50];
    };

    struct Estudante{
        char nome[50];
        char matricula[30];
        int idade;
    }; */

    struct Professor professor[3];

    int i=0, opcao=0;

    printf("\t\tCadastro Professor\n");

    for(i=0;i<3;i++){
        printf("\nNome: ");
        scanf(" %[^\n]s", &professor[i].nome);
        printf("Funcional: ");
        scanf(" %[^\n]s", &professor[i].funcional);
        printf("Titulacao\n");
        printf("\t[1] Especialista\n");
        printf("\t[2] Mestre\n");
        printf("\t[3] Doutor\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
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


/*     
    printf("\n\nCadastro Disciplina\n");
    printf("\n\nCadastro Estudante\n");



 */

        


    return 0;
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