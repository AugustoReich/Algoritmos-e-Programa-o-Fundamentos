#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char opcao;
    int populacao_total, pessoas_inicialmente_infectadas, taxa_contagio;
    int porcentagem_vacinada, efetividade_da_vacina, dias_simulacao;
    int total_infectadas, novos_infectados, infectados_hoje;
    int vacinados, vacinados_saudaveis, nao_vacinados_saudaveis, suscetiveis;
    int vacinados_infectados = 0;

    srand(time(0));

    printf("1 - Nova Simulação\n");
    printf("2 - Sair do Programa\n");
    printf("Escolha uma Opção: ");
    scanf(" %c", &opcao);

    if (opcao == '1') {
        printf("Digite a população total: ");
        scanf("%d", &populacao_total);
        printf("Digite o número de pessoas inicialmente infectadas: ");
        scanf("%d", &pessoas_inicialmente_infectadas);
        printf("Digite a porcentagem da taxa de contágio: ");
        scanf("%d", &taxa_contagio);
        printf("Digite a porcentagem da população vacinada: ");
        scanf("%d", &porcentagem_vacinada);
        printf("Digite a efetividade da vacina em porcentagem: ");
        scanf("%d", &efetividade_da_vacina);
        printf("Digite o número de dias da simulação: ");
        scanf("%d", &dias_simulacao);

        vacinados = (populacao_total * porcentagem_vacinada) / 100;
        vacinados_saudaveis = vacinados;
        nao_vacinados_saudaveis = populacao_total - vacinados - pessoas_inicialmente_infectadas;

        total_infectadas = pessoas_inicialmente_infectadas;

        printf("\nIniciando Simulação\n");
        
        int dia;
        dia = 1;
        int evento;
        int taxa_contagio_dia;
        char evento_nome[50] = "";
        for (dia = 1; dia <= dias_simulacao; dia++)
        {
            evento = rand() % 100 + 1;
            taxa_contagio_dia = taxa_contagio;
            
            if (evento <= 5) 
            {
                taxa_contagio_dia = taxa_contagio_dia + 50;
                sprintf(evento_nome, "Mutação mais contagiosa!");
            } else if (evento <= 10) {
                taxa_contagio_dia = taxa_contagio_dia - 30;
                sprintf(evento_nome, "Mídia gera alerta!");
            } else if (evento <= 20) {
                taxa_contagio_dia = taxa_contagio_dia - 20;
                sprintf(evento_nome, "Isolamento voluntário.");
            } else if (evento <= 35) {
                taxa_contagio_dia = taxa_contagio_dia + 25;
                sprintf(evento_nome, "Aglomeração!");
            }

            if (taxa_contagio_dia < 0) taxa_contagio_dia = 0;
            if (taxa_contagio_dia > 100) taxa_contagio_dia = 100;

            suscetiveis = nao_vacinados_saudaveis + (vacinados_saudaveis * (100 - efetividade_da_vacina)) / 100;

            if (suscetiveis <= 0) {
                printf("\nTodos os suscetíveis foram infectados. Simulação encerrada no dia %d.\n", dia);
            }

            novos_infectados = (total_infectadas * taxa_contagio_dia) / 100;

            if (novos_infectados > suscetiveis) 
            {
                novos_infectados = suscetiveis;
            }

            infectados_hoje = novos_infectados;
            total_infectadas = total_infectadas + infectados_hoje;

            int possiveis_vacinados_infectados = (vacinados_saudaveis * (100 - efetividade_da_vacina)) / 100;
            if (infectados_hoje > nao_vacinados_saudaveis) {
                int infectados_vacinados = infectados_hoje - nao_vacinados_saudaveis;
                if (infectados_vacinados > possiveis_vacinados_infectados) 
                {
                    infectados_vacinados = possiveis_vacinados_infectados;
                }
                vacinados_saudaveis = vacinados_saudaveis - infectados_vacinados;
                vacinados_infectados = vacinados_infectados + infectados_vacinados;
                nao_vacinados_saudaveis = 0;
            } else {
                nao_vacinados_saudaveis = nao_vacinados_saudaveis - infectados_hoje;
            }
            
            printf("Dia %d: %d infectados (+%d)", dia, total_infectadas, infectados_hoje);
            if (evento_nome[0] != '\0') {
                printf(" (evento: %s)", evento_nome);
            }
            printf("\n");
        }
        
        int saudaveis_restantes = populacao_total - total_infectadas;
        printf("\nResultado Final\n");
        printf("População: %d\n", populacao_total);
        printf("Total infectados: %d\n", total_infectadas);
        printf("População vacinada: %d\n", vacinados);
        printf("Vacinados infectados: %d\n", vacinados_infectados);
        printf("População saudável: %d\n", saudaveis_restantes);
    } else {
        printf("Programa encerrado.\n");
    }

    return 0;
}