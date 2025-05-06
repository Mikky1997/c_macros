#include "macros.h"

uint32_t main()
{
    // Test STRINGIFY
    printf("STRINGIFY(123): %s\n", STRINGIFY(123));     // Expected: "123"
    printf("STRINGIFY(hello): %s\n", STRINGIFY(hello)); // Expected: "hello"
    printf("\n");

    // Test CONCAT
    uint32_t CONCAT(test, Var) = 42;
    printf("CONCAT(test, Var): %d\n", testVar); // Expected: 42
    printf("\n");

    // Test ARRAY_SIZE
    uint32_t arr[3] = {1, 2, 3};
    printf("ARRAY_SIZE(arr): %zu\n", ARRAY_SIZE(arr)); // Expected: 3
    printf("\n");

    // Test FOR_EACH
    printf("FOR_EACH: ");
    FOR_EACH(i, arr)
    {
        printf("%d ", arr[i]); // Expected: 1 2 3
    }
    printf("\n");

    // Test IN_RANGE
    printf("IN_RANGE(5, 1, 10): %s\n", IN_RANGE(5, 1, 10) ? "true" : "false"); // Expected: true
    printf("IN_RANGE(0, 1, 10): %s\n", IN_RANGE(0, 1, 10) ? "true" : "false"); // Expected: false
    printf("\n");

    // Test MIN and MAX
    printf("MIN(3, 5): %d\n", MIN(3, 5)); // Expected: 3
    printf("MAX(3, 5): %d\n", MAX(3, 5)); // Expected: 5
    printf("\n");

    // Test POW2
    printf("POW2(4): %d\n", POW2(4));   // Expected: 16
    printf("POW2(-3): %d\n", POW2(-3)); // Expected: 9
    printf("\n");

    // Test ABS
    printf("ABS(-7): %d\n", ABS(-7)); // Expected: 7
    printf("ABS(7): %f\n", ABS(7.6)); // Expected: 7.6
    printf("\n");

    // Test swap
    uint32_t x = 10, y = 20;
    swap(x, y);
    printf("swap(10, 20): %d %d\n", x, y); // Expected: 20 10
    printf("\n");

    // Test TIME_IT
    TIME_IT({
        // time anything here
        uint64_t sum = 0;
        for (size_t i = 0; i < 999999; i++)
        {
            sum += i;
        }
        printf("sum is : %llu\n", sum);
    });
    printf("\n");

    // Test SAFE_MALLOC
    uint32_t *array;
    SAFE_MALLOC(array, 99 * sizeof(uint32_t));
    printf("SAFE_MALLOC: %s\n", array ? "Success" : "Failed"); // Expected: Success
    printf("\n");

    // Test SAFE_FREE
    SAFE_FREE(array);
    printf("SAFE_FREE: %s\n", array == NULL ? "NULL" : "Not NULL"); // Expected: NULL
    printf("\n");

    // Test SAFE_MALLOC
    uint32_t *very_big_array;
    SAFE_MALLOC(very_big_array, 9999999999999999 * sizeof(uint32_t));
    printf("SAFE_MALLOC: %s\n", very_big_array ? "Success" : "Failed"); // Memory allocation failed at test.c:79
    printf("\n");

    // Test SAFE_FREE
    SAFE_FREE(very_big_array);
    printf("SAFE_FREE: %s\n", very_big_array == NULL ? "NULL" : "Not NULL"); // Expected: NULL
    printf("\n");

    return 0;
}