#ifndef AMIGA_LVO_H
#define AMIGA_LVO_H

/* Offset vettori Exec (A6) per chiamate AmigaOS.
 * Generato da tools/symbols_to_units.py <- amiga_data.json.
 * Sottoinsieme comune: ricontrollare contro NDK3.x
 * include/lvo/exec_lib.i prima del matching byte-perfect. */

#define _LVOAbortIO -480
#define _LVOAddHead -240
#define _LVOAddPort -354
#define _LVOAddTail -246
#define _LVOAllocMem -198
#define _LVOAllocSignal -330
#define _LVOAvailMem -216
#define _LVOCheckIO -468
#define _LVOCloseDevice -450
#define _LVOCloseLibrary -414
#define _LVODisable -120
#define _LVODoIO -456
#define _LVOEnable -126
#define _LVOEnqueue -270
#define _LVOFindName -276
#define _LVOFindPort -390
#define _LVOFindTask -294
#define _LVOForbid -132
#define _LVOFreeMem -210
#define _LVOFreeSignal -336
#define _LVOGetMsg -372
#define _LVOOldOpenLibrary -408
#define _LVOOpenDevice -444
#define _LVOOpenLibrary -552
#define _LVOPermit -138
#define _LVOPutMsg -366
#define _LVORawDoFmt -522
#define _LVORemHead -258
#define _LVORemPort -360
#define _LVORemTail -264
#define _LVORemove -252
#define _LVOReplyMsg -378
#define _LVOSendIO -462
#define _LVOSetExcept -312
#define _LVOSetSignal -306
#define _LVOSignal -324
#define _LVOSupervisor -30
#define _LVOWait -318
#define _LVOWaitIO -474
#define _LVOWaitPort -384

#endif /* AMIGA_LVO_H */
