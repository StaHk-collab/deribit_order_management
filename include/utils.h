#pragma once

#include <string>
#include <curl/curl.h>
#include <iostream>

namespace UtilityNamespace {

    // func declarations
    std::string sendPostRequest(const std::string& url, const std::string& postFields);
    std::string sendPostRequestWithAuth(const std::string& url, const std::string& postFields, const std::string& token);
    std::string sendGetRequest(const std::string& url);
    std::string authenticate();
    void logMessage(const std::string& message);

    // callback func to write data received from cURL to a string
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s);
}