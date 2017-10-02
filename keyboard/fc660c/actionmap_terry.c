#include "action.h"
#include "actionmap.h"
#include "hook.h"
#include "fc660c.h"


#define AC_L3       ACTION_LAYER_MOMENTARY(3)
#define AC_L4       ACTION_LAYER_MOMENTARY(4)
#define AC_LS_2     ACTION_LAYER_MODS(2, MOD_LSFT)
#define AC_RS_2     ACTION_LAYER_MODS(2, MOD_RSFT)
#define AC_TGL1     ACTION_LAYER_TOGGLE(1)
#define AC_SPC5     ACTION_LAYER_TAP_KEY(5, KC_SPC)
#define AC_SLS6     ACTION_LAYER_TAP_KEY(6, KC_SLSH)

#define AC_BACK     ACTION_MODS_KEY(MOD_LALT, KC_LEFT)
#define AC_FRWD     ACTION_MODS_KEY(MOD_LALT, KC_RIGHT)

#define AC_CLN		ACTION_MODS_KEY(MOD_LSFT, KC_SCLN)
#define AC_LSH 		ACTION_FUNCTION_TAP(LSHIFT_LCLN)

enum function_id {
    LSHIFT_LCLN,
};

#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
	ACTION_FUNCTION_TAP(LSHIFT_LCLN) //FN0
};


// emulates FC660C default keymap
#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [0] = KMAP( \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     PSCR,
        TAB, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,   LBRC,RBRC,BSLS,     DEL,
        ESC ,A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,     ENT,
        LSH, Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLS6,          RS_2,   UP,
        LCTL,  LGUI,LALT,          SPC5,                    L4, RALT ,L3,  LEFT,DOWN,RGHT
    ),
    [1] = KMAP(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL,
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLS6,          RSFT,UP,
        L4,  LGUI,LALT,          SPC,                    RALT,TRNS,L4,  LEFT,DOWN,RGHT
    ),
    [2] = KMAP(
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS
    ),
    [3] = KMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TRNS,
        CAPS,TGL1,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,TRNS,TRNS,HOME,PGUP,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,END, PGDN,TRNS,          TRNS,PGUP,
        L3,  TRNS,TRNS,          TRNS,                    TRNS,APP, L3,  HOME,PGDN,END
    ),
    [4] = KMAP(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TRNS,
        CAPS,TGL1,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,H,   J,   K,   L,   TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,END, PGDN,TRNS,          TRNS,PGUP,
        L4,  TRNS,TRNS,          TRNS,                    TRNS,APP, L4,  HOME,PGDN,END
    ),
    [5] = KMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, GRV,      TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WH_L,WH_D,MS_U,WH_U,WH_R,BTN4,BTN5,TRNS,     TRNS,
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,TRNS,MS_L,MS_D,MS_R,BTN1,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,BTN1,BACK,FRWD,TRNS,          TRNS,PGUP,
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,HOME,PGDN,END
    ),
    [6] = KMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TRNS,
        TRNS,HOME,PGDN,UP,  PGUP,END, HOME,PGDN,PGUP,END, TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,LEFT,DOWN,RGHT,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,     TRNS,
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,HOME,PGDN,PGUP,END, TRNS,     TRNS,PGUP,
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,HOME,PGDN,END
    ),
};


void hook_layer_change(uint32_t layer_state)
{
    // lights LED on Insert when layer 1 is enabled
    if (layer_state & (1L<<1)) {
        PORTB &= ~(1<<5);
    } else {
        PORTB |=  (1<<5);
    }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case LSHIFT_LCLN:
			// Modified into LShift + tap ':'
            // Shift parentheses example: LShft + tap '('
            // http://stevelosh.com/blog/2012/10/a-modern-space-cadet/#shift-parentheses
            // http://geekhack.org/index.php?topic=41989.msg1304899#msg1304899
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        register_mods(MOD_BIT(KC_LSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_LSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_SCLN);
                    unregister_code(KC_SCLN);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                }
            }
            break;
    }
}
