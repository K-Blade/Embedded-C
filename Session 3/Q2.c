#include <stdio.h>

#define SET_BIT(val, pos) (val |= (1U << pos))
#define CLEAR_BIT(val, pos) (val &= (~(1U << pos)))
#define TOGGLE_BIT(val, pos) (val ^= (1U << pos))
#define CHECK_BIT(val, pos) ((val & (1U << pos)) ? 1 : 0)
#define SWAP_NIBBLES(x) ((x & 0x0F) << 4 | (x & 0xF0) >> 4)
#define PRINT_BIT(n) do { unsigned int i, temp = 1U << 31; for (i = 0; i < 32; i++, temp >>= 1) ((n & temp) == 0) ? printf("0") : printf("1"); printf("\n"); } while (0)

int main() {
    unsigned int n, ch, pos;
    printf("Enter Number: ");
    scanf("%u", &n);
    PRINT_BIT(n);
    
    while (1) {
        printf("\nChoose an Option:\n1. Set Bit\n2. Reset Bit\n3. Toggle Bit\n4. Read Bit\n5. Exit\n");
        scanf("%u", &ch);
        
        if (ch == 1) {
            printf("Enter Position: ");
            scanf("%u", &pos);
            SET_BIT(n, pos);
            PRINT_BIT(n);
        } else if (ch == 2) {
            printf("Enter Position: ");
            scanf("%u", &pos);
            CLEAR_BIT(n, pos);
            PRINT_BIT(n);
        } else if (ch == 3) {
            printf("Enter Position: ");
            scanf("%u", &pos);
            TOGGLE_BIT(n, pos);
            PRINT_BIT(n);
        } else if (ch == 4) {
            printf("Enter Position: ");
            scanf("%u", &pos);
            printf("%d\n", CHECK_BIT(n, pos));
        } else if (ch == 5) {
            break;
        } else {
            printf("Invalid Option\n");
        }
    }
    
    return 0;
}

