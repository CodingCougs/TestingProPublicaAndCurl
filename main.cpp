/*
 * @author: Bobby Thompson (robert.h.thompson@wsu.edu)
 * @description: Example program to pull data from an API and output it to stdout
 *
 * compiling instructions: make
**/
#include <iostream>
#include <stdio.h>
#include <curl/curl.h>

#define PROPUBLICA_API_Key XXXXXXXXXXXXX        // Enter your own API Key

using namespace std;

// size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);

int main(int argc, char* argv[])
{
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    headers = curl_slist_append(headers, "X-API-Key: XXXXXXXXX");   // API Key goes into the header, to send with the request

    if(curl)
    {                                                               // This is where you set the API URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.propublica.org/congress/v1/members/K000388/votes.json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);        // This is where the API Key you set earlier gets set

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}