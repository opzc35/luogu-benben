#include <iostream>
#include <string>
#include <curl/curl.h>
using namespace std;
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void focuson(const int& target_uid,const string& client_id, const string& uid) {
    CURL* curl = curl_easy_init();
    
    if (curl) {
        const char* url = "https://www.luogu.com.cn/api/user/updateRelationShip";
        
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "accept: application/json, text/plain, */*");
        headers = curl_slist_append(headers, "accept-language: zh-CN,zh;q=0.9");
        headers = curl_slist_append(headers, "content-type: application/json");
        
        string cookie = "__client_id=" + client_id + "; _uid=" + uid + "; C3VK=357442";
        headers = curl_slist_append(headers, ("cookie: " + cookie).c_str());
        
        headers = curl_slist_append(headers, "dnt: 1");
        headers = curl_slist_append(headers, "origin: https://www.luogu.com.cn");
        headers = curl_slist_append(headers, "priority: u=1, i");
        headers = curl_slist_append(headers, "referer: https://www.luogu.com.cn/user/1");
        headers = curl_slist_append(headers, "sec-ch-ua: \"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");
        headers = curl_slist_append(headers, "sec-ch-ua-mobile: ?0");
        headers = curl_slist_append(headers, "sec-ch-ua-platform: \"Windows\"");
        headers = curl_slist_append(headers, "sec-fetch-dest: empty");
        headers = curl_slist_append(headers, "sec-fetch-mode: cors");
        headers = curl_slist_append(headers, "sec-fetch-site: same-origin");
        headers = curl_slist_append(headers, "user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0");
        
        headers = curl_slist_append(headers, "x-csrf-token: 1735988870:oyGDaZnPgtsvd7lLX0+smHPEfY2lUy+gcLJ4SQN5NKY=");
        headers = curl_slist_append(headers, "x-requested-with: XMLHttpRequest");

        string json_data = "{\"uid\":1,\"relationship\":1}";
        json_data.replace(json_data.find("1"), 1, target_uid);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());

        string response_data;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "Request failed: " << curl_easy_strerror(res) << endl;
        } else {
            cout << "Response data: " << response_data << endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
}
