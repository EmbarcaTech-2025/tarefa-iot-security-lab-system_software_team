
# Tarefa: IoT Security Lab - EmbarcaTech 2025

Autores: **Daltro Oliveira Vinuto e Kyara Esteves de Sousa**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, Maio de 2025

---

<!-- INSIRA O CONTEÚDO DO SEU README AQUI! -->

---

## 📜 Licença
GNU GPL-3.0.  


Foi criada uma pasta chamada assets/ que contem os printscreens relacionados ao checklist das tarefa Segurança em IoT com a BitDogLab.

A **Etapa 1**(Inicializar a conexão de rede via Wi-Fi usando o SDK Pico W + lwIP
) do roteiro foi atendida com sucesso conforme podemos ver pelos printscreens abaixo: 
- Compilou sem erros:
![compilou sem erros](assets/1_daltro_compilação_sem_erros.png)  
![compilou sem erros](assets/1_kyara_compilacao_sem_erros.png)  
- O teste de conexão com o wifi foi bem sucedido:   
![teste de conexacao com wifi](assets/1_daltro_teste_conexao_em_uma_rede_wifi.png)
![teste de conexacao com wifi](assets/1_kyara_teste_de_conexao_com_wifi.png))

A **Etapa 2**(Conectar um dispositivo embarcado a um broker MQTT e publicar dados em tópicos específicos, com tratamento básico de erros) do roteiro foi atendida com sucesso conforme podemos ver pelos printscreens abaixo: 
- Teste de conexão mqtt:  
![teste de conexão mqtt](assets/2_e_3_daltro_publicacao_mqtt_sem_segurança.png)
![teste de conexão mqtt](assets/2_e_3_kyara_publicacao_mqtt_sem_seguranca_sub_e_pub_mosquitto.png)

A **Etapa 3**(Enviar mensagem em texto claro via MQTT (pico-mqtt-c ou lwIP)) do roteiro foi atendida com sucesso conforme podemos ver pelos printscreens abaixo: 
 - Broker local recebe a mensagem, antes do envio (publish):   
![teste de conexão mqtt](assets/2_e_3_daltro_publicacao_mqtt_sem_segurança.png)
![teste de conexão mqtt](assets/2_e_3_kyara_publicacao_mqtt_sem_seguranca_sub_e_pub_mosquitto.png)

A **Etapa 4**(Adicionar autenticação simples no broker e configurar no cliente
) do roteiro foi atendida com sucesso conforme podemos ver pelos printscreens abaixo: 
- Somente dispositivos autenticados conseguem publicar:  
![autenticacao com senha no mosquitto](assets/4_daltro_autenticacao_com_senha_mosquito.png)
![autenticacao com senha no mosquitto](assets/4_kyara_autenticacao_basica_mosquito_com_senha_remota.png)

A **Etapa 5**(Ofuscar o conteúdo para evitar sniffing básico
) do roteiro foi atendida com sucesso conforme podemos ver pelos printscreens abaixo: 
- Wireshark mostra conteúdo ofuscado:
![mqtt wireshark](assets/5_daltro_publisher_wireshark.png)  
![mqtt publisher](assets/5_daltro_publisher_criptografado_com_xor.png)

- Subscriber consegue decifrar aplicando a mesma função XOR  
![mqtt subscriber](assets/5_kyara_subscriber_wireshark_ofuscado_mensagem_decifrada_com_sucesso.png)


A **Etapa 6**(Adicionar timestamp e validar mensagens no subscriber) do roteiro foi atendida com sucesso conforme podemos ver pelos printscreens abaixo: 
* Mensagens antigas são descartadas e
Apenas novos timestamps são aceitos:  
  * Publisher: ![publisher](assets/6_kyara_publisher_com_timestamp.png)
  * Subscriber: ![subscriber](assets/6_daltro_subscriber_com_timestamp_e_dados_criptografados.png)
