#ifndef DETECTMACMODE_H
#define DETECTMACMODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    MAC_MODE_LIGHT   =  0,
    MAC_MODE_DARK    =  1,
    MAC_MODE_UNKNOWN = -1
} MacMode;

/*
 * Returns the current macOS appearance.
 *
 * MAC_MODE_LIGHT   — light mode (also returned when the preference is unset,
 *                    which is the system default)
 * MAC_MODE_DARK    — dark mode
 * MAC_MODE_UNKNOWN — could not read the preference
 */
MacMode detect_mac_mode(void);

/* Convenience: returns 1 if dark mode is active, 0 otherwise. */
int is_dark_mode(void);

/* Convenience: returns 1 if light mode is active, 0 otherwise. */
int is_light_mode(void);

#ifdef __cplusplus
}
#endif

#endif /* DETECTMACMODE_H */
