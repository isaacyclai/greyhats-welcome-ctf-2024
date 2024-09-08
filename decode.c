#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int main() {
    // Encrypted flag (replace with actual hex string)
    const char *encrypted = "8fb6a90c747d7352ac6ac807df6df26bd52501670a3c8666cb636f7b8087207f";
    // const char *encrypted = "7f208780";

    // Calculate the length of the encrypted flag in bytes
    size_t encrypted_len = strlen(encrypted);

    // Brute-force possible seeds
    time_t start_time = time(NULL) - 86400;  // Adjust the range based on expected time
    time_t end_time = time(NULL);

    // srand(1724576127);
    // char cur_flag[encrypted_len * 2 + 1]; // Each byte in the hex string becomes 2 characters + null terminator
    // cur_flag[0] = '\0';
    

    for (time_t seed = start_time; seed <= end_time; seed++) {
        srand(seed);
        char recovered[(int)encrypted_len / 4+1]; // 16 chars + 1 for the null terminator
        for (int i = 0; i < encrypted_len / 4; i++) {
            long long rand_i = rand();
            char block_hex[10]; // 8 characters + 1 null terminator
            strncpy(block_hex, encrypted + i * 8, 8);
            block_hex[8] = '\0';
            char block_hex_reversed[10];
            for (int j = 4; j >= 1; j--) {
                block_hex_reversed[j*2-1] = block_hex[8-j*2+1];
                block_hex_reversed[j*2-2] = block_hex[8-j*2];
            }
            block_hex_reversed[8] = '\0';
            // printf("%s\n", block_hex_reversed);
            // long long block = hex_to_int(block_hex_reversed);
            long long block = (long long)strtol(block_hex_reversed, NULL, 16); 
            // printf("%lld\n", block);
            long long decrypted_block = block ^ rand_i;
            // printf("decrypted:%lld\n", decrypted_block);
            recovered[i*4] = decrypted_block & 0xFF;
            recovered[i*4+1] = (decrypted_block >> 8) & 0xFF;
            recovered[i*4+2] = (decrypted_block >> 16) & 0xFF;
            recovered[i*4+3] = (decrypted_block >> 24) & 0xFF;
            // append_to_flag(cur_flag, decrypted_block);
        }
        if (recovered[0] == 'g' && recovered[1] == 'r') printf("Possible flag with seed %ld: %s\n", seed, recovered);
        // printf("Possible flag with seed %ld: %s\n", seed, recovered);
        // break;
    }
}
