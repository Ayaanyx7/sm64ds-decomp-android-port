//cpp
// @symbol _ZN10daKpa3Bg_c16CleanupResourcesEv
#include "daKpa3Bg_c.h"
/* recovered: renamed to Class_Method, RTTI class fields named, declarations from a shared header */
#include "decl_common.h"
// recovered name: daKpa3Bg_c_CleanupResources
/* recovered: renamed to Class_Method */
/* daKpa3Bg_c::CleanupResources - name recovered from the vtable slot it fills.
   The body is a decompilation verified against the ROM, not an
   inferred stub. */
extern "C" {
extern void _ZN13SharedFilePtr7ReleaseEv(void *);
extern void *data_ov060_02119514[];
extern void *data_ov060_0211953c[];
}

s32 daKpa3Bg_c::CleanupResources() {
    char * c = (char *)this;
    struct daKpa3Bg_c *self = (struct daKpa3Bg_c *)(void *)c;
    _ZN4dBgW7DisableEv(c + 0x124);
    _ZN13SharedFilePtr7ReleaseEv(data_ov060_02119514[self->mVariant]);
    _ZN13SharedFilePtr7ReleaseEv(data_ov060_0211953c[self->mVariant]);
    return 1;
}
