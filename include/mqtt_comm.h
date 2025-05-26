#ifndef MQTT_COMM_H
#define MQTT_COMM_H

// connect function 
void mqtt_setup_publish(const char *client_id, const char *broker_ip, const char *user, const char *pass);

// publish function
void mqtt_comm_publish(const char *topic, const uint8_t *data, size_t len);

// subscribe functions
void mqtt_setup_and_subscribe(const char *client_id, const char *broker_ip, const char *user, const char *pass);


#endif