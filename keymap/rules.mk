# PERMISSIVE_HOLD = Always the modified output
# IGNORE_MOD_TAP_INTERRUPT = Always both keys, unless you hold both keys for at least TAPPING_TERM
# PERMISSIVE_HOLD + IGNORE_MOD_TAP_INTERRUPT = Modified output if the other key is released before the tap key, or when both keys are held longer than TAPPING_TERM. So both keys are output when releasing the tap key before the other key and held lesss than TAPPING_TERM

# # OLD config.h
# #ifndef CONFIG_USER_H
# #define CONFIG_USER_H

# #include "../../config.h"

# #undef TAPPING_TERM
# #define TAPPING_TERM 200
# #define PERMISSIVE_HOLD

# #define ONESHOT_TIMEOUT 500
# #define ONESHOT_TAP_TOGGLE 0

# /* prevent stuck modifiers */
# #define PREVENT_STUCK_MODIFIERS

RAW_ENABLE = yes

# Wake-up problemen 2019-08-13 https://github.com/qmk/qmk_firmware/issues/6369
NO_USB_STARTUP_CHECK = yes

DEBOUNCE = 15