#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/pwm.h"

// Bibliotecas criadas para o projeto
#include "bibliotecas/control_leds.h"
#include "bibliotecas/memoria.h"
#include "bibliotecas/musica.h"
#include "bibliotecas/pitches.h"
#include "Projeto_Final.pio.h"

// **Prototipos das funções para evitar erro de compilação**
void jogo_musical();
void jogo_memoria();

#define VRX_PIN 26
#define VRY_PIN 27
#define BOTAO_A 5
#define BOTAO_B 6
#define MATRIZ 7
#define BUZZER 10
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C
#define BUZZER_PIN 21


// **Tamanho do quadrado e tela SSD1306**
#define QUAD_SIZE 8  
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Objetos Globais
PIO pio = pio0;  // Escolhemos o PIO0 para a matriz de LEDs
uint sm;         // Máquina de estado (State Machine)
uint offset;     // Offset do programa PIO
uint nivel = 1;  // Nivel começa em 1 pois é o primeiro nivel
ssd1306_t ssd;  // Inicializa a estrutura do display
int opcao = 1;  // Opção inicial do menu


void incializa_perifericos () {
    //UART para depuração
    stdio_init_all();

    // Inicialização do ADC para leitura do Joystick
    adc_init();
    adc_gpio_init(VRX_PIN);   //Configura o pino ADC para o eixo X
    adc_gpio_init(VRY_PIN);  //Configura o pino do ADC para o eixo Y

    //Configuração do Botão B
    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_B); // Habilita pull-up interno

    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);

    //Configura o buzzer
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    //Inicialização do barramento I2C para o display OLED
    i2c_init(I2C_PORT, 400 * 1000); // Velocidade de 400kHz
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    //Inicializa o Buzzer 2
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    //coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
    bool ok = set_sys_clock_khz(128000, false);

    //configurações da PIO
    uint offset = pio_add_program(pio, &Projeto_Final_program);
    uint sm = pio_claim_unused_sm(pio, true);
    Projeto_Final_program_init(pio, sm, offset, MATRIZ);

    // Inicializa o display OLED
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
    ssd1306_config(&ssd); // Configura o display
    ssd1306_send_data(&ssd); // Envia os dados para o display
    ssd1306_fill(&ssd, false); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, true, false); //Cria um retangulo
    ssd1306_draw_string(&ssd, "Vamos brincar", 8, 10);
    ssd1306_send_data(&ssd); // Envia os dados para o display
    sleep_ms(1000);
}

void selecionar_jogo() {
    bool escolha_confirmada = false;

    while (!escolha_confirmada) {
        ssd1306_fill(&ssd, false);

        // Exibe o menu, destacando a opção selecionada
        if (opcao == 1) {
            ssd1306_draw_string(&ssd, "* Ouvido Musical", 5, 10);
            ssd1306_draw_string(&ssd, "  Jogo Memoria", 8, 30);
        } else {
            ssd1306_draw_string(&ssd, "  Ouvido Musical", 5, 10);
            ssd1306_draw_string(&ssd, "* Jogo Memoria", 8, 30);
        }

        ssd1306_send_data(&ssd);
        sleep_ms(100);

        // Leitura do Joystick
        adc_select_input(0);
        uint16_t y_value = adc_read();

        // Move o cursor para cima ou para baixo no menu
        if (y_value > (1950 + 300) && opcao != 1) {  
            opcao = 1;  
            sleep_ms(200);
        }
        if (y_value < (1950 - 300) && opcao != 2) {  
            opcao = 2;  
            sleep_ms(200);
        }

        // Verifica se o Botão C foi pressionado para confirmar a escolha
        if (gpio_get(BOTAO_A) == 0) {
            escolha_confirmada = true;
            sleep_ms(300); // Pequeno debounce
        }
    }

    // Após confirmação, inicia o jogo correspondente
    if (opcao == 1) {
        jogo_musical();
    } else {
        jogo_memoria();
    }
}

// **Função do "Jogo Musical" (será implementado depois)**
void jogo_musical() {
    ssd1306_fill(&ssd, false);
    ssd1306_draw_string(&ssd, "Iniciando Jogo Musical", 8, 20);
    ssd1306_send_data(&ssd);
    sleep_ms(2000);
    
    while (true) {

        if (musica_atual == 1) {
            play_melody_modificado(pm_melody, pm_durations, sizeof(pm_melody) / sizeof(pm_melody[0]),musica_atual);
        } else if (musica_atual == 2) {
            play_melody_modificado(mario_melody, mario_durations, sizeof(mario_melody) / sizeof(mario_melody[0]),musica_atual);
        } else if (musica_atual == 3) {
            play_melody_modificado(korobeiniki_melody, korobeiniki_durations, sizeof(korobeiniki_melody) / sizeof(korobeiniki_melody[0]),musica_atual);
        } else if (musica_atual == 4) {
            play_melody_modificado(imperial_melody, imperial_durations, sizeof(imperial_melody) / sizeof(imperial_melody[0]),musica_atual);
        }
        sleep_ms(1000);  // Pequena pausa antes de repetir o loop
        proxima_musica();

        if (musica_atual > 4) {
            return; // Sai do loop e retorna ao menu principal
        }
    }
    }


// **Função do "Jogo da Memória"**
void jogo_memoria() {
    ssd1306_fill(&ssd, false);
    ssd1306_draw_string(&ssd, "Iniciando Jogo da Memoria", 8, 20);
    ssd1306_send_data(&ssd);
    sleep_ms(2000);
    while (true) {  

        exibir_sequencia(pio, sm, nivel);
        sleep_ms(1500);
        verificar_entrada(pio, sm);
        sleep_ms(500);
    }
}

int main()
{
    incializa_perifericos();
    selecionar_jogo();
    sleep_ms(1000);
    return 0;
}