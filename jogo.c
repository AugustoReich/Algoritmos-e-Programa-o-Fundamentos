#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_JOGADORES 5
#define VIDA_INICIAL 100

typedef struct {
    char classe[20];
    int vida;
    int ataque;
    int defesa;
    int habilidade_ativa;
} Personagem;

void inicializarTime(Personagem time[], int numeroTime);
int escolherAtacante(Personagem time[]);
int sortearAlvo(Personagem time[]);
int calcularDano(Personagem *atacante, Personagem *defensor);
void aplicarHabilidade(Personagem *atacante, Personagem *defensor, int *dano);
void imprimirEstado(Personagem t1[], Personagem t2[], int rodada);
int timeVivo(Personagem time[]);

int main() {
    Personagem time1[NUM_JOGADORES];
    Personagem time2[NUM_JOGADORES];

    srand(time(NULL));

    inicializarTime(time1, 1);
    inicializarTime(time2, 2);

    int rodada = 1;
    int turno = rand() % 2;

    while (timeVivo(time1) && timeVivo(time2)) {
        printf("Rodada %d:\n", rodada);

        if (turno == 0) {
            int idxAtacante = escolherAtacante(time1);
            int idxAlvo = sortearAlvo(time2);
            int dano = calcularDano(&time1[idxAtacante], &time2[idxAlvo]);

            printf("Time 1 — %s (Vida: %d) ataca %s do Time 2 (Vida: %d)\n",
                   time1[idxAtacante].classe, time1[idxAtacante].vida,
                   time2[idxAlvo].classe, time2[idxAlvo].vida);

            if (dano == -1) {
                printf("Ataque errou! Nenhum dano aplicado.\n");
            } else {
                printf("Dano aplicado: %d\n", dano);
                time2[idxAlvo].vida -= dano;
                if (time2[idxAlvo].vida < 0) time2[idxAlvo].vida = 0;
            }

        } else {
            int idxAtacante = escolherAtacante(time2);
            int idxAlvo = sortearAlvo(time1);
            int dano = calcularDano(&time2[idxAtacante], &time1[idxAlvo]);

            printf("Time 2 — %s (Vida: %d) ataca %s do Time 1 (Vida: %d)\n",
                   time2[idxAtacante].classe, time2[idxAtacante].vida,
                   time1[idxAlvo].classe, time1[idxAlvo].vida);

            if (dano == -1) {
                printf("Ataque errou! Nenhum dano aplicado.\n");
            } else {
                printf("Dano aplicado: %d\n", dano);
                time1[idxAlvo].vida -= dano;
                if (time1[idxAlvo].vida < 0) time1[idxAlvo].vida = 0;
            }
        }

        imprimirEstado(time1, time2, rodada);
        rodada++;
        turno = 1 - turno;
    }

    printf("\nFim da Batalha\n");
    if (timeVivo(time1) && !timeVivo(time2)) {
        printf("Vitória do Time 1\n");
    } else if (!timeVivo(time1) && timeVivo(time2)) {
        printf("Vitória do Time 2\n");
    } else {
        printf("Empate\n");
    }

    return 0;
}

void inicializarTime(Personagem time[], int numeroTime) {
    char classes[5][20] = {"Guerreiro", "Mago", "Caçador", "Paladino", "Bárbaro"};
    int ataques[5] = {20, 30, 18, 15, 25};
    int defesas[5] = {10, 5, 8, 12, 6};

    for (int i = 0; i < NUM_JOGADORES; i++) {
        strcpy(time[i].classe, classes[i]);
        time[i].vida = VIDA_INICIAL;
        time[i].ataque = ataques[i];
        time[i].defesa = defesas[i];
        time[i].habilidade_ativa = 0;
    }
}

int escolherAtacante(Personagem time[]) {
    float melhorRazao = -1;
    int indice = -1;

    for (int i = 0; i < NUM_JOGADORES; i++) {
        if (time[i].vida > 0) {
            float razao = (float)time[i].vida / time[i].ataque;
            if (razao > melhorRazao) {
                melhorRazao = razao;
                indice = i;
            }
        }
    }
    return indice;
}

int sortearAlvo(Personagem time[]) {
    int vivos[NUM_JOGADORES];
    int n = 0;

    for (int i = 0; i < NUM_JOGADORES; i++) {
        if (time[i].vida > 0) {
            vivos[n++] = i;
        }
    }

    return vivos[rand() % n];
}

int calcularDano(Personagem *atacante, Personagem *defensor) {
    int chanceErro = rand() % 100;
    if (strcmp(atacante->classe, "Bárbaro") != 0 && chanceErro < 20) {
        return -1;
    }

    int danoBase = atacante->ataque;
    int chanceHabilidade = rand() % 100;

    if (strcmp(atacante->classe, "Guerreiro") == 0 && chanceHabilidade < 20) {
        danoBase *= 2;
        printf("Habilidade do Guerreiro ativada: Golpe Crítico!\n");
    } else if (strcmp(atacante->classe, "Mago") == 0 && chanceHabilidade < 25) {
        defensor->defesa = 0;
        printf("Habilidade do Mago ativada: Bola de Fogo (ignora defesa)!\n");
    } else if (strcmp(atacante->classe, "Caçador") == 0 && chanceHabilidade < 15) {
        printf("Habilidade do Caçador ativada: Ataque Duplo!\n");
        return calcularDano(atacante, defensor) + calcularDano(atacante, defensor);
    }

    if (rand() % 100 < 20) {
        printf("Defesa do defensor falhou! Defesa ignorada.\n");
        defensor->defesa = 0;
    }

    int dano = danoBase - defensor->defesa;
    if (dano < 0) dano = 0;

    if (strcmp(defensor->classe, "Paladino") == 0 && defensor->vida > 0 && rand() % 100 < 30) {
        int vidaPerdida = VIDA_INICIAL - defensor->vida;
        int cura = vidaPerdida * 0.2;
        defensor->vida += cura;
        if (defensor->vida > VIDA_INICIAL) defensor->vida = VIDA_INICIAL;
        printf("Habilidade do Paladino ativada: Regeneração de %d de vida\n", cura);
    }

    return dano;
}

void imprimirEstado(Personagem t1[], Personagem t2[], int rodada) {
    printf("Estado Atual após Rodada %d:\n", rodada);
    printf("Time 1:\n");
    for (int i = 0; i < NUM_JOGADORES; i++) {
        printf(" %s: Vida %d\n", t1[i].classe, t1[i].vida);
    }

    printf("Time 2:\n");
    for (int i = 0; i < NUM_JOGADORES; i++) {
        printf(" %s: Vida %d\n", t2[i].classe, t2[i].vida);
    }
    printf("\n");
}

int timeVivo(Personagem time[]) {
    for (int i = 0; i < NUM_JOGADORES; i++) {
        if (time[i].vida > 0) return 1;
    }
    return 0;
}
