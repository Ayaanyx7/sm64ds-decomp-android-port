#ifndef DAKPA3BG_C_H
#define DAKPA3BG_C_H

#include "types.h"
#include "dBgActor_c.h"

/* daKpa3Bg_c -- the Bowser-in-the-Sky arena platform.
 *
 * MEASURED, from ov060 (base 0x02111900, extracted/dsd/arm9_overlays/ov060.bin):
 *
 *   NAME    _ZTS10daKpa3Bg_c @ 0x0211a954 spells "10daKpa3Bg_c" -- the ROM's own
 *           name for the class that was coined `BowserSkyPlatform`.
 *   BASE    _ZTI10daKpa3Bg_c @ 0x0211a948 is an abi::__si_class_type_info (word 0
 *           = 0x0209a764) whose +8 base pointer is 0x021089ec = _ZTI10dBgActor_c
 *           (ov002). SECOND WITNESS: the vtable below is 32 words long and its
 *           slot 31 holds 0x020ee55c = dBgActor_c::Kill, the one slot dBgActor_c
 *           adds over dActor_c. Both witnesses agree.
 *   VTABLE  _ZTV10daKpa3Bg_c @ 0x0211a9b0; V-8 = 0, V-4 = 0x0211a948 (the _ZTI
 *           above), so 0x0211a9b0 IS the address point.
 *   SIZE    0x32c, the literal daKpa3Bg_c_classInit hands to
 *           fBase_c::operator new; the last member closes exactly on it.
 *
 * THE VTABLE was diffed slot by slot against _ZTV10dBgActor_c. Only the four
 * slots declared below hold ov060-resident words (0x021182b0, 0x021181e8,
 * 0x02118254, 0x0211822c), plus the two destructor slots (0x02117d1c D1,
 * 0x02117d60 D0); every other slot repeats the base's own word and is inherited,
 * so it is deliberately not redeclared here.
 *
 * The destructor is declared FIRST and inline on purpose: declared last it stops
 * being the key function, mwccarm then emits D0 ahead of D1 and objisolate
 * refuses the pair.
 */
struct daKpa3Bg_c : dBgActor_c {
    virtual ~daKpa3Bg_c() {}          /* slots 16 (D1), 17 (D0) */

    virtual s32 InitResources();      /* slot  0 -- 0x021182b0 */
    virtual s32 CleanupResources();   /* slot  3 -- 0x021181e8 */
    virtual s32 Behavior();           /* slot  6 -- 0x02118254 */
    virtual s32 Render();             /* slot  9 -- 0x0211822c */

    u32 mBossActorRef;                /* 0x320 -- fBase_c ref of the KOOPA3 boss */
    u16 mShakeTimer;                  /* 0x324 */
    u16 mCollapseTimer;               /* 0x326 */
    u8  mState;                       /* 0x328 -- index into data_ov060_0211b1ac */
    u8  mVariant;                     /* 0x329 -- spawn param & 0xf; picks file/CLPS */
    u8  mArmed;                       /* 0x32a */
    u8  mBossTouched;                 /* 0x32b */
};

typedef char daKpa3Bg_c_size_must_be_0x32c[sizeof(daKpa3Bg_c) == 0x32c ? 1 : -1];

#endif /* DAKPA3BG_C_H */
