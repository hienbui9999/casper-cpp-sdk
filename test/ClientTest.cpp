#include "CasperClient.h"
#include "acutest.h"

/**
 * @brief Check the "info_get_peers" rpc function. Size of the resulting array shouldn't be 0.
 *
 */
void get_peers_test (void) {
  Casper::Client client(CASPER_TEST_ADDRESS);
  TEST_ASSERT(client.GetNodePeers().peers.size() != 0);
}

/**
 * @brief Check the "get_state_root_hash" rpc function with a variable. Compare the result with an empty string.
 *
 */
void get_state_root_hash_block_height_test (void) {
  Casper::Client client(CASPER_TEST_ADDRESS);
  uint64_t block_height = 10;
  TEST_ASSERT(client.GetStateRootHash(block_height).state_root_hash != "");
}

/**
 * @brief Check the "get_state_root_hash" rpc function without a variable. Compare the result with an empty string.
 *
 */
void get_state_root_hash_test () {
  Casper::Client client(CASPER_TEST_ADDRESS);
  TEST_ASSERT(client.GetStateRootHash().state_root_hash != "");
}

TEST_LIST = {
    { "peers", get_peers_test },
    { "root hash 1", get_state_root_hash_block_height_test },
    { "root hash 2", get_state_root_hash_test },
    { NULL, NULL }
};
