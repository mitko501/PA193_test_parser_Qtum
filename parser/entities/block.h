//
// Created by mhajas on 10/13/17.
//

#ifndef PA193_QTUM_PARSER_BLOCK_H
#define PA193_QTUM_PARSER_BLOCK_H


#include <array>
#include <ostream>
#include <vector>

#include "transaction.h"

class block {
    using hash_type = std::array<uint8_t, 32>;
    using vector_type = std::vector<uint8_t>;

    uint32_t _version;
    hash_type _hash_prev_block;
    hash_type _hash_merkle_root;

    uint32_t _n_time;
    uint32_t _n_bits;
    uint32_t _n_nonce;

    hash_type _hash_state_root;
    hash_type _hash_UTXO_root;

    c_out_point _prevout_stake;

    uint8_t _vch_block_sig_size;
    vector_type _vch_block_sig;

    uint8_t _number_of_transactions;
    uint16_t _extended_number_of_transactions;

    std::vector<transaction> _transactions;

public:
    block();
    explicit block(std::istream& stream);

    uint32_t get_version() const;

    const hash_type& get_hash_prev_block() const;

    const hash_type& get_hash_merkle_root() const;

    uint32_t get_n_time() const;

    uint32_t get_n_bits() const;

    uint32_t get_n_nonce() const;

    const hash_type& get_hash_state_root() const;

    const hash_type& get_hash_UTXO_root() const;

    const c_out_point& get_prevout_stake() const;

    uint8_t get_vch_block_sig_size() const;

    const vector_type& get_vch_block_sig() const;

    uint16_t get_number_of_transactions() const;

    uint32_t get_block_height() const;
  
    std::vector<transaction> get_transactions();

    hash_type compute_hash() const;
    hash_type compute_merkle_root() const;


    bool validate() const;
    bool verify_following_transactions(const block& block2) const;


public:
    friend std::ostream& operator<<(std::ostream& os, const block& block1);
    friend std::istream& operator>>(std::istream& is, block& block1);
};


#endif //PA193_QTUM_PARSER_BLOCK_H
