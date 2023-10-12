#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#define _PINNUM(port, pin) ((port)*32 + (pin))

#ifndef NRF_DFU_BL_ACCEPT_SAME_VERSION
#define NRF_DFU_BL_ACCEPT_SAME_VERSION 1
#endif

#ifndef NRF_DFU_REQUIRE_SIGNED_APP_UPDATE
#define NRF_DFU_REQUIRE_SIGNED_APP_UPDATE 1
#endif

#ifndef NRF_BL_APP_SIGNATURE_CHECK_REQUIRED
#define NRF_BL_APP_SIGNATURE_CHECK_REQUIRED 0
#endif

#ifndef NRF_DFU_FORCE_DUAL_BANK_APP_UPDATES
#define NRF_DFU_FORCE_DUAL_BANK_APP_UPDATES 1
#endif

#ifdef BOOTLOADER_DEBUG

#ifndef NRF_DFU_BL_ALLOW_DOWNGRADE
#define NRF_DFU_BL_ALLOW_DOWNGRADE 1
#endif

#ifndef NRF_LOG_ENABLED
#define NRF_LOG_ENABLED 1
#endif

#ifndef NRF_LOG_DEFAULT_LEVEL
#define NRF_LOG_DEFAULT_LEVEL 5
#endif

#ifndef APP_USBD_NRF_DFU_TRIGGER_CONFIG_LOG_ENABLED
#define APP_USBD_NRF_DFU_TRIGGER_CONFIG_LOG_ENABLED 1
#endif

#ifndef NRFX_USBD_CONFIG_LOG_ENABLED
#define NRFX_USBD_CONFIG_LOG_ENABLED 1
#endif

#ifndef APP_USBD_CDC_ACM_CONFIG_LOG_ENABLED
#define APP_USBD_CDC_ACM_CONFIG_LOG_ENABLED 1
#endif

#ifndef APP_USBD_CDC_ACM_CONFIG_LOG_LEVEL
#define APP_USBD_CDC_ACM_CONFIG_LOG_LEVEL 4
#endif

#ifndef NRFX_USBD_CONFIG_LOG_LEVEL
#define NRFX_USBD_CONFIG_LOG_LEVEL 4
#endif

#ifndef USBD_CONFIG_LOG_ENABLED
#define USBD_CONFIG_LOG_ENABLED 1
#endif

#ifndef USBD_CONFIG_LOG_LEVEL
#define USBD_CONFIG_LOG_LEVEL 4
#endif

/* enabled this if you only need to debug the bootloader via RTT, RTT cant work with bl and application simultaneously
#ifndef NRF_LOG_BACKEND_RTT_ENABLED
#define NRF_LOG_BACKEND_RTT_ENABLED 1
#endif

#ifndef NRF_LOG_BACKEND_SERIAL_USES_RTT
#define NRF_LOG_BACKEND_SERIAL_USES_RTT 1
#endif
*/

#ifndef NRF_SDH_BLE_LOG_LEVEL
#define NRF_SDH_BLE_LOG_LEVEL 5
#endif

#ifndef NRF_SDH_BLE_LOG_ENABLED
#define NRF_SDH_BLE_LOG_ENABLED 1
#endif

#ifndef NRF_SDH_LOG_ENABLED
#define NRF_SDH_LOG_ENABLED 1
#endif

#ifndef NRF_SDH_LOG_LEVEL
#define NRF_SDH_LOG_LEVEL 5
#endif

#else // BOOTLOADER_DEBUG not defined


#ifndef NRF_DFU_BL_ALLOW_DOWNGRADE
#define NRF_DFU_BL_ALLOW_DOWNGRADE 1
#endif

#ifndef NRF_LOG_ENABLED
#define NRF_LOG_ENABLED 0
#endif

#ifndef NRF_LOG_DEFAULT_LEVEL
#define NRF_LOG_DEFAULT_LEVEL 5
#endif

#ifndef APP_USBD_NRF_DFU_TRIGGER_CONFIG_LOG_ENABLED
#define APP_USBD_NRF_DFU_TRIGGER_CONFIG_LOG_ENABLED 0
#endif

#ifndef NRFX_USBD_CONFIG_LOG_ENABLED
#define NRFX_USBD_CONFIG_LOG_ENABLED 0
#endif

#ifndef APP_USBD_CDC_ACM_CONFIG_LOG_ENABLED
#define APP_USBD_CDC_ACM_CONFIG_LOG_ENABLED 0
#endif

#ifndef APP_USBD_CDC_ACM_CONFIG_LOG_LEVEL
#define APP_USBD_CDC_ACM_CONFIG_LOG_LEVEL 4
#endif

#ifndef NRFX_USBD_CONFIG_LOG_LEVEL
#define NRFX_USBD_CONFIG_LOG_LEVEL 4
#endif

#ifndef USBD_CONFIG_LOG_ENABLED
#define USBD_CONFIG_LOG_ENABLED 0
#endif

#ifndef USBD_CONFIG_LOG_LEVEL
#define USBD_CONFIG_LOG_LEVEL 4
#endif

#ifndef NRF_LOG_BACKEND_RTT_ENABLED
#define NRF_LOG_BACKEND_RTT_ENABLED 1
#endif

#ifndef NRF_LOG_BACKEND_SERIAL_USES_RTT
#define NRF_LOG_BACKEND_SERIAL_USES_RTT 1
#endif

#ifndef NRF_SDH_BLE_LOG_LEVEL
#define NRF_SDH_BLE_LOG_LEVEL 5
#endif

#ifndef NRF_SDH_BLE_LOG_ENABLED
#define NRF_SDH_BLE_LOG_ENABLED 1
#endif

#ifndef NRF_SDH_LOG_ENABLED
#define NRF_SDH_LOG_ENABLED 1
#endif

#ifndef NRF_SDH_LOG_LEVEL
#define NRF_SDH_LOG_LEVEL 5
#endif

#endif // BOOTLOADER_DEBUG

#ifndef NRF_DFU_BL_ALLOW_DOWNGRADE
#define NRF_DFU_BL_ALLOW_DOWNGRADE 0
#endif

#ifdef __cplusplus
}
#endif

#endif // APP_CONFIG_H