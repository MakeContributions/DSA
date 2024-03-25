#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE (sizeof(unsigned int) * 8)


typedef struct {
    unsigned int* array;
    size_t size; 
} BitArray;

typedef BitArray* BitArrayPtr;

BitArrayPtr createBitArray(size_t n) {
    BitArrayPtr bit_array = (BitArrayPtr)calloc(n, sizeof(unsigned int));
    if (!bit_array) return NULL;
    size_t numBytes = (n + BITS_PER_BYTE - 1) / BITS_PER_BYTE; 
    bit_array->array = (unsigned int*)calloc(numBytes, sizeof(unsigned int));
    if (!bit_array->array) {
        free(bit_array);
        return NULL;
    }
    bit_array->size = n;
    return bit_array;
}

void freeBitArray(BitArrayPtr bit_array){
    if(bit_array){
        free(bit_array->array);
        free(bit_array);
        bit_array = NULL;
    }
}

void setBit(BitArray* ba, size_t index) {
    if (index < ba->size) {
        ba->array[index / BITS_PER_BYTE] |= 1 << (index % BITS_PER_BYTE);
    }
}

void clearBit(BitArray* ba, size_t index) {
    if (index < ba->size) {
        ba->array[index / BITS_PER_BYTE] &= ~(1 << (index % BITS_PER_BYTE));
    }
}

int testBit(const BitArray* ba, size_t index) {
    if (index < ba->size) {
        return (ba->array[index / BITS_PER_BYTE] & (1 << (index % BITS_PER_BYTE))) != 0;
    }
    return -1;
}

void toggleBit(BitArray* ba, size_t index) {
    if (index < ba->size) {
        ba->array[index / BITS_PER_BYTE] ^= 1 << (index % BITS_PER_BYTE);
    }
}

unsigned int hammingWeightBitArray(const BitArray* bitArray) {
    unsigned int totalWeight = 0;
    for (size_t i = 0; i < bitArray->size; i++) {
        if (testBit(bitArray, i)) {
            totalWeight++;
        }
    }
    return totalWeight;
}



int findFirstSetBit(const BitArray* ba) {
    for (size_t i = 0; i < ba->size; i++) {
        if (testBit(ba, i)) {
            return i; 
        }
    }
    return -1; 
}


int findFirstUnsetBit(const BitArray* ba) {
    for (size_t i = 0; i < ba->size; i++) {
        if (!testBit(ba, i)) {
            return i; 
        }
    }
    return -1; 
}

BitArrayPtr bitwiseAND(const BitArray* ba1, const BitArray* ba2) {
    BitArrayPtr result = createBitArray(ba1->size);
    if (!result) return NULL;
    size_t numInts = (ba1->size + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    for (size_t i = 0; i < numInts; i++) {
        result->array[i] = ba1->array[i] & ba2->array[i];
    }
    return result;
}

BitArrayPtr bitwiseOR(const BitArray* ba1, const BitArray* ba2) {
    BitArrayPtr result = createBitArray(ba1->size);
    if (!result) return NULL;
    size_t numInts = (ba1->size + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    for (size_t i = 0; i < numInts; i++) {
        result->array[i] = ba1->array[i] | ba2->array[i];
    }
    return result;
}

BitArrayPtr bitwiseNOT(const BitArray* ba) {
    BitArrayPtr result = createBitArray(ba->size);
    if (!result) return NULL;
    size_t numInts = (ba->size + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    for (size_t i = 0; i < numInts; i++) {
        result->array[i] = ~ba->array[i];
    }
    return result;
}

BitArrayPtr bitwiseXOR(const BitArray* ba1, const BitArray* ba2) {
    BitArrayPtr result = createBitArray(ba1->size);
    if (!result) return NULL;
    size_t numInts = (ba1->size + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    for (size_t i = 0; i < numInts; i++) {
        result->array[i] = ba1->array[i] ^ ba2->array[i];
    }
    return result;
}

BitArrayPtr bitwiseShiftLeft(const BitArray* ba, size_t shift) {
    BitArrayPtr result = createBitArray(ba->size);
    if (!result) return NULL;

    size_t numInts = (ba->size + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    size_t shiftInts = shift / BITS_PER_BYTE;
    size_t shiftBits = shift % BITS_PER_BYTE;

    for (size_t i = 0; i < numInts - shiftInts; i++) {
        if (i + shiftInts + 1 < numInts && shiftBits != 0) {
            result->array[i] = (ba->array[i + shiftInts] << shiftBits) |
                               (ba->array[i + shiftInts + 1] >> (BITS_PER_BYTE - shiftBits));
        } else {
            result->array[i] = ba->array[i + shiftInts] << shiftBits;
        }
    }

    return result;
}

BitArrayPtr bitwiseShiftRight(const BitArray* ba, size_t shift) {
    BitArrayPtr result = createBitArray(ba->size);
    if (!result) return NULL;

    size_t numInts = (ba->size + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    size_t shiftInts = shift / BITS_PER_BYTE;
    size_t shiftBits = shift % BITS_PER_BYTE;

    for (size_t i = numInts - 1; i >= shiftInts; i--) {
        if (i >= shiftInts + 1 && shiftBits != 0) {
            result->array[i] = (ba->array[i - shiftInts] >> shiftBits) |
                               (ba->array[i - shiftInts - 1] << (BITS_PER_BYTE - shiftBits));
        } else {
            result->array[i] = ba->array[i - shiftInts] >> shiftBits;
        }
        if (i == 0) break; 
    }

    return result;
}

BitArrayPtr bitwiseRotateLeft(const BitArray* ba, size_t rotate) {
    size_t sizeInBits = ba->size;
    BitArrayPtr result = bitwiseShiftLeft(ba, rotate % sizeInBits);
    BitArrayPtr temp = bitwiseShiftRight(ba, (sizeInBits - rotate) % sizeInBits);

    for (size_t i = 0; i < (sizeInBits / BITS_PER_BYTE); i++) {
        result->array[i] |= temp->array[i];
    }

    freeBitArray(temp);
    return result;
}

BitArrayPtr bitwiseRotateRight(const BitArray* ba, size_t rotate) {
    size_t sizeInBits = ba->size;
    BitArrayPtr result = bitwiseShiftRight(ba, rotate % sizeInBits);
    BitArrayPtr temp = bitwiseShiftLeft(ba, (sizeInBits - rotate) % sizeInBits);

    for (size_t i = 0; i < (sizeInBits / BITS_PER_BYTE); i++) {
        result->array[i] |= temp->array[i];
    }

    freeBitArray(temp);
    return result;
}

BitArrayPtr bitSlice(const BitArray* ba, size_t start, size_t end) {
    if (start > end || end >= ba->size) return NULL; 

    size_t newSize = end - start + 1;
    BitArrayPtr slice = createBitArray(newSize);
    if (!slice) return NULL;

    for (size_t i = start; i <= end; i++) {
        if (testBit(ba, i)) {
            setBit(slice, i - start);
        }
    }
    return slice;
}

BitArrayPtr unionBitArrays(const BitArray* ba1, const BitArray* ba2) {
    size_t maxSize = (ba1->size > ba2->size) ? ba1->size : ba2->size;
    BitArrayPtr result = createBitArray(maxSize);
    if (!result) return NULL;

    
    for (size_t i = 0; i < (maxSize + BITS_PER_BYTE - 1) / BITS_PER_BYTE; i++) {
        result->array[i] = ba1->array[i] | ba2->array[i];
    }
    return result;
}

BitArrayPtr intersectionBitArrays(const BitArray* ba1, const BitArray* ba2) {
    size_t maxSize = (ba1->size > ba2->size) ? ba1->size : ba2->size;
    BitArrayPtr result = createBitArray(maxSize);
    if (!result) return NULL;

    
    for (size_t i = 0; i < (maxSize + BITS_PER_BYTE - 1) / BITS_PER_BYTE; i++) {
        result->array[i] = ba1->array[i] & ba2->array[i];
    }
    return result;
}

BitArrayPtr differenceBitArrays(const BitArray* ba1, const BitArray* ba2) {
    size_t maxSize = (ba1->size > ba2->size) ? ba1->size : ba2->size;
    BitArrayPtr result = createBitArray(maxSize);
    if (!result) return NULL;

    
    for (size_t i = 0; i < (maxSize + BITS_PER_BYTE - 1) / BITS_PER_BYTE; i++) {
        result->array[i] = ba1->array[i] & ~ba2->array[i];
    }
    return result;
}

BitArrayPtr resizeBitArray(const BitArray* ba, size_t newSize) {
    BitArrayPtr resized = createBitArray(newSize);
    if (!resized) return NULL;

    size_t minSize = (newSize < ba->size) ? newSize : ba->size;
    for (size_t i = 0; i < minSize; i++) {
        if (testBit(ba, i)) {
            setBit(resized, i);
        }
    }
    return resized;
}

void printBitArray(const BitArray* ba) {
    for (size_t i = 0; i < ba->size; i++) {
        printf("%d", (ba->array[i / BITS_PER_BYTE] >> (i % BITS_PER_BYTE)) & 1);
        if ((i + 1) % BITS_PER_BYTE == 0) printf(" ");
    }
    printf("\n");
}


int main() {
    
    BitArrayPtr bitArray = createBitArray(32);
    printf("BitArray created. Initial state: ");
    printBitArray(bitArray);

    
    setBit(bitArray, 0);
    setBit(bitArray, 5);
    setBit(bitArray, 31);
    printf("After setting bits at positions 0, 5, and 31: ");
    printBitArray(bitArray);

    
    clearBit(bitArray, 5);
    printf("After clearing bit at position 5: ");
    printBitArray(bitArray);

    
    printf("Test bit at position 0: %d\n", testBit(bitArray, 0));
    printf("Test bit at position 5: %d\n", testBit(bitArray, 5));

    
    toggleBit(bitArray, 0);
    toggleBit(bitArray, 5);
    printf("After toggling bits at positions 0 and 5: ");
    printBitArray(bitArray);

    
    printf("First set bit: %d\n", findFirstSetBit(bitArray));
    printf("First unset bit: %d\n", findFirstUnsetBit(bitArray));

    
    printf("Hamming weight: %u\n", hammingWeightBitArray(bitArray));

    
    BitArrayPtr bitArray2 = createBitArray(32);
    setBit(bitArray2, 31); 
    BitArrayPtr andResult = bitwiseAND(bitArray, bitArray2);
    printf("Bitwise AND: ");
    printBitArray(andResult);

    BitArrayPtr orResult = bitwiseOR(bitArray, bitArray2);
    printf("Bitwise OR: ");
    printBitArray(orResult);

    BitArrayPtr notResult = bitwiseNOT(bitArray);
    printf("Bitwise NOT: ");
    printBitArray(notResult);

    BitArrayPtr xorResult = bitwiseXOR(bitArray, bitArray2);
    printf("Bitwise XOR: ");
    printBitArray(xorResult);

    
    BitArrayPtr shiftLeftResult = bitwiseShiftLeft(bitArray, 2);
    printf("Bitwise shift left by 2: ");
    printBitArray(shiftLeftResult);

    BitArrayPtr shiftRightResult = bitwiseShiftRight(bitArray, 2);
    printf("Bitwise shift right by 2: ");
    printBitArray(shiftRightResult);

    BitArrayPtr rotateLeftResult = bitwiseRotateLeft(bitArray, 2);
    printf("Bitwise rotate left by 2: ");
    printBitArray(rotateLeftResult);

    BitArrayPtr rotateRightResult = bitwiseRotateRight(bitArray, 2);
    printf("Bitwise rotate right by 2: ");
    printBitArray(rotateRightResult);

    
    freeBitArray(bitArray);
    freeBitArray(bitArray2);
    freeBitArray(andResult);
    freeBitArray(orResult);
    freeBitArray(notResult);
    freeBitArray(xorResult);
    freeBitArray(shiftLeftResult);
    freeBitArray(shiftRightResult);
    freeBitArray(rotateLeftResult);
    freeBitArray(rotateRightResult);

    return 0;
}