//Vão ser declarados os frames e cores da animação 1
#ifndef MEMORIA_H
#define MEMORIA_H
#define BOTAO_B 6
#define ZONA_MORTA_X 300  // Ajuste fino para a sensibilidade do eixo X
#define ZONA_MORTA_Y 300  // Ajuste fino para a sensibilidade do eixo Y
#define DELAY_MOVIMENTO 50
#define TEMPO_DEBOUNCE 150000  // 150ms em microssegundos

#include "control_leds.h"
#include "bibliotecas/pitches.h"
ssd1306_t ssd;
extern uint nivel;
int pontuacao = 0;
uint64_t tempo_anterior = 0; //Será util na implantação do debounce. 
extern bool verificar_saida();
extern void selecionar_jogo();



//Exemplo de como definir as cores de cada led:
/*(os números indicam a intensidade da cor caso o led epecífico seja ligado, vc pode misturar as 
intensidades de red, green ou blue pra atingir outras cores;
Você pode deixar todas da mesma cor ou alterar a cor de cada led individualmente).*/

double numeros_red[25] =     {0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1, 
                            0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1};

double numeros_green[25] =   {0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 
                            0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0};

double numeros_blue[25] =    {0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1, 
                            0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1};




//exemplo de frame (Aqui vc desenha)
//Numeros de 0 a 9
// Número 0
uint sequencia_1[25] = {
    0, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
    1, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

// Número 1
uint sequencia_2[25] = {
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 0
};

// Número 2
uint sequencia_3[25] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 1, 0, 0, 0,
    0, 0, 0, 0, 1
};

// Número 3
uint sequencia_4[25] = {
    0, 0, 0, 1, 0,
    0, 1, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 1,
    0, 0, 1, 0, 0
};

// Número 4
uint sequencia_5[25] = {
    0, 0, 0, 0, 1,
    0, 1, 0, 0, 0,
    0, 0, 0, 1, 0,
    1, 0, 0, 0, 0,
    0, 0, 1, 0, 0
};

// Número 5
uint sequencia_6[25] = {
    1, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
    1, 1, 0, 0, 0,
    0, 0, 0, 1, 0,
    0, 1, 0, 0, 0
};

// Número 6
uint sequencia_7[25] = {
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 0, 0, 1,
    0, 1, 0, 1, 0
};

// Número 7
uint sequencia_8[25] = {
    1, 0, 1, 0, 0,
    0, 0, 0, 1, 0,
    0, 1, 0, 0, 0,
    0, 1, 0, 0, 1,
    1, 0, 0, 1, 0
};

// Número 8
uint sequencia_9[25] = {
    1, 0, 1, 0, 1,
    0, 1, 0, 1, 0,
    1, 0, 1, 0, 0,
    1, 0, 0, 0, 1,
    1, 1, 1, 0, 0
};

// Número 9
uint sequencia_10[25] = {
    1, 0, 1, 1, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

uint vazio[25] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

                                        
// Rodar animação:
// Função para exibir o número correspondente
void exibir_sequencia(PIO pio, uint sm, uint nivel) {
    if (nivel >10) { //Forma de evitar que nivel ultrapasse a quantidade de animações definidas
        nivel = 1;
    }
    
    // Determina qual sequência será usada (níveis de 1 a 10)
    uint *sequencia_atual;
        switch(nivel) {
        case 1:
            sequencia_atual = sequencia_1;
            break;
        case 2:
            sequencia_atual = sequencia_2;
            break;
        case 3:
            sequencia_atual = sequencia_3;
            break;
        case 4:
            sequencia_atual = sequencia_4;
            break;
        case 5:
            sequencia_atual = sequencia_5;
            break;
        case 6:
            sequencia_atual = sequencia_6;
            break;
        case 7:
            sequencia_atual = sequencia_7;
            break;
        case 8:
            sequencia_atual = sequencia_8;
            break;
        case 9:
            sequencia_atual = sequencia_9;
            break;
        case 10:
            sequencia_atual = sequencia_10;
            break;
        default:
            return;
    }
        if (sequencia_atual == NULL) {
            return;
        }
        
        // Limpa a matriz antes de começar
        put_leds(vazio, numeros_red, numeros_green, numeros_blue, 0, pio, sm);
        sleep_ms(200);

        // Exibe mensagem inicial no display OLED
        ssd1306_fill(&ssd, false); // Limpa o display
        ssd1306_draw_string(&ssd, "PEGUE A VISAO", 8, 10);
        ssd1306_send_data(&ssd);
        sleep_ms(1000); // Pequena pausa antes de iniciar

         // Percorre a sequência do nível atual
        for (int i = 0; i < 25; i++) {
            if (sequencia_atual[i] == 1) {

                uint temp_leds[25] = {0}; 
                temp_leds[i] = 1; // Ativa somente o LED atual

            // Acende o LED correspondente
            put_leds(temp_leds, numeros_red, numeros_green, numeros_blue, i, pio, sm);
            
            // Determina a frequência do buzzer com base na linha do LED
            int linha = i / 5;
            int freq;
            switch(linha) {
                case 0: freq = NOTE_C4; break;
                case 1: freq = NOTE_D4; break;
                case 2: freq = NOTE_E4; break;
                case 3: freq = NOTE_F4; break;
                case 4: freq = NOTE_G4; break;
                default: freq = NOTE_C4; break;
            }

            // Toca o som do LED correspondente
            play_tone(BUZZER, freq, 300);

            // Mantém o LED aceso por um tempo antes de apagar
            sleep_ms(500);
            put_leds(vazio, numeros_red, numeros_green, numeros_blue, 0, pio, sm);
            sleep_ms(300); // Pequeno intervalo entre os LEDs
        }
            
    }
            // Após exibir a sequência, muda a mensagem do display OLED
            ssd1306_fill(&ssd, false);
            ssd1306_draw_string(&ssd, "REPITA", 8, 10);
            ssd1306_send_data(&ssd);
    }

    int contar_leds_acesos(uint *sequencia) {
        int contador = 0;
        for (int i = 0; i < 25; i++) {
            if (sequencia[i] == 1) {
                contador++;
            }
        }
        return contador;
    }
   

    void verificar_entrada(PIO pio, uint sm) {
        uint *sequencia_atual = NULL;

    switch(nivel) {
        case 1: sequencia_atual = sequencia_1; break;
        case 2: sequencia_atual = sequencia_2; break;
        case 3: sequencia_atual = sequencia_3; break;
        case 4: sequencia_atual = sequencia_4; break;
        case 5: sequencia_atual = sequencia_5; break;
        case 6: sequencia_atual = sequencia_6; break;
        case 7: sequencia_atual = sequencia_7; break;
        case 8: sequencia_atual = sequencia_8; break;
        case 9: sequencia_atual = sequencia_9; break;
        case 10: sequencia_atual = sequencia_10; break;
        default: return;
    }

    if (sequencia_atual == NULL) {
        return;
    } 

        int tamanho_sequencia = contar_leds_acesos(sequencia_atual);

        // Vetor para armazenar a ordem correta da sequência exibida
        uint sequencia_exibida[10];  // No máximo 10 LEDs por sequência
         int indice_sequencia = 0;

         //Preenche sequencia_exibida na ordem correta
    for (int i = 0; i < 25; i++) {
        if (sequencia_atual[i] == 1) {
            sequencia_exibida[indice_sequencia++] = i;
        }
    }

    put_leds(vazio, numeros_red, numeros_green, numeros_blue, 0, pio, sm);
    sleep_ms(500);

        // Define a posição do cursos
        int cursor_x = 2;  // Posição inicial do cursor (coluna)
        int cursor_y = 2;  // Posição inicial do cursor (linha)
        int indice_cursor = cursor_y * 5 + cursor_x;
       
        //Define a posição inicial do cursor 
        uint temp_cursor[25] = {0};
        temp_cursor[indice_cursor] = 1;
        put_leds(temp_cursor, numeros_red, numeros_green, numeros_blue, indice_cursor, pio, sm);
        sleep_ms(50); // Delay para evitar movimentação muito rápida

        int pressionamentos = 0;  // Contador de pressionamentos do botão B
        //uint tentativa[25] = {0}; // Vetor para armazenar os LEDs escolhidos pelo jogador
        uint entrada_jogador[10];  // Vetor para armazenar a ordem de entrada do jogador
        int indice_entrada = 0;

    while (pressionamentos < tamanho_sequencia) {  

        // Atualiza a posição do cursor conforme o joystick
        adc_select_input(1); 
        uint16_t x_value = adc_read();
        adc_select_input(0);
        uint16_t y_value = adc_read();

        // Mostra os valores do joystick no display OLED para depuração
        if (x_value < (2170 - ZONA_MORTA_X) && cursor_x > 0) { 
            cursor_x--;  
            sleep_ms(DELAY_MOVIMENTO);
        }
        if (x_value > (2170 + ZONA_MORTA_X) && cursor_x < 4) { 
            cursor_x++;  
            sleep_ms(DELAY_MOVIMENTO);
        }
        if (y_value > (1950 + ZONA_MORTA_Y) && cursor_y > 0) {  //  Eixo Y invertido aqui!
            cursor_y--;  
            sleep_ms(DELAY_MOVIMENTO);
        }
        if (y_value < (1950 - ZONA_MORTA_Y) && cursor_y < 4) {  //  Eixo Y invertido aqui!
            cursor_y++;  
            sleep_ms(DELAY_MOVIMENTO);
        }

        //Atualiza a posição do cursor sem esperar o botao ser pressionado
        indice_cursor = cursor_y * 5 + cursor_x;
        uint temp_cursor[25] = {0};
        temp_cursor[indice_cursor] = 1;
        put_leds(temp_cursor, numeros_red, numeros_green, numeros_blue, indice_cursor, pio, sm);
        sleep_ms(50);
        

    if (gpio_get(BOTAO_B) == 0 && (time_us_64() - tempo_anterior > TEMPO_DEBOUNCE)) {
            tempo_anterior = time_us_64();  // Atualiza o tempo do último clique
            entrada_jogador[indice_entrada++] = indice_cursor; // Salva a posição pressionada na ordem
            pressionamentos++;

            play_tone(BUZZER, NOTE_A4, 200);

        }
    }


    bool correto = true;
    for (int i = 0; i < tamanho_sequencia; i++) {
        if (entrada_jogador[i] != sequencia_exibida[i]) {
            correto = false;
            break;
        }
    }

    if (correto) { 
        // Jogador acertou!
        pontuacao++;
        ssd1306_fill(&ssd, false);
        char msg_pontuacao[20];
        sprintf(msg_pontuacao, "Parabens! +%d Pt", pontuacao);
        ssd1306_draw_string(&ssd, msg_pontuacao, 8, 10);
        ssd1306_send_data(&ssd);
        sleep_ms(2000);

        if (pontuacao == 10) {  // 🏆 Se o jogador completou 10 níveis, reiniciar jogo
            ssd1306_fill(&ssd, false);
            ssd1306_draw_string(&ssd, "Jogo completo!", 8, 10);
            ssd1306_send_data(&ssd);
            play_tone(BUZZER, NOTE_C6, 1500);
            sleep_ms(3000);
            pontuacao = 0;  // Zerar pontuação para novo jogo
            nivel = 1;  // Reiniciar no nível 1
            ssd1306_fill(&ssd, false);
            ssd1306_draw_string(&ssd, "Menu Principal", 8, 20);
            ssd1306_send_data(&ssd);
            sleep_ms(1500);
            put_leds(vazio, numeros_red, numeros_green, numeros_blue, 0, pio, sm);
            selecionar_jogo();

        } else {
            nivel++;  // Avança para o próximo nível
        }
    } else {
        //  Jogador errou!
        ssd1306_fill(&ssd, false);
        ssd1306_draw_string(&ssd, "ERRO! Reiniciando...", 8, 10);
        ssd1306_send_data(&ssd);
        play_tone(BUZZER, NOTE_B2, 1000);
        sleep_ms(2000);
        nivel = 1;
        pontuacao =0;
    }
    }

#endif //MEMORIA_H