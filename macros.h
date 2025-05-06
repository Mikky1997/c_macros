#ifndef MACROS
#define MACROS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define STRINGIFY(x) #x

#define CONCAT(a, b) a##b

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define FOR_EACH(i, array) for (size_t i = 0; i < ARRAY_SIZE(array); i++)

#define IN_RANGE(x, min, max) ((x) >= (min) && (x) <= (max))

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define POW2(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define swap(x, y)          \
    do                      \
    {                       \
        typeof(x) temp = x; \
        x = y;              \
        y = temp;           \
    } while (0)

#define SAFE_MALLOC(ptr, size)                                                          \
    do                                                                                  \
    {                                                                                   \
        ptr = malloc(size);                                                             \
        if (!ptr)                                                                       \
        {                                                                               \
            fprintf(stderr, "Memory allocation failed at %s:%d\n", __FILE__, __LINE__); \
            exit(EXIT_FAILURE);                                                         \
        }                                                                               \
    } while (0)

#define SAFE_FREE(p) \
    do               \
    {                \
        free(p);     \
        (p) = NULL;  \
    } while (0)

#define TIME_IT(block)                                                                  \
    do                                                                                  \
    {                                                                                   \
        printf("TIME_IT STARTED...\n");                                                 \
        clock_t start = clock();                                                        \
        {block} clock_t end = clock();                                                  \
        printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC); \
    } while (0)

#endif