/*
 * @author: Bobby Thompson (robert.h.thompson@wsu.edu)
 * @description: Example program to pull data from an API and output it to stdout
 * Code used as a template for the original program was found at https://curl.haxx.se/libcurl/c/https.html
 *
 * compiling instructions: make
**/

#include <iostream>
#include <stdio.h>
#include <curl/curl.h>

#define PROPUBLICA_API_Key XXXXXXXXXXXXX                            // Enter your own API Key

using namespace std;
                                                                    // Suggested template for a write_data function: Future Case
// size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);

int main(int argc, char* argv[])
{
    CURL *curl;                                                     // cURL Object that will do requests for us
    CURLcode res;
    struct curl_slist *headers = NULL;                              // Headers list object, will be used for API Key

    curl_global_init(CURL_GLOBAL_DEFAULT);                          // Initialize Global defaults required

    curl = curl_easy_init();                                        // Initialize cURL object

    headers = curl_slist_append(headers, "X-API-Key: XXXXXXXXX");   // API Key goes into the header, to send with the request

    if(curl)
    {                                                               // This is where you set the API URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.propublica.org/congress/v1/members/K000388/votes.json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);        // This is where the API Key you set earlier goes to send with request

                                                                    // Perform the request, res will get the return code
        res = curl_easy_perform(curl);
                                                                    // Check for errors
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }


        curl_easy_cleanup(curl);                                    // Always cleanup
    }

    curl_global_cleanup();                                          // Cleaning up global settings

    return 0;
}