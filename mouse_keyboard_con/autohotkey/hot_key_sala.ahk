﻿#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.
!v::

send ^w
Sleep 200
send ^+M
Sleep 500
send ^+v
Sleep 200
send {Enter}
return

!B::
send ^C
Sleep 200
return
