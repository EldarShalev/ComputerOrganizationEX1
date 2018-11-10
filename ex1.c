

/**
 * This function checks Little or Big endian.
 * @return 1 if the first char is equivalent to 1, else returns 0.
 */
int is_little_endian() {

    long int number = 1;
    // create pointer to the address of the number
    char *numPtr = (char *) &number;
    // check if the first bit equals to 1 and return 1 if it does
    return (numPtr[0] == 1);
}


/**
 * This function merged the lsb of y with the other bytes of x.
 * @param x a given unsigned long number.
 * @param y a given unsigned long number.
 * @return unsigned long number with the least significant byte of y, and other bytes of x.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y) {

    // pointers to the addresses
    unsigned char *numXPtr = (unsigned char *) &x;
    unsigned char *numYPtr = (unsigned char *) &y;
    if (is_little_endian()) {
        // LSB is in the smallest address therefore it's located first.
        numXPtr[0] = numYPtr[0];
    } else {
        // LSB is in the biggest address - therefore it's located last.
        int size = sizeof(y);
        numXPtr[size - 1] = numYPtr[size - 1];
    }
    return x;


}

/**
 * This function replaces the bytes with given index and bytes to replace.
 * @param x the number we want to change its byte.
 * @param b the byte to change with.
 * @param i the index of the location.
 * @return the number with the replacing of the byte.
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    //create pointers to first address bit of x
    unsigned char *addressX = (unsigned char *) &x;
    if (is_little_endian()) {
        //LSB is in the smallest address(left), therefore we can count from there
        addressX[i] = b;
    } else {
        // LSB is in the biggest address(right), therefore we can count from there
        int size = sizeof(x);
        addressX[size - 1 - i] = b;
    }
    return x;

}


