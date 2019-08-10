; Author: Jari Pennanen

hidAcc := DllCall("LoadLibrary", Str, "C:\Source\CandCPP\HIDAccessor\x64\Release\HIDAccessor.dll", "Ptr")
if (ErrorLevel) {
    OutputDebug, Unable to open the HIDAccessor.dll, please check the path
}

hid_get_path_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_get_path", "Ptr")
hid_open_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_open", "Ptr")
hid_write_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_write", "Ptr")
hid_read_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_read", "Ptr")
hid_register_reader_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_register_reader", "Ptr")
hid_close_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_close", "Ptr")
hid_unregister_reader_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_unregister_reader", "Ptr")

HidWriteAndForget(devicePath, writeBufferPtr, writeBufferLen) {
    global hid_open_proc, hid_write_proc, hid_close_proc

    hHid := DllCall(hid_open_proc, Ptr, &devicePath)
    if (!hHid) {
        OutputDebug, HidWriteAndForget Failed to open %devicePath%
    }

    res := DllCall(hid_write_proc, UInt, hHid, Ptr, writeBufferPtr, UInt, writeBufferLen)
    if (!res) {
        OutputDebug, HidWriteAndForget Failed to write %writeBufferLen% bytes to %devicePath%
    }

    ; Close
    res := DllCall(hid_close_proc, UInt, hHid)
    if (!res) {
        OutputDebug, HidWriteAndForget Failed to close
    }
}

; Ergodox specific ------------------------------------------------------------------------------------

ERGODOX_PATH := GetErgodoxPath()
ERGODOX_BUFFER_LEN := 33

MY_HID_CMD := 1
C_TOGGLE_LED := 1
C_SET_COLOR_HSV := 2

MY_HID_REPORT := 2
R_LAYER_CHANGE := 1

GetErgodoxPath() {
    global hid_get_path_proc

    ; HID Device information
    vid := 0xfeed ; Erogdox Ez Vendor ID
    pid := 0x1307 ; Ergodox Ez Product ID
    inumber := 1  ; Interface number 1 (QMK with rules.mk with RAW_ENABLE = yes)

    ; Silly way to create long string
    devicePath := "                                                                                                  "

    ; Retrieve device path
    res := DllCall(hid_get_path_proc, UInt, vid, UInt, pid, Int, inumber, Ptr, &devicePath, Int, StrLen(devicePath))
    if (!res) {
        OutputDebug, Failed to get the path for %vid% %pid% and %inumber%
        return ""
    }
    
    return devicePath
}

WriteErgodox(cmd, bytes*) {
    global MY_HID_CMD, ERGODOX_BUFFER_LEN, ERGODOX_PATH
    if (!ERGODOX_PATH) {
        OutputDebug, Ergodox path is incorrect: %ERGODOX_PATH%
        return
    }
    VarSetCapacity(WriteBuffer, ERGODOX_BUFFER_LEN, 0)
    NumPut(MY_HID_CMD, WriteBuffer, 1, "UChar") ; MY_HID_CMD
    NumPut(cmd, WriteBuffer, 2, "UChar") ; C_SET_COLOR
    for index,param in bytes
        NumPut(param, WriteBuffer, index + 2, "UChar")
    HidWriteAndForget(ERGODOX_PATH, &WriteBuffer, ERGODOX_BUFFER_LEN)
}

; Generic command in my keymap -----------------------------------------------------------------------

SetErgodoxColorHsv(h, s, v) {
    global C_SET_COLOR_HSV
    WriteErgodox(C_SET_COLOR_HSV, h, s, v)
}