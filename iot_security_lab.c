// Bibliotecas necessárias#
#include <string.h>                 // Para funções de string como strlen()
#include <time.h>
#include <string.h>
#include "pico/stdlib.h"            // Biblioteca padrão do Pico (GPIO, tempo, etc.)
#include "pico/cyw43_arch.h"        // Driver WiFi para Pico W
#include "include/wifi_conn.h"      // Funções personalizadas de conexão WiFi
#include "include/mqtt_comm.h"      // Funções personalizadas para MQTT
#include "include/xor_cipher.h"     // Funções de cifra XOR

uint is_subscriber = 1;
uint is_publisher = 0;
const char* topic = "escola/sala1/temperatura";


int main() {
    // Inicializa todas as interfaces de I/O padrão (USB serial, etc.)
    stdio_init_all();
    
    // Conecta à rede WiFi
    // Parâmetros: Nome da rede (SSID) e senha
    connect_to_wifi("Kyara", "kyara123");

    // Configura o cliente MQTT
    // Parâmetros: ID do cliente, IP do broker, usuário, senha
    if (is_subscriber) {
        mqtt_setup_and_subscribe("bitdog_subscriber", "192.168.151.142", "aluno", "senha123");
        
    } 
    if (is_publisher) {
        mqtt_setup_publish("bitdog_publisher", "192.168.151.142", "aluno", "senha123");
    }
    

    // Mensagem original a ser enviada
    //const char *mensagem = "25";

    uint8_t mensagem[51];
    
   
    // Loop principal do programa
    while (true) {
        if (is_publisher) {
            time_t seconds = time(NULL);
            sprintf(mensagem, "{\"valor\":26.5,\"ts\":%lu}", seconds);

            // Publica a mensagem original (não criptografada)
            //mqtt_comm_publish("escola/sala1/temperatura", mensagem, strlen(mensagem));
            //printf("A mensagem %s foi enviada !!!\n", mensagem);
             // Buffer para mensagem criptografada (16 bytes)
            uint8_t criptografada[16];
            // Criptografa a mensagem usando XOR com chave 42
            xor_encrypt((uint8_t *)mensagem, criptografada, strlen(mensagem), 42);

            
            // Alternativa: Publica a mensagem criptografada (atualmente comentada)
            mqtt_comm_publish("escola/sala1/temperatura", criptografada, strlen(mensagem));
            
            // Aguarda 5 segundos antes da próxima publicação
        }
        sleep_ms(5000);
    }
    return 0;
}

/* 
 * Comandos de terminal para testar o MQTT:
 * 
 * Inicia o broker MQTT com logs detalhados:
 * mosquitto -c mosquitto.conf -v
 * 
 * Assina o tópico de temperatura (recebe mensagens):
 * mosquitto_sub -h localhost -p 1883 -t "escola/sala1/temperatura" -u "aluno" -P "senha123"
 * 
 * Publica mensagem de teste no tópico de temperatura:
 * mosquitto_pub -h localhost -p 1883 -t "escola/sala1/temperatura" -u "aluno" -P "senha123" -m "26.6"
 */