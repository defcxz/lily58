#include QMK_KEYBOARD_H
#include <stdio.h>
#include "timer.h"

// Definir el tap dance
enum {
    TD_ALT_CAPS,
};

// Función del tap dance
tap_dance_action_t tap_dance_actions[] = {
    [TD_ALT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_CAPS),
};

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BSPACE|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  Up  |  -   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  Up  | Left | Down |Right |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI |LALT  | /Space  /       \Enter \  |COMMA | DOT  |MINUS |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,   KC_RSFT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_QUOT,  KC_BSLS,  KC_N,    KC_M,    KC_SCLN, KC_LEFT, KC_DOWN, KC_RIGHT,
                        MO(_LOWER),   KC_LGUI, TD(TD_ALT_CAPS), KC_SPC, KC_ENT,  KC_COMM, KC_DOT,  KC_MINS
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | MUTE | VOL- | VOL+ |      |                    | F12  | F13  | F14  | F15  | F16  | F17  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT| NUBS | MRWD | MFFD |      |      |-------.    ,-------|      |      |      |      |      |  /   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |RAISE |      |      |      |      |      |-------|    |-------|      |      |      |      |  `   |  ]   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  | DEL  |  +   |  =   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_ESC,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TAB, _______,  KC_MUTE, KC_VOLD, KC_VOLU, _______,                     KC_F12,  _______, _______, _______, _______, _______,
  KC_LSFT, KC_NUBS,  KC_MRWD, KC_MFFD, _______, _______,                     MS_BTN1, MS_UP,   MS_BTN2, _______, _______, KC_SLSH,
  MO(_RAISE), _______,  _______, _______, _______, _______, _______, _______,   MS_LEFT, MS_DOWN, MS_RGHT, _______, KC_GRV,KC_RBRC,
                              _______, _______, _______, _______, _______,   KC_DEL, KC_PLUS, KC_EQL
),  

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |PGUP  |MWUP  |PGDN  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |MWLEFT|MWDOWN|MWRIGHT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG|RGB_M|RGB_VI|RGB_VD|RGB_HI|RGB_HD|-------.    ,-------|      |      |      |BTN1  | MUP  |BTN2  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |MLEFT |MDOWN |MRIGHT|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, KC_PGUP, MS_WHLU, KC_PGDN,
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, MS_WHLL, MS_WHLD, MS_WHLR,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD,                    _______, _______, _______, MS_BTN1, MS_UP,   MS_BTN2,
    _______, _______, _______, _______, RGB_SAI, RGB_SAD, _______, _______,  _______, _______, _______, MS_LEFT, MS_DOWN, MS_RGHT,
                                _______, _______, _______, _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, MS_WHLU, KC_PGDN,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLR,
  RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD,                   XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN1, MS_UP,   MS_BTN2,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// Añadir después de las definiciones de layers
static uint32_t startup_timer = 0;
static char time_str[16];      // Aumentado para asegurar espacio suficiente
static uint32_t keypress_counter = 0;
static char counter_str[12];   // Aumentado para asegurar espacio suficiente

void update_time_str(void) {
    uint32_t current = timer_read32() / 1000;
    if (!startup_timer) startup_timer = current;
    current -= startup_timer;
    
    uint8_t h = (current / 3600) % 24;
    uint8_t m = (current / 60) % 60;
    uint8_t s = current % 60;
    
    snprintf(time_str, sizeof(time_str), "T: %02u:%02u:%02u", h, m, s);
    snprintf(counter_str, sizeof(counter_str), "K >> %04lu", keypress_counter);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_ln(read_layer_state(), false);
        update_time_str();
        oled_write_ln(time_str, false);
        oled_write_ln(counter_str, false);
        oled_write_ln(read_keylog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        keypress_counter++;
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
    }
    return true;
}
