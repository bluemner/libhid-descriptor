/**
 * 
 * [Class Definition](https://www.usb.org/document-library/device-class-definition-hid-111]
 * PDF USB hid1_11.pdf https://www.usb.org/sites/default/files/documents/hid1_11.pdf
 * 
 * [Usage Tables](https://www.usb.org/document-library/hid-usage-tables-13)
 * PDF USB hut1_3_0.pdf https://usb.org/sites/default/files/hut1_3_0.pdf
 */
#ifndef __LIBHID_EVENT_CODES_H__
#define __LIBHID_EVENT_CODES_H__

#define HID_TYPE 0xFC
#define HID_SIZE 0x03

#define HID_MAIN_INPUT               0x80
#define HID_MAIN_OUTPUT              0x90
#define HID_MAIN_COLLECTION          0xA0
#define HID_MAIN_FEATURE             0xB0
#define HID_MAIN_END_COLLECTION      0xC0

#define HID_TEXT_RESERVED "Reserved"

/*
 * 6.2.2.7 Global Items [Class Definition]
 */
#define HID_GLOBAL_USAGE_PAGE        0x04
#define HID_GLOBAL_LOGICAL_MINIMUM   0x14
#define HID_GLOBAL_LOGICAL_MAXIMUM   0x24
#define HID_GLOBAL_PHYSICAL_MINIMUM  0x34
#define HID_GLOBAL_PHYSICAL_MAXIMUM  0x44
#define HID_GLOBAL_UNIT_EXPONENT     0x54
#define HID_GLOBAL_UNIT              0x64
#define HID_GLOBAL_REPORT_SIZE       0x74
#define HID_GLOBAL_REPORT_ID         0x84
#define HID_GLOBAL_REPORT_COUNT      0x94
#define HID_GLOBAL_PUSH              0xA4
#define HID_GLOBAL_POP               0xB4
#define HID_GLOBAL_RESERVED          0xC4 ... 0xF4

/** 
 * Chapter 3 Usage Pages [Usage Tables]
 ***/
#define HID_USAGE_PAGE_UNDEFINED  0x00 
#define HID_USAGE_PAGE_GENERIC_DESKTOP_PAGE  0x01 
#define HID_USAGE_PAGE_SIMULATION_CONTROLS_PAGE  0x02 
#define HID_USAGE_PAGE_VR_CONTROLS_PAGE  0x03 
#define HID_USAGE_PAGE_SPORT_CONTROLS_PAGE  0x04 
#define HID_USAGE_PAGE_GAME_CONTROLS_PAGE  0x05 
#define HID_USAGE_PAGE_GENERIC_DEVICE_CONTROLS_PAGE  0x06 
#define HID_USAGE_PAGE_KEYBOARD_KEYPAD_PAGE  0x07 
#define HID_USAGE_PAGE_LED_PAGE  0x08 
#define HID_USAGE_PAGE_BUTTON_PAGE  0x09 
#define HID_USAGE_PAGE_ORDINAL_PAGE  0x0A 
#define HID_USAGE_PAGE_TELEPHONY_DEVICE_PAGE  0x0B 
#define HID_USAGE_PAGE_CONSUMER_PAGE  0x0C 
#define HID_USAGE_PAGE_DIGITIZERS_PAGE  0x0D 
#define HID_USAGE_PAGE_HAPTICS_PAGE  0x0E 
#define HID_USAGE_PAGE_PHYSICAL_INPUT_DEVICE_PAGE  0x0F 
#define HID_USAGE_PAGE_UNICODE_PAGE  0x10 
#define HID_USAGE_PAGE_RESERVED_1  0x11 ... 0x11 
#define HID_USAGE_PAGE_EYE_AND_HEAD_TRACKERS_PAGE  0x12 
#define HID_USAGE_PAGE_RESERVED_2  0x13 ... 0x13 
#define HID_USAGE_PAGE_AUXILIARY_DISPLAY_PAGE  0x14 
#define HID_USAGE_PAGE_RESERVED_3  0x15 ... 0x1F 
#define HID_USAGE_PAGE_SENSORS_PAGE  0x20 
#define HID_USAGE_PAGE_RESERVED_4  0x21 ... 0x3F 
#define HID_USAGE_PAGE_MEDICAL_INSTRUMENT_PAGE  0x40 
#define HID_USAGE_PAGE_BRAILLE_DISPLAY_PAGE  0x41 
#define HID_USAGE_PAGE_RESERVED_5  0x42 ... 0x58 
#define HID_USAGE_PAGE_LIGHTING_AND_ILLUMINATION_PAGE  0x59 
#define HID_USAGE_PAGE_RESERVED_6  0x5A ... 0x7F 
#define HID_USAGE_PAGE_MONITOR_PAGE  0x80 
#define HID_USAGE_PAGE_MONITOR_ENUMERATED_PAGE  0x81 
#define HID_USAGE_PAGE_VESA_VIRTUAL_CONTROLS_PAGE  0x82 
#define HID_USAGE_PAGE_RESERVED_7  0x83 ... 0x83 
#define HID_USAGE_PAGE_POWER_PAGE  0x84 
#define HID_USAGE_PAGE_BATTERY_SYSTEM_PAGE  0x85 
#define HID_USAGE_PAGE_RESERVED_8  0x86 ... 0x8B 
#define HID_USAGE_PAGE_BARCODE_SCANNER_PAGE  0x8C 
#define HID_USAGE_PAGE_SCALES_PAGE  0x8D 
#define HID_USAGE_PAGE_MAGNETIC_STRIPE_READER_PAGE  0x8E 
#define HID_USAGE_PAGE_RESERVED_9  0x8F ... 0x8F 
#define HID_USAGE_PAGE_CAMERA_CONTROL_PAGE  0x90 
#define HID_USAGE_PAGE_ARCADE_PAGE  0x91 
#define HID_USAGE_PAGE_GAMING_DEVICE_PAGE  0x92 
#define HID_USAGE_PAGE_RESERVED_10  0x93 ... 0xF1CF 
#define HID_USAGE_PAGE_FIDO_ALLIANCE_PAGE  0xF1D0  
#define HID_USAGE_PAGE_RESERVED_11  0xF1D1 ... 0xFEFF 
#define HID_USAGE_PAGE_VENDOR_DEFINED  0xFF00 ... 0xFFFF 

#define HID_USAGE_PAGE_MAX 0xFFFF
#define HID_USAGE_PAGE_CNT (HID_USAGE_PAGE_MAX + 1)

/**
 * Chapter 4
 * Generic Desktop Page (0x01) [Usage Tables]
 */
#define HID_GENERIC_DESKTOP_PAGE_UNDEFINED 0x00
#define HID_GENERIC_DESKTOP_PAGE_POINTER 0x01
#define HID_GENERIC_DESKTOP_PAGE_MOUSE 0x02
#define HID_GENERIC_DESKTOP_PAGE_RESERVED_0 0x03 ... 0x03
#define HID_GENERIC_DESKTOP_PAGE_JOYSTICK 0x04
#define HID_GENERIC_DESKTOP_PAGE_GAME_PAD 0x05
#define HID_GENERIC_DESKTOP_PAGE_KEYBOARD 0x06
#define HID_GENERIC_DESKTOP_PAGE_KEYPAD 0x07
#define HID_GENERIC_DESKTOP_PAGE_MULTI_AXIS_CONTROLLER 0x08
#define HID_GENERIC_DESKTOP_PAGE_RESERVED_1 0x09 ... 0x2F
#define HID_GENERIC_DESKTOP_PAGE_X 0x30
#define HID_GENERIC_DESKTOP_PAGE_Y 0x31
#define HID_GENERIC_DESKTOP_PAGE_Z 0x32
#define HID_GENERIC_DESKTOP_PAGE_RX 0x33
#define HID_GENERIC_DESKTOP_PAGE_RY 0x34
#define HID_GENERIC_DESKTOP_PAGE_RZ 0x35
#define HID_GENERIC_DESKTOP_PAGE_SLIDER 0x36
#define HID_GENERIC_DESKTOP_PAGE_DIAL 0x37
#define HID_GENERIC_DESKTOP_PAGE_WHEEL 0x38
#define HID_GENERIC_DESKTOP_PAGE_HAT_SWITCH 0x39
#define HID_GENERIC_DESKTOP_PAGE_COUNTED_BUFFER 0x3A
#define HID_GENERIC_DESKTOP_PAGE_BYTE_COUNT 0x3B
#define HID_GENERIC_DESKTOP_PAGE_MOTION_WAKEUP 0x3C
#define HID_GENERIC_DESKTOP_PAGE_START 0x3D
#define HID_GENERIC_DESKTOP_PAGE_SELECT 0x3E
#define HID_GENERIC_DESKTOP_PAGE_RESERVED_2 0x3F ... 0x3F
#define HID_GENERIC_DESKTOP_PAGE_VX 0x40
#define HID_GENERIC_DESKTOP_PAGE_VY 0x41
#define HID_GENERIC_DESKTOP_PAGE_VZ 0x42
#define HID_GENERIC_DESKTOP_PAGE_VBRX 0x43
#define HID_GENERIC_DESKTOP_PAGE_VBRY 0x44
#define HID_GENERIC_DESKTOP_PAGE_VBRZ 0x45
#define HID_GENERIC_DESKTOP_PAGE_VNO 0x46
#define HID_GENERIC_DESKTOP_PAGE_FEATURE_NOTIFICATION 0x47
#define HID_GENERIC_DESKTOP_PAGE_RESERVED_3 0x48 ... 0x7F
#define HID_GENERIC_DESKTOP_PAGE_SYS_CONTROL 0x80
#define HID_GENERIC_DESKTOP_PAGE_SYS_POWER_DOWN 0x81
#define HID_GENERIC_DESKTOP_PAGE_SYS_SLEEP 0x82
#define HID_GENERIC_DESKTOP_PAGE_SYS_WAKE_UP 0x83
#define HID_GENERIC_DESKTOP_PAGE_SYS_CONTEXT_MENU 0x84
#define HID_GENERIC_DESKTOP_PAGE_SYS_MAIN_MENU 0x85
#define HID_GENERIC_DESKTOP_PAGE_SYS_APP_MENU 0x86
#define HID_GENERIC_DESKTOP_PAGE_SYS_MENU_HELP 0x87
#define HID_GENERIC_DESKTOP_PAGE_SYS_MENU_EXIT 0x88
#define HID_GENERIC_DESKTOP_PAGE_SYS_MENU_SELECT 0x89
#define HID_GENERIC_DESKTOP_PAGE_SYS_MENU_RIGHT 0x8A
#define HID_GENERIC_DESKTOP_PAGE_SYS_MENU_LEFT 0x8B
#define HID_GENERIC_DESKTOP_PAGE_SYS_MENU_UP 0x8C
#define HID_GENERIC_DESKTOP_PAGE_SYS_MENU_DOWN 0x8D
#define HID_GENERIC_DESKTOP_PAGE_SYS_COLD_RESTART 0x8E
#define HID_GENERIC_DESKTOP_PAGE_SYS_WARM_RESTART 0x8F
#define HID_GENERIC_DESKTOP_PAGE_D_PAD_UP 0x90
#define HID_GENERIC_DESKTOP_PAGE_D_PAD_DOWN 0x91
#define HID_GENERIC_DESKTOP_PAGE_D_PAD_RIGHT 0x92
#define HID_GENERIC_DESKTOP_PAGE_D_PAD_LEFT 0x93
#define HID_GENERIC_DESKTOP_PAGE_RESERVED_4 0x94 ... 0x9F
#define HID_GENERIC_DESKTOP_PAGE_SYS_DOCK 0xA0
#define HID_GENERIC_DESKTOP_PAGE_SYS_UNDOCK 0xA1
#define HID_GENERIC_DESKTOP_PAGE_SYS_SETUP 0xA2
#define HID_GENERIC_DESKTOP_PAGE_SYS_BREAK 0xA3
#define HID_GENERIC_DESKTOP_PAGE_SYS_DEBUGGER_BREAK 0xA4
#define HID_GENERIC_DESKTOP_PAGE_APPLICATION_BREAK 0xA5
#define HID_GENERIC_DESKTOP_PAGE_APPLICATION_DEBUGGER_BREAK 0xA6
#define HID_GENERIC_DESKTOP_PAGE_SYS_SPEAKER_MUTE 0xA7
#define HID_GENERIC_DESKTOP_PAGE_SYS_HIBERNATE 0xA8
#define HID_GENERIC_DESKTOP_PAGE_RESERVED_5 0xA9 ... 0xAF
#define HID_GENERIC_DESKTOP_PAGE_SYS_DISPLAY_INVERT 0xB0
#define HID_GENERIC_DESKTOP_PAGE_SYS_DISPLAY_INTERNAL 0xB1
#define HID_GENERIC_DESKTOP_PAGE_SYS_DISPLAY_EXTERNAL 0xB2
#define HID_GENERIC_DESKTOP_PAGE_SYS_DISPLAY_BOTH 0xB3
#define HID_GENERIC_DESKTOP_PAGE_SYS_DISPLAY_DUAL 0xB4
#define HID_GENERIC_DESKTOP_PAGE_SYS_DISPLAY_TOGGLE_INT_EXT 0xB5
#define HID_GENERIC_DESKTOP_PAGE_SYS_DISPLAY_SWAP 0xB6
#define HID_GENERIC_DESKTOP_PAGE_SYS_DISPLAY_LCD_AUTOSCALE 0xB7


#define HID_GENERIC_DESKTOP_PAGE_MAX 0xB7
#define HID_GENERIC_DESKTOP_PAGE_CNT (HID_GENERIC_DESKTOP_PAGE_MAX + 1)



#define HID_LOCAL_USAGE              0x08
#define HID_LOCAL_USAGE_MINIMUM      0x18
#define HID_LOCAL_USAGE_MAXIMUM      0x28

/*
 * 6.2.2.6 Collection, End Collection Items [Class Definition]
 * */
#define HID_COLLECTION_PHYSICAL       0x00
#define HID_COLLECTION_APPLICATION    0x01
#define HID_COLLECTION_LOGICAL        0x02
#define HID_COLLECTION_REPORT         0x03
#define HID_COLLECTION_NAMED_ARRAY    0x04
#define HID_COLLECTION_USAGE_SWITCH   0x05
#define HID_COLLECTION_USAGE_MODIFIER 0x06
#define HID_COLLECTION_RESERVED       0x07 ... 0x7F
#define HID_COLLECTION_VENDOR_DEFINED 0x80 ... 0xFF 

#define HID_COLLECTION_MAX 0xFF
#define HID_COLLECTION_CNT (HID_COLLECTION_MAX+1)
/* 
 * Chapter 15 
 * Consumer Page (0x0C) [Usage Tables]
 * 
 */
#define HID_CONSUMER_PAGE_UNASSIGNED 0x00
#define HID_CONSUMER_PAGE_CONSUMER_CONTROL 0x01
#define HID_CONSUMER_PAGE_NUMERIC_KEY_PAD 0x02
#define HID_CONSUMER_PAGE_PROGRAMMABLE_BUTTONS 0x03
#define HID_CONSUMER_PAGE_MICROPHONE 0x04
#define HID_CONSUMER_PAGE_HEADPHONE 0x05
#define HID_CONSUMER_PAGE_GRAPHIC_EQUALIZER 0x06
#define HID_CONSUMER_PAGE_RESERVED_0 0x07 ... 0x1F
#define HID_CONSUMER_PAGE__10 0x20
#define HID_CONSUMER_PAGE__100 0x21
#define HID_CONSUMER_PAGE_AM_PM 0x22
#define HID_CONSUMER_PAGE_RESERVED_1 0x23 ... 0x2F
#define HID_CONSUMER_PAGE_POWER 0x30
#define HID_CONSUMER_PAGE_RESET 0x31
#define HID_CONSUMER_PAGE_SLEEP 0x32
#define HID_CONSUMER_PAGE_SLEEP_AFTER 0x33
#define HID_CONSUMER_PAGE_SLEEP_MODE 0x34
#define HID_CONSUMER_PAGE_ILLUMINATION 0x35
#define HID_CONSUMER_PAGE_FUNCTION_BUTTONS 0x36
#define HID_CONSUMER_PAGE_RESERVED_2 0x37 ... 0x3F
#define HID_CONSUMER_PAGE_MENU 0x40
#define HID_CONSUMER_PAGE_MENU_PICK 0x41
#define HID_CONSUMER_PAGE_MENU_UP 0x42
#define HID_CONSUMER_PAGE_MENU_DOWN 0x43
#define HID_CONSUMER_PAGE_MENU_LEFT 0x44
#define HID_CONSUMER_PAGE_MENU_RIGHT 0x45
#define HID_CONSUMER_PAGE_MENU_ESCAPE 0x46
#define HID_CONSUMER_PAGE_MENU_VALUE_INCREASE 0x47
#define HID_CONSUMER_PAGE_MENU_VALUE_DECREASE 0x48
#define HID_CONSUMER_PAGE_RESERVED_3 0x49 ... 0x5F
#define HID_CONSUMER_PAGE_DATA_ON_SCREEN 0x60
#define HID_CONSUMER_PAGE_CLOSED_CAPTION 0x61
#define HID_CONSUMER_PAGE_CLOSED_CAPTION_SELECT 0x62
#define HID_CONSUMER_PAGE_VCR_TV 0x63
#define HID_CONSUMER_PAGE_BROADCAST_MODE 0x64
#define HID_CONSUMER_PAGE_SNAPSHOT 0x65
#define HID_CONSUMER_PAGE_STILL 0x66
#define HID_CONSUMER_PAGE_RESERVED_4 0x67 ... 0x7F
#define HID_CONSUMER_PAGE_SELECTION 0x80
#define HID_CONSUMER_PAGE_ASSIGN_SELECTION 0x81
#define HID_CONSUMER_PAGE_MODE_STEP 0x82
#define HID_CONSUMER_PAGE_RECALL_LAST 0x83
#define HID_CONSUMER_PAGE_ENTER_CHANNEL 0x84
#define HID_CONSUMER_PAGE_ORDER_MOVIE 0x85
#define HID_CONSUMER_PAGE_CHANNEL 0x86
#define HID_CONSUMER_PAGE_MEDIA_SELECTION 0x87
#define HID_CONSUMER_PAGE_MEDIA_SELECT_COMPUTER 0x88
#define HID_CONSUMER_PAGE_MEDIA_SELECT_TV 0x89
#define HID_CONSUMER_PAGE_MEDIA_SELECT_WWW 0x8A
#define HID_CONSUMER_PAGE_MEDIA_SELECT_DVD 0x8B
#define HID_CONSUMER_PAGE_MEDIA_SELECT_TELEPHONE 0x8C
#define HID_CONSUMER_PAGE_MEDIA_SELECT_PROGRAM_GUIDE 0x8D
#define HID_CONSUMER_PAGE_MEDIA_SELECT_VIDEO_PHONE 0x8E
#define HID_CONSUMER_PAGE_MEDIA_SELECT_GAMES 0x8F
#define HID_CONSUMER_PAGE_MEDIA_SELECT_MESSAGES 0x90
#define HID_CONSUMER_PAGE_MEDIA_SELECT_CD 0x91
#define HID_CONSUMER_PAGE_MEDIA_SELECT_VCR 0x92
#define HID_CONSUMER_PAGE_MEDIA_SELECT_TUNER 0x93
#define HID_CONSUMER_PAGE_QUIT 0x94
#define HID_CONSUMER_PAGE_HELP 0x95
#define HID_CONSUMER_PAGE_MEDIA_SELECT_TAPE 0x96
#define HID_CONSUMER_PAGE_MEDIA_SELECT_CABLE 0x97
#define HID_CONSUMER_PAGE_MEDIA_SELECT_SATELLITE 0x98
#define HID_CONSUMER_PAGE_MEDIA_SELECT_SECURITY 0x99
#define HID_CONSUMER_PAGE_MEDIA_SELECT_HOME 0x9A
#define HID_CONSUMER_PAGE_MEDIA_SELECT_CALL 0x9B
#define HID_CONSUMER_PAGE_CHANNEL_INCREMENT 0x9C
#define HID_CONSUMER_PAGE_CHANNEL_DECREMENT 0x9D
#define HID_CONSUMER_PAGE_MEDIA_SELECT_SAP 0x9E
#define HID_CONSUMER_PAGE_RESERVED_5 0x9F ... 0x9F
#define HID_CONSUMER_PAGE_VCR_PLUS 0xA0
#define HID_CONSUMER_PAGE_ONCE 0xA1
#define HID_CONSUMER_PAGE_DAILY 0xA2
#define HID_CONSUMER_PAGE_WEEKLY 0xA3
#define HID_CONSUMER_PAGE_MONTHLY 0xA4
#define HID_CONSUMER_PAGE_RESERVED_6 0xA5 ... 0xAF
#define HID_CONSUMER_PAGE_PLAY 0xB0
#define HID_CONSUMER_PAGE_PAUSE 0xB1
#define HID_CONSUMER_PAGE_RECORD 0xB2
#define HID_CONSUMER_PAGE_FAST_FORWARD 0xB3
#define HID_CONSUMER_PAGE_REWIND 0xB4
#define HID_CONSUMER_PAGE_SCAN_NEXT_TRACK 0xB5
#define HID_CONSUMER_PAGE_SCAN_PREVIOUS_TRACK 0xB6
#define HID_CONSUMER_PAGE_STOP 0xB7
#define HID_CONSUMER_PAGE_EJECT 0xB8
#define HID_CONSUMER_PAGE_RANDOM_PLAY 0xB9
#define HID_CONSUMER_PAGE_SELECT_DISC 0xBA
#define HID_CONSUMER_PAGE_ENTER_DISC 0xBB
#define HID_CONSUMER_PAGE_REPEAT 0xBC
#define HID_CONSUMER_PAGE_TRACKING 0xBD
#define HID_CONSUMER_PAGE_TRACK_NORMAL 0xBE
#define HID_CONSUMER_PAGE_SLOW_TRACKING 0xBF
#define HID_CONSUMER_PAGE_FRAME_FORWARD 0xC0
#define HID_CONSUMER_PAGE_FRAME_BACK 0xC1
#define HID_CONSUMER_PAGE_MARK 0xC2
#define HID_CONSUMER_PAGE_CLEAR_MARK 0xC3
#define HID_CONSUMER_PAGE_REPEAT_FROM_MARK 0xC4
#define HID_CONSUMER_PAGE_RETURN_TO_MARK 0xC5
#define HID_CONSUMER_PAGE_SEARCH_MARK_FORWARD 0xC6
#define HID_CONSUMER_PAGE_SEARCH_MARK_BACKWARDS 0xC7
#define HID_CONSUMER_PAGE_COUNTER_RESET 0xC8
#define HID_CONSUMER_PAGE_SHOW_COUNTER 0xC9
#define HID_CONSUMER_PAGE_TRACKING_INCREMENT 0xCA
#define HID_CONSUMER_PAGE_TRACKING_DECREMENT 0xCB
#define HID_CONSUMER_PAGE_STOP_EJECT 0xCC
#define HID_CONSUMER_PAGE_PLAY_PAUSE 0xCD
#define HID_CONSUMER_PAGE_PLAY_SKIP 0xCE
#define HID_CONSUMER_PAGE_RESERVED_7 0xCF ... 0xDF
#define HID_CONSUMER_PAGE_VOLUME 0xE0
#define HID_CONSUMER_PAGE_BALANCE 0xE1
#define HID_CONSUMER_PAGE_MUTE 0xE2
#define HID_CONSUMER_PAGE_BASS 0xE3
#define HID_CONSUMER_PAGE_TREBLE 0xE4
#define HID_CONSUMER_PAGE_BASS_BOOST 0xE5
#define HID_CONSUMER_PAGE_SURROUND_MODE 0xE6
#define HID_CONSUMER_PAGE_LOUDNESS 0xE7
#define HID_CONSUMER_PAGE_MPX 0xE8
#define HID_CONSUMER_PAGE_VOLUME_INCREMENT 0xE9
#define HID_CONSUMER_PAGE_VOLUME_DECREMENT 0xEA
#define HID_CONSUMER_PAGE_RESERVED_8 0xEB ... 0xEF
#define HID_CONSUMER_PAGE_SPEED_SELECT 0xF0
#define HID_CONSUMER_PAGE_PLAYBACK_SPEED 0xF1
#define HID_CONSUMER_PAGE_STANDARD_PLAY 0xF2
#define HID_CONSUMER_PAGE_LONG_PLAY 0xF3
#define HID_CONSUMER_PAGE_EXTENDED_PLAY 0xF4
#define HID_CONSUMER_PAGE_SLOW 0xF5
#define HID_CONSUMER_PAGE_RESERVED_9 0xF6 ... 0xFF
#define HID_CONSUMER_PAGE_FAN_ENABLE 0x100
#define HID_CONSUMER_PAGE_FAN_SPEED 0x101
#define HID_CONSUMER_PAGE_LIGHT_ENABLE 0x102
#define HID_CONSUMER_PAGE_LIGHT_ILLUMINATION_LEVEL 0x103
#define HID_CONSUMER_PAGE_CLIMATE_CONTROL_ENABLE 0x104
#define HID_CONSUMER_PAGE_ROOM_TEMPERATURE 0x105
#define HID_CONSUMER_PAGE_SECURITY_ENABLE 0x106
#define HID_CONSUMER_PAGE_FIRE_ALARM 0x107
#define HID_CONSUMER_PAGE_POLICE_ALARM 0x108
#define HID_CONSUMER_PAGE_PROXIMITY 0x109
#define HID_CONSUMER_PAGE_MOTION 0x10A
#define HID_CONSUMER_PAGE_DURESS_ALARM 0x10B
#define HID_CONSUMER_PAGE_HOLDUP_ALARM 0x10C
#define HID_CONSUMER_PAGE_MEDICAL_ALARM 0x10D
#define HID_CONSUMER_PAGE_RESERVED_10 0x10E ... 0x14F
#define HID_CONSUMER_PAGE_BALANCE_RIGHT 0x150
#define HID_CONSUMER_PAGE_BALANCE_LEFT 0x151
#define HID_CONSUMER_PAGE_BASS_INCREMENT 0x152
#define HID_CONSUMER_PAGE_BASS_DECREMENT 0x153
#define HID_CONSUMER_PAGE_TREBLE_INCREMENT 0x154
#define HID_CONSUMER_PAGE_TREBLE_DECREMENT 0x155
#define HID_CONSUMER_PAGE_RESERVED_11 0x156 ... 0x15F
#define HID_CONSUMER_PAGE_SPEAKER_SYSTEM 0x160
#define HID_CONSUMER_PAGE_CHANNEL_LEFT 0x161
#define HID_CONSUMER_PAGE_CHANNEL_RIGHT 0x162
#define HID_CONSUMER_PAGE_CHANNEL_CENTER 0x163
#define HID_CONSUMER_PAGE_CHANNEL_FRONT 0x164
#define HID_CONSUMER_PAGE_CHANNEL_CENTER_FRONT 0x165
#define HID_CONSUMER_PAGE_CHANNEL_SIDE 0x166
#define HID_CONSUMER_PAGE_CHANNEL_SURROUND 0x167
#define HID_CONSUMER_PAGE_CHANNEL_LOW_FREQUENCY_ENHANCEMENT 0x168
#define HID_CONSUMER_PAGE_CHANNEL_TOP 0x169
#define HID_CONSUMER_PAGE_CHANNEL_UNKNOWN 0x16A
#define HID_CONSUMER_PAGE_RESERVED_12 0x16B ... 0x16F
#define HID_CONSUMER_PAGE_SUB_CHANNEL 0x170
#define HID_CONSUMER_PAGE_SUB_CHANNEL_INCREMENT 0x171
#define HID_CONSUMER_PAGE_SUB_CHANNEL_DECREMENT 0x172
#define HID_CONSUMER_PAGE_ALTERNATE_AUDIO_INCREMENT 0x173
#define HID_CONSUMER_PAGE_ALTERNATE_AUDIO_DECREMENT 0x174
#define HID_CONSUMER_PAGE_RESERVED_13 0x175 ... 0x17F
#define HID_CONSUMER_PAGE_APPLICATION_LAUNCH_BUTTONS 0x180
#define HID_CONSUMER_PAGE_AL_LAUNCH_BUTTON_CONFIGURATION_TOOL 0x181
#define HID_CONSUMER_PAGE_AL_PROGRAMMABLE_BUTTON_CONFIGURATION 0x182
#define HID_CONSUMER_PAGE_AL_CONSUMER_CONTROL_CONFIGURATION 0x183
#define HID_CONSUMER_PAGE_AL_WORD_PROCESSOR 0x184
#define HID_CONSUMER_PAGE_AL_TEXT_EDITOR 0x185
#define HID_CONSUMER_PAGE_AL_SPREADSHEET 0x186
#define HID_CONSUMER_PAGE_AL_GRAPHICS_EDITOR 0x187
#define HID_CONSUMER_PAGE_AL_PRESENTATION_APP 0x188
#define HID_CONSUMER_PAGE_AL_DATABASE_APP 0x189
#define HID_CONSUMER_PAGE_AL_EMAIL_READER 0x18A
#define HID_CONSUMER_PAGE_AL_NEWSREADER 0x18B
#define HID_CONSUMER_PAGE_AL_VOICEMAIL 0x18C
#define HID_CONSUMER_PAGE_AL_CONTACTS_ADDRESS_BOOK 0x18D
#define HID_CONSUMER_PAGE_AL_CALENDAR_SCHEDULE 0x18E
#define HID_CONSUMER_PAGE_AL_TASK_PROJECT_MANAGER 0x18F
#define HID_CONSUMER_PAGE_AL_LOG_JOURNAL_TIMECARD 0x190
#define HID_CONSUMER_PAGE_AL_CHECKBOOK_FINANCE 0x191
#define HID_CONSUMER_PAGE_AL_CALCULATOR 0x192
#define HID_CONSUMER_PAGE_AL_A_V_CAPTURE_PLAYBACK 0x193
#define HID_CONSUMER_PAGE_AL_LOCAL_MACHINE_BROWSER 0x194
#define HID_CONSUMER_PAGE_AL_LAN_WAN_BROWSER 0x195
#define HID_CONSUMER_PAGE_AL_INTERNET_BROWSER 0x196
#define HID_CONSUMER_PAGE_AL_REMOTE_NETWORKING_ISP_CONNECT 0x197
#define HID_CONSUMER_PAGE_AL_NETWORK_CONFERENCE 0x198
#define HID_CONSUMER_PAGE_AL_NETWORK_CHAT 0x199
#define HID_CONSUMER_PAGE_AL_TELEPHONY_DIALER 0x19A
#define HID_CONSUMER_PAGE_AL_LOGON 0x19B
#define HID_CONSUMER_PAGE_AL_LOGOFF 0x19C
#define HID_CONSUMER_PAGE_AL_LOGON_LOGOFF 0x19D
#define HID_CONSUMER_PAGE_AL_TERMINAL_LOCK_SCREENSAVER 0x19E
#define HID_CONSUMER_PAGE_AL_CONTROL_PANEL 0x19F
#define HID_CONSUMER_PAGE_AL_COMMAND_LINE_PROCESSOR_RUN_SEL 0x1A0
#define HID_CONSUMER_PAGE_AL_PROCESS_TASK_MANAGER 0x1A1
#define HID_CONSUMER_PAGE_AL_SELECT_TASK_APPLICATION 0x1A2
#define HID_CONSUMER_PAGE_AL_NEXT_TASK_APPLICATION 0x1A3
#define HID_CONSUMER_PAGE_AL_PREVIOUS_TASK_APPLICATION 0x1A4
#define HID_CONSUMER_PAGE_AL_PREEMPTIVE_HALT_TASK_APPLICATION 0x1A5
#define HID_CONSUMER_PAGE_AL_INTEGRATED_HELP_CENTER 0x1A6
#define HID_CONSUMER_PAGE_AL_DOCUMENTS 0x1A7
#define HID_CONSUMER_PAGE_AL_THESAURUS 0x1A8
#define HID_CONSUMER_PAGE_AL_DICTIONARY 0x1A9
#define HID_CONSUMER_PAGE_AL_DESKTOP 0x1AA
#define HID_CONSUMER_PAGE_AL_SPELL_CHECK 0x1AB
#define HID_CONSUMER_PAGE_AL_GRAMMAR_CHECK 0x1AC
#define HID_CONSUMER_PAGE_AL_WIRELESS_STATUS 0x1AD
#define HID_CONSUMER_PAGE_AL_KEYBOARD_LAYOUT 0x1AE
#define HID_CONSUMER_PAGE_AL_VIRUS_PROTECTION 0x1AF
#define HID_CONSUMER_PAGE_AL_ENCRYPTION 0x1B0
#define HID_CONSUMER_PAGE_AL_SCREEN_SAVER 0x1B1
#define HID_CONSUMER_PAGE_AL_ALARMS 0x1B2
#define HID_CONSUMER_PAGE_AL_CLOCK 0x1B3
#define HID_CONSUMER_PAGE_AL_FILE_BROWSER 0x1B4
#define HID_CONSUMER_PAGE_AL_POWER_STATUS 0x1B5
#define HID_CONSUMER_PAGE_RESERVED_14 0x1B6 ... 0x1FF
#define HID_CONSUMER_PAGE_GENERIC_GUI_APPLICATION_CONTROLS 0x200
#define HID_CONSUMER_PAGE_AC_NEW 0x201
#define HID_CONSUMER_PAGE_AC_OPEN 0x202
#define HID_CONSUMER_PAGE_AC_CLOSE 0x203
#define HID_CONSUMER_PAGE_AC_EXIT 0x204
#define HID_CONSUMER_PAGE_AC_MAXIMIZE 0x205
#define HID_CONSUMER_PAGE_AC_MINIMIZE 0x206
#define HID_CONSUMER_PAGE_AC_SAVE 0x207
#define HID_CONSUMER_PAGE_AC_PRINT 0x208
#define HID_CONSUMER_PAGE_AC_PROPERTIES 0x209
#define HID_CONSUMER_PAGE_RESERVED_15 0x20A ... 0x219
#define HID_CONSUMER_PAGE_AC_UNDO 0x21A
#define HID_CONSUMER_PAGE_AC_COPY 0x21B
#define HID_CONSUMER_PAGE_AC_CUT 0x21C
#define HID_CONSUMER_PAGE_AC_PASTE 0x21D
#define HID_CONSUMER_PAGE_AC_SELECT_ALL 0x21E
#define HID_CONSUMER_PAGE_AC_FIND 0x21F
#define HID_CONSUMER_PAGE_AC_FIND_AND_REPLACE 0x220
#define HID_CONSUMER_PAGE_AC_SEARCH 0x221
#define HID_CONSUMER_PAGE_AC_GO_TO 0x222
#define HID_CONSUMER_PAGE_AC_HOME 0x223
#define HID_CONSUMER_PAGE_AC_BACK 0x224
#define HID_CONSUMER_PAGE_AC_FORWARD 0x225
#define HID_CONSUMER_PAGE_AC_STOP 0x226
#define HID_CONSUMER_PAGE_AC_REFRESH 0x227
#define HID_CONSUMER_PAGE_AC_PREVIOUS_LINK 0x228
#define HID_CONSUMER_PAGE_AC_NEXT_LINK 0x229
#define HID_CONSUMER_PAGE_AC_BOOKMARKS 0x22A
#define HID_CONSUMER_PAGE_AC_HISTORY 0x22B
#define HID_CONSUMER_PAGE_AC_SUBSCRIPTIONS 0x22C
#define HID_CONSUMER_PAGE_AC_ZOOM_IN 0x22D
#define HID_CONSUMER_PAGE_AC_ZOOM_OUT 0x22E
#define HID_CONSUMER_PAGE_AC_ZOOM 0x22F
#define HID_CONSUMER_PAGE_AC_FULL_SCREEN_VIEW 0x230
#define HID_CONSUMER_PAGE_AC_NORMAL_VIEW 0x231
#define HID_CONSUMER_PAGE_AC_VIEW_TOGGLE 0x232
#define HID_CONSUMER_PAGE_AC_SCROLL_UP 0x233
#define HID_CONSUMER_PAGE_AC_SCROLL_DOWN 0x234
#define HID_CONSUMER_PAGE_AC_SCROLL 0x235
#define HID_CONSUMER_PAGE_AC_PAN_LEFT 0x236
#define HID_CONSUMER_PAGE_AC_PAN_RIGHT 0x237
#define HID_CONSUMER_PAGE_AC_PAN 0x238
#define HID_CONSUMER_PAGE_AC_NEW_WINDOW 0x239
#define HID_CONSUMER_PAGE_AC_TILE_HORIZONTALLY 0x23A
#define HID_CONSUMER_PAGE_AC_TILE_VERTICALLY 0x23B
#define HID_CONSUMER_PAGE_AC_FORMAT 0x23C
#define HID_CONSUMER_PAGE_AC_EDIT 0x23D
#define HID_CONSUMER_PAGE_AC_BOLD 0x23E
#define HID_CONSUMER_PAGE_AC_ITALICS 0x23F
#define HID_CONSUMER_PAGE_AC_UNDERLINE 0x240
#define HID_CONSUMER_PAGE_AC_STRIKETHROUGH 0x241
#define HID_CONSUMER_PAGE_AC_SUBSCRIPT 0x242
#define HID_CONSUMER_PAGE_AC_SUPERSCRIPT 0x243
#define HID_CONSUMER_PAGE_AC_ALL_CAPS 0x244
#define HID_CONSUMER_PAGE_AC_ROTATE 0x245
#define HID_CONSUMER_PAGE_AC_RESIZE 0x246
#define HID_CONSUMER_PAGE_AC_FLIP_HORIZONTAL 0x247
#define HID_CONSUMER_PAGE_AC_FLIP_VERTICAL 0x248
#define HID_CONSUMER_PAGE_AC_MIRROR_HORIZONTAL 0x249
#define HID_CONSUMER_PAGE_AC_MIRROR_VERTICAL 0x24A
#define HID_CONSUMER_PAGE_AC_FONT_SELECT 0x24B
#define HID_CONSUMER_PAGE_AC_FONT_COLOR 0x24C
#define HID_CONSUMER_PAGE_AC_FONT_SIZE 0x24D
#define HID_CONSUMER_PAGE_AC_JUSTIFY_LEFT 0x24E
#define HID_CONSUMER_PAGE_AC_JUSTIFY_CENTER_H 0x24F
#define HID_CONSUMER_PAGE_AC_JUSTIFY_RIGHT 0x250
#define HID_CONSUMER_PAGE_AC_JUSTIFY_BLOCK_H 0x251
#define HID_CONSUMER_PAGE_AC_JUSTIFY_TOP 0x252
#define HID_CONSUMER_PAGE_AC_JUSTIFY_CENTER_V 0x253
#define HID_CONSUMER_PAGE_AC_JUSTIFY_BOTTOM 0x254
#define HID_CONSUMER_PAGE_AC_JUSTIFY_BLOCK_V 0x255
#define HID_CONSUMER_PAGE_AC_INDENT_DECREASE 0x256
#define HID_CONSUMER_PAGE_AC_INDENT_INCREASE 0x257
#define HID_CONSUMER_PAGE_AC_NUMBERED_LIST 0x258
#define HID_CONSUMER_PAGE_AC_RESTART_NUMBERING 0x259
#define HID_CONSUMER_PAGE_AC_BULLETED_LIST 0x25A
#define HID_CONSUMER_PAGE_AC_PROMOTE 0x25B
#define HID_CONSUMER_PAGE_AC_DEMOTE 0x25C
#define HID_CONSUMER_PAGE_AC_YES 0x25D
#define HID_CONSUMER_PAGE_AC_NO 0x25E
#define HID_CONSUMER_PAGE_AC_CANCEL 0x25F
#define HID_CONSUMER_PAGE_AC_CATALOG 0x260
#define HID_CONSUMER_PAGE_AC_BUY_CHECKOUT 0x261
#define HID_CONSUMER_PAGE_AC_ADD_TO_CART 0x262
#define HID_CONSUMER_PAGE_AC_EXPAND 0x263
#define HID_CONSUMER_PAGE_AC_EXPAND_ALL 0x264
#define HID_CONSUMER_PAGE_AC_COLLAPSE 0x265
#define HID_CONSUMER_PAGE_AC_COLLAPSE_ALL 0x266
#define HID_CONSUMER_PAGE_AC_PRINT_PREVIEW 0x267
#define HID_CONSUMER_PAGE_AC_PASTE_SPECIAL 0x268
#define HID_CONSUMER_PAGE_AC_INSERT_MODE 0x269
#define HID_CONSUMER_PAGE_AC_DELETE 0x26A
#define HID_CONSUMER_PAGE_AC_LOCK 0x26B
#define HID_CONSUMER_PAGE_AC_UNLOCK 0x26C
#define HID_CONSUMER_PAGE_AC_PROTECT 0x26D
#define HID_CONSUMER_PAGE_AC_UNPROTECT 0x26E
#define HID_CONSUMER_PAGE_AC_ATTACH_COMMENT 0x26F
#define HID_CONSUMER_PAGE_AC_DELETE_COMMENT 0x270
#define HID_CONSUMER_PAGE_AC_VIEW_COMMENT 0x271
#define HID_CONSUMER_PAGE_AC_SELECT_WORD 0x272
#define HID_CONSUMER_PAGE_AC_SELECT_SENTENCE 0x273
#define HID_CONSUMER_PAGE_AC_SELECT_PARAGRAPH 0x274
#define HID_CONSUMER_PAGE_AC_SELECT_COLUMN 0x275
#define HID_CONSUMER_PAGE_AC_SELECT_ROW 0x276
#define HID_CONSUMER_PAGE_AC_SELECT_TABLE 0x277
#define HID_CONSUMER_PAGE_AC_SELECT_OBJECT 0x278
#define HID_CONSUMER_PAGE_AC_REDO_REPEAT 0x279
#define HID_CONSUMER_PAGE_AC_SORT 0x27A
#define HID_CONSUMER_PAGE_AC_SORT_ASCENDING 0x27B
#define HID_CONSUMER_PAGE_AC_SORT_DESCENDING 0x27C
#define HID_CONSUMER_PAGE_AC_FILTER 0x27D
#define HID_CONSUMER_PAGE_AC_SET_CLOCK 0x27E
#define HID_CONSUMER_PAGE_AC_VIEW_CLOCK 0x27F
#define HID_CONSUMER_PAGE_AC_SELECT_TIME_ZONE 0x280
#define HID_CONSUMER_PAGE_AC_EDIT_TIME_ZONES 0x281
#define HID_CONSUMER_PAGE_AC_SET_ALARM 0x282
#define HID_CONSUMER_PAGE_AC_CLEAR_ALARM 0x283
#define HID_CONSUMER_PAGE_AC_SNOOZE_ALARM 0x284
#define HID_CONSUMER_PAGE_AC_RESET_ALARM 0x285
#define HID_CONSUMER_PAGE_AC_SYNCHRONIZE 0x286
#define HID_CONSUMER_PAGE_AC_SEND_RECEIVE 0x287
#define HID_CONSUMER_PAGE_AC_SEND_TO 0x288
#define HID_CONSUMER_PAGE_AC_REPLY 0x289
#define HID_CONSUMER_PAGE_AC_REPLY_ALL 0x28A
#define HID_CONSUMER_PAGE_AC_FORWARD_MSG 0x28B
#define HID_CONSUMER_PAGE_AC_SEND 0x28C
#define HID_CONSUMER_PAGE_AC_ATTACH_FILE 0x28D
#define HID_CONSUMER_PAGE_AC_UPLOAD 0x28E
#define HID_CONSUMER_PAGE_AC_DOWNLOAD_SAVE_TARGET_AS 0x28F
#define HID_CONSUMER_PAGE_AC_SET_BORDERS 0x290
#define HID_CONSUMER_PAGE_AC_INSERT_ROW 0x291
#define HID_CONSUMER_PAGE_AC_INSERT_COLUMN 0x292
#define HID_CONSUMER_PAGE_AC_INSERT_FILE 0x293
#define HID_CONSUMER_PAGE_AC_INSERT_PICTURE 0x294
#define HID_CONSUMER_PAGE_AC_INSERT_OBJECT 0x295
#define HID_CONSUMER_PAGE_AC_INSERT_SYMBOL 0x296
#define HID_CONSUMER_PAGE_AC_SAVE_AND_CLOSE 0x297
#define HID_CONSUMER_PAGE_AC_RENAME 0x298
#define HID_CONSUMER_PAGE_AC_MERGE 0x299
#define HID_CONSUMER_PAGE_AC_SPLIT 0x29A
#define HID_CONSUMER_PAGE_AC_DISRIBUTE_HORIZONTALLY 0x29B
#define HID_CONSUMER_PAGE_AC_DISTRIBUTE_VERTICALLY 0x29C

#define HID_CONSUMER_PAGE_MAX 0x29C
#define HID_CONSUMER_PAGE_CNT (HID_CONSUMER_PAGE_MAX+1)


#endif