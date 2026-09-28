# PR #3227: Player reference parameter

Input: dbd94c7c483db1b6c5603c7ec2a680b46461643e.
Task: pr3227-player-reference. Producer/integration owner: codex-pr3227-reference.
Independent reviewer: kpa3_review. Endpoint: push to existing PR #3227; no merge.

## Scope and authorization

Change func_ov002_020d7430 to take Player&, update its two source callers, and
remove its obsolete char* declaration from include/decl_common.h. The user
explicitly confirmed this exact prepared patch, including the scoped header edit
while jump-contract-repair-0918 reserves that header. That task's branch and
reservation remain untouched. No other shared-header declarations change.

The existing Player method passes *this directly. The remaining legacy free
function caller converts its char* at that call boundary. The callee retains a
char* view solely for its existing Hurt, state and address-named helper bridges.
C linkage preserves the enrolled symbol name. No layout, symbol/config identity,
attribution, enrollment, or baseline exception changes are needed.

Completion is partial: this exposes the evidenced Player object in the signature;
it does not complete the legacy caller, shared Player fields, or engine bridges.
The prior handoff pr3227-player-caller.md records those inherited limitations.

## Verification

The prepared patch's three functions independently passed the pinned compiler's
linked-byte probe before application: VERIFIED, diffs [], blind 0 for each:

- ov002 func_ov002_020d6790: 0x020d6790, size 0x208.
- ov002 func_ov002_020d7430: 0x020d7430, size 0xd4.
- ov002 Player::St_YoshiPower_Main: 0x020d7504, size 0x9cc.

Applied production declaration check:
`python tools/check_decl_agreement.py --changed dbd94c7c483db1b6c5603c7ec2a680b46461643e`
passes, with no new declaration disagreements. affected_src.py reports 535 source
consumers of decl_common.h; the header change only removes the obsolete unused
prototype. Full production, committed-range consumer checks and final independent
review are pending at this checkpoint. Next action: complete those checks and push
only the proven candidate to PR #3227.
