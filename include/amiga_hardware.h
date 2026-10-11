#ifndef AMIGA_HARDWARE_H
#define AMIGA_HARDWARE_H

#include <stdint.h>

/*
 * Registri dei Custom Chip Amiga (Agnus/Denise/Paula) a 0xDFF000.
 *
 * Ogni registro e' al suo offset reale (Amiga Hardware Reference Manual).
 * Solo i registri usati dal progetto sono nominati; il resto e' padding.
 */

typedef volatile uint16_t vuint16;

struct Custom {
    vuint16 bltddat;      /* $000 */
    vuint16 dmaconr;      /* $002 */
    vuint16 vposr;        /* $004 */
    vuint16 vhposr;       /* $006 */
    vuint16 dskdatr;      /* $008 */
    vuint16 joy0dat;      /* $00A */
    vuint16 joy1dat;      /* $00C */
    vuint16 clxdat;       /* $00E */
    vuint16 adkconr;      /* $010 */
    vuint16 pot0dat;      /* $012 */
    vuint16 pot1dat;      /* $014 */
    vuint16 potinp;       /* $016 */
    vuint16 serdatr;      /* $018 */
    vuint16 dskbytr;      /* $01A */
    vuint16 intenar;      /* $01C */
    vuint16 intreqr;      /* $01E */
    uint8_t _pad020_08D[0x08E - 0x020]; /* $020-$08D: disk/copper/blitter/audio */
    vuint16 diwstrt;      /* $08E */
    vuint16 diwstop;      /* $090 */
    vuint16 ddfstrt;      /* $092 */
    vuint16 ddfstop;      /* $094 */
    vuint16 dmacon;       /* $096 */
    vuint16 clxcon;       /* $098 */
    vuint16 intena;       /* $09A */
    vuint16 intreq;       /* $09C */
    vuint16 adkcon;       /* $09E */
    uint8_t _pad0A0_17F[0x180 - 0x0A0]; /* $0A0-$17F: audio, sprite, playfield */
    vuint16 color[32];    /* $180-$1BE */
};

#define CUSTOM (*(struct Custom *)0xDFF000UL)

/*
 * Convenzioni di chiamata M68k.
 *
 * - vbcc:  void foo(__reg("d0") int x);  (qualificatore PRIMA del tipo)
 * - bebbo m68k-amigaos-gcc: int foo(int x asm("d0"));
 *
 * Non usare macro dopo il nome del parametro (sintassi invalida in entrambi).
 */

#endif /* AMIGA_HARDWARE_H */
