#ifndef MUSICA_H
#define MUSICA_H
#define BUZZER_PIN 21
#define BOTAO_A 5
#define BOTAO_B 6
#define BOTAO_J 22
#define SENSIBILIDADE_MOVIMENTO 500  // Aumenta a responsividade
#define TEMPO_MOVIMENTO 150  // Reduz delay para melhor resposta
#define DELAY_MOVIMENTO 50
#define TEMPER 150000  // 150ms em microssegundos
#define TEMPO_RETORNO_MENU 5000000 // 5 segundos em microssegundos


#include "bibliotecas/pitches.h"

//Prototipos de Funções
void play_melody_modificado(int *melody, int *durations, int size, int musica_atual);
int selecionar_nota(int nota_correta);  
void verificar_respostas(int *notas_corretas, int *notas_escolhidas);
void proxima_musica();
extern void selecionar_jogo();

int musica_atual =1;

  int pm_melody[] = {
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5,
  NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_C5,
  NOTE_C6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_G6, NOTE_E6,
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_B5,
  NOTE_FS5, NOTE_DS5, NOTE_DS5, NOTE_E5, NOTE_F5,
  NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_B5
      };

 int pm_durations[] = {
  142, 142, 142, 142,
  71, 213, 285, 142,
  142, 142, 142, 71, 213, 285,
  142, 142, 142, 142, 71,
  213, 285, 71, 71, 71,
  71, 71, 71, 71, 71, 71, 142, 285};


  int mario_melody [] = {
     NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
     NOTE_AS3, NOTE_AS4, 0,
     0,
    NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
    NOTE_AS3, NOTE_AS4, 0,
    0,
    NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
    NOTE_DS3, NOTE_DS4, 0,
    0,
    NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
    NOTE_DS3, NOTE_DS4, 0,
    0, NOTE_DS4, NOTE_CS4, NOTE_D4,
    NOTE_CS4, NOTE_DS4,
    NOTE_DS4, NOTE_GS3,
    NOTE_G3, NOTE_CS4,
    NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
    NOTE_GS4, NOTE_DS4, NOTE_B3,
    NOTE_AS3, NOTE_A3, NOTE_GS3,
    0, 0, 0

  };

  int mario_durations [] = {
    120, 120, 120, 120,
    120, 120, 60,
    30,
    120, 120, 120, 120,
    120, 120, 60,
    30,
    120, 120, 120, 120,
    120, 120, 60,
    30,
    120, 120, 120, 120,
    120, 120, 60,
    60, 180, 180, 180,
    60, 60,
    60, 60,
    60, 60,
    180, 180, 180, 180, 180, 180,
    100, 100, 100,
    100, 100, 100,
    30, 30, 30
  };

  
int korobeiniki_melody[] = {
    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,
    NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, REST,
    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,
    NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, REST,
    NOTE_E5, NOTE_C5,
    NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_A4,
    NOTE_GS4, NOTE_B4, REST,
    NOTE_E5, NOTE_C5,
    NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_E5, NOTE_A5,
    NOTE_GS5
};

int korobeiniki_durations[] = {
    500, 250, 250, 500, 250, 250,
    500, 250, 250, 500, 250, 250,
    750, 250, 500, 500,
    500, 500, 250, 500, 250, 250,
    750, 250, 500, 250, 250,
    750, 250, 500, 250, 250,
    500, 250, 250, 500, 500,
    500, 500, 500, 500,
    500, 250, 250, 500, 250, 250,
    500, 250, 250, 500, 250, 250,
    750, 250, 500, 500,
    500, 500, 250, 500, 250, 250,
    750, 250, 500, 250, 250,
    750, 250, 500, 250, 250,
    500, 250, 250, 500, 500,
    500, 500, 500, 500,
    1000, 1000,
    1000, 1000,
    1000, 1000,
    1000, 500, 250,
    1000, 1000,
    1000, 1000,
    500, 500, 1000,
    1000
};


    int imperial_melody[] = {
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, REST,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, REST,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5,
    NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4,
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5,
    NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4,
    NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5,
    NOTE_DS5, NOTE_D5, NOTE_DS5, REST, NOTE_A4, NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_C5, NOTE_B4, NOTE_C5, REST, NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4,
    NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5,
    NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5,
    NOTE_DS5, NOTE_D5, NOTE_DS5, REST, NOTE_A4, NOTE_DS5, NOTE_D5, NOTE_CS5,
    NOTE_C5, NOTE_B4, NOTE_C5, REST, NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4,
    NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4
    };
    
    int imperial_durations[] = {
    750, 750, 125, 125, 125, 125, 250, 250,
    750, 750, 125, 125, 125, 125, 250, 250,
    500, 500, 500, 375, 125,
    500, 375, 125, 1000,
    500, 500, 500, 375, 125,
    500, 375, 125, 1000,
    500, 375, 125, 500, 375, 125,
    125, 125, 250, 250, 250, 500, 375, 125,
    125, 125, 125, 250, 250, 500, 375, 187,
    500, 375, 125, 1000,
    500, 375, 125, 500, 375, 125,
    125, 125, 250, 250, 250, 500, 375, 125,
    125, 125, 125, 250, 250, 500, 375, 187,
    500, 375, 125, 1000
};

typedef struct {
    int freq;
    char *nome;
} NotaMap;

NotaMap notas_mapeadas[] = {
    {NOTE_B0, "B0"}, {NOTE_C1, "C1"}, {NOTE_CS1, "CS1"}, {NOTE_D1, "D1"}, {NOTE_DS1, "DS1"},
    {NOTE_E1, "E1"}, {NOTE_F1, "F1"}, {NOTE_FS1, "FS1"}, {NOTE_G1, "G1"}, {NOTE_GS1, "GS1"},
    {NOTE_A1, "A1"}, {NOTE_AS1, "AS1"}, {NOTE_B1, "B1"}, {NOTE_C2, "C2"}, {NOTE_CS2, "CS2"},
    {NOTE_D2, "D2"}, {NOTE_DS2, "DS2"}, {NOTE_E2, "E2"}, {NOTE_F2, "F2"}, {NOTE_FS2, "FS2"},
    {NOTE_G2, "G2"}, {NOTE_GS2, "GS2"}, {NOTE_A2, "A2"}, {NOTE_AS2, "AS2"}, {NOTE_B2, "B2"},
    {NOTE_C3, "C3"}, {NOTE_CS3, "CS3"}, {NOTE_D3, "D3"}, {NOTE_DS3, "DS3"}, {NOTE_E3, "E3"},
    {NOTE_F3, "F3"}, {NOTE_FS3, "FS3"}, {NOTE_G3, "G3"}, {NOTE_GS3, "GS3"}, {NOTE_A3, "A3"},
    {NOTE_AS3, "AS3"}, {NOTE_B3, "B3"}, {NOTE_C4, "C4"}, {NOTE_CS4, "CS4"}, {NOTE_D4, "D4"},
    {NOTE_DS4, "DS4"}, {NOTE_E4, "E4"}, {NOTE_F4, "F4"}, {NOTE_FS4, "FS4"}, {NOTE_G4, "G4"},
    {NOTE_GS4, "GS4"}, {NOTE_A4, "A4"}, {NOTE_AS4, "AS4"}, {NOTE_B4, "B4"}, {NOTE_C5, "C5"},
    {NOTE_CS5, "CS5"}, {NOTE_D5, "D5"}, {NOTE_DS5, "DS5"}, {NOTE_E5, "E5"}, {NOTE_F5, "F5"},
    {NOTE_FS5, "FS5"}, {NOTE_G5, "G5"}, {NOTE_GS5, "GS5"}, {NOTE_A5, "A5"}, {NOTE_AS5, "AS5"},
    {NOTE_B5, "B5"}, {NOTE_C6, "C6"}, {NOTE_CS6, "CS6"}, {NOTE_D6, "D6"}, {NOTE_DS6, "DS6"},
    {NOTE_E6, "E6"}, {NOTE_F6, "F6"}, {NOTE_FS6, "FS6"}, {NOTE_G6, "G6"}, {NOTE_GS6, "GS6"},
    {NOTE_A6, "A6"}, {NOTE_AS6, "AS6"}, {NOTE_B6, "B6"}, {NOTE_C7, "C7"}, {NOTE_CS7, "CS7"},
    {NOTE_D7, "D7"}, {NOTE_DS7, "DS7"}, {NOTE_E7, "E7"}, {NOTE_F7, "F7"}, {NOTE_FS7, "FS7"},
    {NOTE_G7, "G7"}, {NOTE_GS7, "GS7"}, {NOTE_A7, "A7"}, {NOTE_AS7, "AS7"}, {NOTE_B7, "B7"},
    {NOTE_C8, "C8"}, {NOTE_CS8, "CS8"}, {NOTE_D8, "D8"}, {NOTE_DS8, "DS8"},
    {REST, "REST"}
};

// **Nomes das músicas**
char* nomes_musicas[4] = {
    "Pac-Man",
    "Mario Bros.",
    "Korobeiniki",
    "Imperial March"
};

// **Função para obter o nome da nota**
char* obter_nome_nota(int freq) {
    for (int i = 0; i < sizeof(notas_mapeadas) / sizeof(NotaMap); i++) {
        if (notas_mapeadas[i].freq == freq) {
            return notas_mapeadas[i].nome;
        }
    }
    return "N/A";  // Caso a nota não seja encontrada
}

// **Definição das notas faltantes (fixas para cada música)**
int notas_faltantes_musicas[4][3] = {
    {10, 17, 25},  // Índices das notas faltantes para Pac-Man
    {5, 14, 27},   // Índices das notas faltantes para Mario
    {15, 42, 83},   // Índices das notas faltantes para Tetris
    {7, 19, 28}    // Índices das notas faltantes para Star Wars
};


void play_melody_modificado(int *melody, int *durations, int size, int musica_atual) {
    int respostas_jogador[3];  
    int respostas_corretas[3] = {
        melody[notas_faltantes_musicas[musica_atual - 1][0]],
        melody[notas_faltantes_musicas[musica_atual - 1][1]],
        melody[notas_faltantes_musicas[musica_atual - 1][2]]
    };

    // **Exibe o nome da música no display**
    ssd1306_fill(&ssd, false);
    ssd1306_draw_string(&ssd, "Tocando", 8, 10);
    ssd1306_draw_string(&ssd, nomes_musicas[musica_atual - 1], 8, 25);
    ssd1306_send_data(&ssd);
    sleep_ms(2000);  // Pequena pausa antes de tocar a música


    //  **Toca a música inteira**
    for (int i = 0; i < size; i++) {
        if (melody[i] != 0) {
            play_tone(BUZZER_PIN, melody[i], durations[i]);
        } else {
            sleep_ms(durations[i]);
        }
        sleep_ms(50);
    }

    sleep_ms(1000);  // Pequena pausa antes do desafio

    //  **Toca a música com as notas faltantes**
    int indice_faltante = 0;
    for (int i = 0; i < size; i++) {
        if (indice_faltante < 3 && i == notas_faltantes_musicas[musica_atual - 1][indice_faltante]) {
            // Exibir no display e capturar a escolha do usuário
            respostas_jogador[indice_faltante] = selecionar_nota(respostas_corretas[indice_faltante]);
            indice_faltante++;
        } else {
            if (melody[i] != 0) {
                play_tone(BUZZER_PIN, melody[i], durations[i]);
            } else {
                sleep_ms(durations[i]);
            }
            sleep_ms(50);
        }
    }

    verificar_respostas(respostas_jogador, respostas_corretas);
}
    
// **Selecionar nota no OLED**
int selecionar_nota(int nota_correta) {
    int index_correto = -1;
    for (int i = 0; i < sizeof(notas_mapeadas) / sizeof(NotaMap); i++) {
        if (notas_mapeadas[i].freq == nota_correta) {
            index_correto = i;
            break;
        }
    }

    if (index_correto == -1) {
        return nota_correta;  // Se a nota correta não for encontrada, retorna ela mesma
    }

    // Garante que as opções sejam sempre válidas
    int opcoes[3];
    opcoes[0] = nota_correta;  // Opção correta

    // Escolhe notas vizinhas dentro dos limites do array
    if (index_correto > 0) {
        opcoes[1] = notas_mapeadas[index_correto - 1].freq;
    } else {
        opcoes[1] = notas_mapeadas[index_correto + 1].freq;
    }

    if (index_correto < (sizeof(notas_mapeadas) / sizeof(NotaMap)) - 1) {
        opcoes[2] = notas_mapeadas[index_correto + 1].freq;
    } else {
        opcoes[2] = notas_mapeadas[index_correto - 1].freq;
    }

    int selecao = 0;
    int nota_anterior = -1;
    while (true) {
        ssd1306_fill(&ssd, false);
        ssd1306_draw_string(&ssd, "Escolha a nota", 8, 10);
        
        for (int i = 0; i < 3; i++) {
            char texto[10];
            sprintf(texto, "%s%s", (i == selecao ? "* " : "  "), obter_nome_nota(opcoes[i]));
            ssd1306_draw_string(&ssd, texto, 8, 20 + (i * 10));
        }
        
        ssd1306_send_data(&ssd);

        adc_select_input(0);
        uint16_t y_value = adc_read();

        if (y_value > (2170 + SENSIBILIDADE_MOVIMENTO) && selecao > 0) { 
            selecao--;
            sleep_ms(TEMPO_MOVIMENTO);  // Ajuste no tempo
        }
        if (y_value < (2170 - SENSIBILIDADE_MOVIMENTO) && selecao < 2) {
            selecao++;
            sleep_ms(TEMPO_MOVIMENTO);
        }

        if (nota_anterior != opcoes[selecao]) {
            play_tone(BUZZER_PIN, opcoes[selecao], 150);  // Nota curta para referência
            nota_anterior = opcoes[selecao];
        }

        if (gpio_get(BOTAO_B) == 0 && (time_us_64() - tempo_anterior > TEMPER)) {
            tempo_anterior = time_us_64();
            return opcoes[selecao]; 
        }
    }
}

// **Verifica as respostas**
void verificar_respostas(int *respostas_jogador, int *respostas_corretas) {
    bool acertou = true;

    for (int i = 0; i < 3; i++) {
        if (respostas_jogador[i] != respostas_corretas[i]) {
            acertou = false;
            break;
        }
    }

    ssd1306_fill(&ssd, false);
    if (acertou) {
        ssd1306_draw_string(&ssd, "Parabens!", 8, 10);
        ssd1306_draw_string(&ssd, "Proximo nivel...", 8, 25);
        ssd1306_send_data(&ssd);
        sleep_ms(2000);
        proxima_musica();  // Se acertou, vai para a próxima música

        switch (musica_atual) {
            case 1:
                play_melody_modificado(pm_melody, pm_durations, sizeof(pm_melody) / sizeof(pm_melody[0]), musica_atual);
                break;
            case 2:
                play_melody_modificado(mario_melody, mario_durations, sizeof(mario_melody) / sizeof(mario_melody[0]), musica_atual);
                break;
            case 3:
                play_melody_modificado(korobeiniki_melody, korobeiniki_durations, sizeof(korobeiniki_melody) / sizeof(korobeiniki_melody[0]), musica_atual);
                break;
            case 4:
                play_melody_modificado(imperial_melody, imperial_durations, sizeof(imperial_melody) / sizeof(imperial_melody[0]), musica_atual);
                break;
        }
    } else {
        ssd1306_draw_string(&ssd, "Errou! Reiniciando...", 8, 10);
        ssd1306_send_data(&ssd);
        sleep_ms(2000);
        switch (musica_atual) {
            case 1:
                play_melody_modificado(pm_melody, pm_durations, sizeof(pm_melody) / sizeof(pm_melody[0]), musica_atual);
                break;
            case 2:
                play_melody_modificado(mario_melody, mario_durations, sizeof(mario_melody) / sizeof(mario_melody[0]), musica_atual);
                break;
            case 3:
                play_melody_modificado(korobeiniki_melody, korobeiniki_durations, sizeof(korobeiniki_melody) / sizeof(korobeiniki_melody[0]), musica_atual);
                break;
            case 4:
                play_melody_modificado(imperial_melody, imperial_durations, sizeof(imperial_melody) / sizeof(imperial_melody[0]), musica_atual);
                break;
        }
    }
    ssd1306_send_data(&ssd);
}

// **Avança para a próxima música**
void proxima_musica() {
    musica_atual++;

    if (musica_atual > 4) {
        ssd1306_fill(&ssd, false);
        ssd1306_draw_string(&ssd, "Menu Principal", 8, 20);
        ssd1306_send_data(&ssd);
        sleep_ms(1500);
        musica_atual = 1;  // Reinicia ciclo de músicas
        selecionar_jogo();
    }
    
}
    #endif //MUSICA_H