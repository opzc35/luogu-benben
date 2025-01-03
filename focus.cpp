#include "LuoguAPI.h"
int main() {
    const char *secret_key = getenv("luogu_cookie");
    const char *secret_uid = getenv("luogu_uid");
    const char *secret_official_mail_password = getenv("official_mail_password");
    cout<<secret_key<<endl;
    cout<<secret_uid<<endl;
    cout<<secret_official_mail_password<<endl;
    return 0;
}
