/**
 * This header file implements universally computed functions
 * These functions include:
 * 1.   rectangle_coordinates
 * 2.   ;
*/

#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <nlohmann/json.hpp>
#include <curl/curl.h>


/**
 * universally shared resource between classes
*/

// Callback function for cURL to handle response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

namespace univ{

/**
 * Function to extract location coordinates from Google Maps API
*/
std::pair<double, double> rectangle_coordinates(const std::string& address) {
    CURL* curl;
    CURLcode res;

    // Initialize cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    // Check if cURL initialization is successful
    if (curl) {
        // Google Maps Geocoding API endpoint
        std::string apiUrl = "https://maps.googleapis.com/maps/api/geocode/json?address=" + address + "&key=YOUR_API_KEY";

        // Set cURL options
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Response string to store the nlohmann::json response
        std::string responseString;

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Parse nlohmann::json response
            auto jsonResult = nlohmann::json::parse(responseString);

            // Extract latitude and longitude
            double latitude = jsonResult["results"][0]["geometry"]["location"]["lat"];
            double longitude = jsonResult["results"][0]["geometry"]["location"]["lng"];

            // Clean up cURL
            curl_easy_cleanup(curl);
            curl_global_cleanup();

            return std::make_pair(latitude, longitude);
        }
    }

    // Clean up cURL in case of failure
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    // Return an invalid coordinate if the request fails
    return std::make_pair(0.0, 0.0);
}
/**
 * Make sure to replace "YOUR_API_KEY" in the apiUrl variable with 
 * your actual Google Maps API key. Note that you should keep your 
 * API key confidential and consider restricting its usage to 
 * prevent unauthorized access.
*/

}    // namespace univ


// int main() {
//     // Provide the address for which you want to get coordinates
//     std::string address = "1600 Amphitheatre Parkway, Mountain View, CA";

//     // Call the function to get coordinates
//     auto coordinates = getCoordinates(address);

//     // Display the result
//     std::cout << "Latitude: " << coordinates.first << std::endl;
//     std::cout << "Longitude: " << coordinates.second << std::endl;

//     return 0;
// }

