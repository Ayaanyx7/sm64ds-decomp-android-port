extern void *_ZN7fBase_cnwEj(unsigned);
extern void _ZN10dBgActor_cC2Ev(void *);
extern int _ZTV10daKpa3Bg_c[];
int *daKpa3Bg_c_classInit(void)
{
    int *p = (int *)_ZN7fBase_cnwEj(812);
    if (p) { _ZN10dBgActor_cC2Ev(p); p[0] = (int)_ZTV10daKpa3Bg_c; }
    return p;
}
