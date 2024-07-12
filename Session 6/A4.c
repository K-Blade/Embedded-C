#include <stdio.h>

struct date {
    int dd;
    int mm;
    int yy;
};

struct date nextDate(struct date d) {
    struct date next;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((d.yy % 4 == 0 && d.yy % 100 != 0) || (d.yy % 400 == 0)) {
        daysInMonth[2] = 29;
    }

    if (d.dd < daysInMonth[d.mm]) {
        next.dd = d.dd + 1;
        next.mm = d.mm;
        next.yy = d.yy;
    } else {
        if (d.mm == 12) {
            next.dd = 1;
            next.mm = 1;
            next.yy = d.yy + 1;
        } else {
            next.dd = 1;
            next.mm = d.mm + 1;
            next.yy = d.yy;
        }
    }

    return next;
}

int main() {
    struct date current = {8, 7, 2024};
    struct date result = nextDate(current);
    
    printf("Current date: %d-%d-%d\n", current.dd, current.mm, current.yy);
    printf("Next date: %d-%d-%d\n", result.dd, result.mm, result.yy);

    return 0;
}

