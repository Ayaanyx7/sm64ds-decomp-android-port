# PR #3227: readable legacy Player caller

User-requested follow-up to `9fed4ec3d55f3c4413173d53e3d8b734e6541fe9`.
Scope: `src/func_ov002_020d7430.cpp`, ov002 `[0x020d7430, 0x020d7504)`.
Task: `pr3227-player-caller`; producer/integration owner: `codex-pr3227-caller`.
Independent source reviewer: `kpa3_review`. Publication endpoint: push to PR #3227;
merge is outside this request.

The legacy C entry point keeps its existing `char*` ABI. One typed Player reference
replaces the cast at the method call. Real dActor_c virtuals replace the fabricated
20-slot Obj interface; position and mouth-actor accesses use existing named fields.
The mouth actor is intentionally reloaded after the Player method call. Sound uses
its existing namespace declaration. No header, symbol, enrollment or credit changes.

## Exact local proof

Pinned compiler canary: 2004/b56. Final focused command:

```
python tools/linkcheck.py --name func_ov002_020d7430 --c src/func_ov002_020d7430.cpp --addr 0x020d7430 --size 0xd4 --module ov002 --json build/player-caller-link-final.json
python tools/check_decl_agreement.py --changed 9fed4ec3d55f3c4413173d53e3d8b734e6541fe9
```

Link result: VERIFIED, diffs [], blind 0; all 212 linked bytes reproduce the ROM.
Declaration ratchet: no new disagreements. No baseline exceptions added.
Full production verification and independent review are pending at this checkpoint.

## Remaining reconstruction and measured alternative

Completion is partial. Player.h still represents mObjInMouth as s32 and the
camera-space position as three scalar fields. Their pointer/vector views retain
casts. The caller's char* ABI, Hurt bridge, state interfaces and address-named helper
remain migration work, not demonstrated compiler restrictions. Existing caller and
shared Player interfaces are outside this one-function scope.

Experiment: declare both data_ov002_02110034 and data_ov002_0211013c as Player::State,
then replace the two mangled calls with player.IsState(data_ov002_02110034) and
player.ChangeState(data_ov002_0211013c). This cleaner version also returned VERIFIED,
diffs [], blind 0. Declaration agreement rejected the new global declarations:
02110034's plurality is the separate legacy State type (St_Swallow_Init.cpp), and
0211013c's plurality is int[] (St_Bonk_Main.cpp). The final patch therefore preserves
the original state declarations/calls; it adds neither type-laundering casts nor
baseline entries to conceal the disagreement. A coordinated state-interface repair
must settle the other declarations before adopting this measured alternative.

Next owner: the Player reconstruction producer, tracked through PR #3227 and its
existing Player interface work. Next action after this focused follow-up: reconcile
the state-global declaration population, then adopt native state calls and prove
all affected consumers. The byte-identical experiment above establishes that this
caller's compiler output is not the blocker.
