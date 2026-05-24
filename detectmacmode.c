#include "detectmacmode.h"
#include <CoreFoundation/CoreFoundation.h>

MacMode detect_mac_mode(void) {
    CFStringRef value = (CFStringRef)CFPreferencesCopyValue(
        CFSTR("AppleInterfaceStyle"),
        CFSTR("NSGlobalDomain"),
        kCFPreferencesCurrentUser,
        kCFPreferencesAnyHost
    );

    if (value == NULL) {
        /* Preference absent → system is in light mode (the default). */
        return MAC_MODE_LIGHT;
    }

    MacMode mode;
    if (CFGetTypeID(value) == CFStringGetTypeID() &&
        CFStringCompare(value, CFSTR("Dark"), kCFCompareCaseInsensitive) == kCFCompareEqualTo) {
        mode = MAC_MODE_DARK;
    } else {
        mode = MAC_MODE_UNKNOWN;
    }

    CFRelease(value);
    return mode;
}

int is_dark_mode(void) {
    return detect_mac_mode() == MAC_MODE_DARK;
}

int is_light_mode(void) {
    return detect_mac_mode() == MAC_MODE_LIGHT;
}
