# TestingProPublicaAndCurl

This is a simple C++ program to pull data from the ProPublica API. Mostly used as an example for future use cases and testing.

You'll need to get your own API Key to use the API, which can be done at the ProPublica website (https://www.propublica.org/datastore/api/propublica-congress-api). There is plenty of API documentation on their website with all of the URIs needed to pull information there.

Example code used to create this program was found at https://curl.haxx.se/libcurl/c/https.html

<b>On Ubuntu to install cURL:</b>

<i>Step 1:</i>

    sudo apt-get install libcurl4-gnutls-dev
    
    or
    
    sudo apt-get install libcurl4-openssl-dev

<i>Step 2:</i>  Follow the steps in this tutorial to link the library to your compiler:

https://curl.haxx.se/libcurl/c/libcurl-tutorial.html

After this you will need to include -lcurl in your compiles to link the cURL library to your project.
