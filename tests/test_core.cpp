#include "stratum-codec/work.h"

#include <cstdlib>
#include <iostream>

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "fail: " #cond " (" << __FILE__ << ":" << __LINE__  \
                      << ")\n";                                              \
            return 1;                                                        \
        }                                                                    \
    } while (0)

int main() {
    auto a = stratumcdc::make_job("pool");
    auto b = stratumcdc::make_job("pool");
    CHECK(a.id == b.id);
    CHECK(stratumcdc::hash_nonce(a, 1) != stratumcdc::hash_nonce(a, 2));
    CHECK(stratumcdc::bench(8) == 8);
    CHECK(stratumcdc::algo() != nullptr);
    std::cout << "ok\n";
    return 0;
}
