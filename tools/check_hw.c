#include <stdio.h>
#include <stddef.h>
#include "amiga_hardware.h"
#define CHECK(f, exp) do { size_t o = offsetof(struct Custom, f); printf("%-12s %#x (atteso %#x) %s\n", #f, (unsigned)o, (unsigned)(exp), o==(exp)?"OK":"ERRORE"); if (o!=(exp)) rc=1; } while(0)
int main(void) {
    int rc = 0;
    CHECK(bltddat, 0x000); CHECK(dmaconr, 0x002); CHECK(vposr, 0x004);
    CHECK(vhposr, 0x006); CHECK(serdatr, 0x018); CHECK(dskbytr, 0x01A);
    CHECK(intenar, 0x01C); CHECK(intreqr, 0x01E);
    CHECK(diwstrt, 0x08E); CHECK(diwstop, 0x090); CHECK(ddfstrt, 0x092);
    CHECK(ddfstop, 0x094); CHECK(dmacon, 0x096); CHECK(clxcon, 0x098);
    CHECK(intena, 0x09A); CHECK(intreq, 0x09C); CHECK(adkcon, 0x09E);
    CHECK(color, 0x180);
    printf("sizeof(struct Custom) = %#x\n", (unsigned)sizeof(struct Custom));
    return rc;
}
