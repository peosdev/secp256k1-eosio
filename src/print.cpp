
#include <eosio/eosio.hpp>
extern "C"
{
void print_i(unsigned int i) {
    eosio::print("Print_i:", i, "\n");
}
}