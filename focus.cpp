#include "LuoguAPI.h"

int main() {
    const char *secret_key = getenv("luogu-cookie");
    const char *secret_uid = getenv("luogu-uid");
    cout<<secret_key<<" "<<secret_uid;
    return 0;
}