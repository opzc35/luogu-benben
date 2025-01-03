#include "LuoguAPI.h"
int main() {
    freopen("log.log","w",stdout);
    const char *secret_key = getenv("luogu_cookie");
    const char *secret_uid = getenv("luogu_uid");
    const char *secret_official_mail_password = getenv("official_mail_password");
    cout<<secret_key<<endl;
    cout<<secret_uid<<endl;
    cout<<secret_official_mail_password<<endl;
    cout<<"1145141919810";
    return 0;
}
