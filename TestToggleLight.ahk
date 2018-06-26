; Author: Jari Pennanen
;
; This script is an HID raw interaction example, and requires HIDAccessor.dll
; for interacting with RAW HID devices.
;
; Script sends 0x00, 0x80, 0xff to Ergodox Ez, listens to bytes coming from the
; device.
;
; Requires keyboard firmware (QMK with rules.mk and RAW_ENABLE = yes) that can
; handle RAW hid.

hidAcc := DllCall("LoadLibrary", Str, "C:\Source\CandCPP\HIDAccessor\x64\Release\HIDAccessor.dll", "Ptr")

hid_get_path_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_get_path", "Ptr")
hid_open_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_open", "Ptr")
hid_write_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_write", "Ptr")
; hid_read_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_read", "Ptr")
; hid_register_reader_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_register_reader", "Ptr")
hid_close_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_close", "Ptr")
; hid_unregister_reader_proc := DllCall("GetProcAddress", Ptr, hidAcc, AStr, "hid_unregister_reader", "Ptr")

; HID Device information
vid := 0xfeed ; Erogdox Ez Vendor ID
pid := 0x1307 ; Ergodox Ez Product ID
inumber := 1  ; Interface number 1 (QMK with rules.mk with RAW_ENABLE = yes)

; Silly way to create long string
devicePath := "                                                                                                  "

; Retrieve device path
res := DllCall(hid_get_path_proc, UInt, vid, UInt, pid, Int, inumber, Ptr, &devicePath, Int, StrLen(devicePath))
if (!res) {
    MsgBox, Failed to get the path
}

; listening ---------------------------------------------------------

; writing ---------------------------------------------------------

; Open
hHid := DllCall(hid_open_proc, Ptr, &devicePath)
if (!hHid) {
    MsgBox, Failed to open
}

; Write
VarSetCapacity(WriteBuffer, 33, 0)
NumPut(0x01, WriteBuffer, 1, "UChar") ; MY_HID_CMD
NumPut(0x01, WriteBuffer, 2, "UChar") ; C_TOGGLE_LED
res := DllCall(hid_write_proc, UInt, hHid, Ptr, &WriteBuffer, UInt, 33)
if (!res) {
    MsgBox, Failed to write
}

; Close
res := DllCall(hid_close_proc, UInt, hHid)
if (!res) {
    MsgBox, Failed to close
}

ExitApp, 0