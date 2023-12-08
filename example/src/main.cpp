#include "main.hpp"

#include <libmem/libmem.h>

LIBMEM_DEMO_NOINLINE void a() {
    printf("it's a!\n");
}

LIBMEM_DEMO_NOINLINE void b() {
    printf("it's b!\n");
}

int main(int argc, char **argv) {
    lm_size_t hook_res = LM_HookCode(reinterpret_cast<lm_address_t>(&a), reinterpret_cast<lm_address_t>(&b), nullptr);
    if (hook_res == 0) {
        printf("Failed to hook a()!\n");
        return 1;
    }

    a();
    return 0;
}
