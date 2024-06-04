#ifndef RAVE_TOY_CONFIG_HPP
#define RAVE_TOY_CONFIG_HPP

namespace rave_toy::config {
    /**
     * The SSID of the exposed wifi network
     */
    const char* WIFI_SSID = "RAVE_TOY";

    /**
     * The password of the exposed wifi network, or nullptr for no password
     */
    const char* WIFI_PASSWORD = nullptr; // string or nullptr
}

#endif //RAVE_TOY_CONFIG_HPP
