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

struct date prevDate(struct date d) {
    struct date prev;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((d.yy % 4 == 0 && d.yy % 100 != 0) || (d.yy % 400 == 0)) {
        daysInMonth[2] = 29;
    }

    if (d.dd > 1) {
        prev.dd = d.dd - 1;
        prev.mm = d.mm;
        prev.yy = d.yy;
    } else {
        if (d.mm == 1) {
            prev.dd = 31;
            prev.mm = 12;
            prev.yy = d.yy - 1;
        } else {
            prev.dd = daysInMonth[d.mm - 1];
            prev.mm = d.mm - 1;
            prev.yy = d.yy;
        }
    }

    return prev;
}

int main() {
    struct date current = {8, 7, 2024};
    struct date next = nextDate(current);
    struct date previous = prevDate(current);
    
    printf("Current date: %d-%d-%d\n", current.dd, current.mm, current.yy);
    printf("Next date: %d-%d-%d\n", next.dd, next.mm, next.yy);
    printf("Previous date: %d-%d-%d\n", previous.dd, previous.mm, previous.yy);

    return 0;
}
