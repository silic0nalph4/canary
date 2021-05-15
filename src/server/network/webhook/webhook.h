#ifndef SRC_SERVER_NETWORK_WEBHOOK_WEBHOOK_H_
#define SRC_SERVER_NETWORK_WEBHOOK_WEBHOOK_H_

#include <string>

void webhook_init();

void webhook_send_message(const std::string& title, const std::string& message, int color);

#endif  // SRC_SERVER_NETWORK_WEBHOOK_WEBHOOK_H_
