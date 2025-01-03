#include "LuoguAPI.h"
int main() {
    const char *secret_key = getenv("luogu_cookie");
    const char *secret_uid = getenv("luogu_uid");
    const char *uid = getenv("uid");
    string uid_s(uid);
    string sk(secret_key);
    string su(secret_uid);
    focuson(stoi(uid_s), sk, su);
    return 0;
}
