#include <stdio.h>
#include <stdlib.h>

typedef short Date;
typedef Date* Week;
typedef Week* Month;

typedef enum {SUN=0, MON, TUE, WED, THU, FRI, SAT} Day;

Month mk_month(short ndays, Day firstday) {
    // temporary holder for weeks
    Week wk[7];
    int wkn = 0;

    // first week
    Week w = (Week) calloc(7, sizeof(Date));
    // find first day
    int i = SUN;
    while ( i < firstday){
        i++;
    }
    Date d = 1;
    while (i <= SAT) {
        w[i] = d;
        d++;
        i++;
    }
    wk[wkn] = w;
    wkn++;

    // weeks after first
    do {
        w = (Week) calloc(7, sizeof(Date));
        for (i = SUN; i <= SAT && d <= ndays; i++) {
            w[i] = d;
            d++;
        }
        wk[wkn] = w;
        wkn++;
    } while (d <= ndays);
    
    // make an extra space to have a zero terminator
    Month m = calloc(wkn + 1, sizeof(Week));
    for (i = 0; i < wkn; i++) {
        m[i] = wk[i];
    }
    return m;
}

int main() {
    Month mar = mk_month(30, FRI);
    printf("SUN MON TUE WED THU FRI SAT\n");
    for (int w = 0; mar[w] != '\0'; w++) {
        Week wk = mar[w];
        for (int d = SUN; d <= SAT; d++) {
            if (wk[d] != '\0') {
                printf("%3d ", wk[d]);
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
}
